|----------------------------------------------------------------------------|
|- e3_Classes_Warrior.inc v3.0 ( originally designed to work with e3.mac )	-|
|- Written by Killians of PEQ												-|
|----------------------------------------------------------------------------|
|- Contains Warrior specific functions related to,							-|
|-		Setup and Ini entry information										-|
|-		MainLoop, and AssistLoop hooks										-|
|-		Over-all functionality / flow										-|
|----------------------------------------------------------------------------|



|--------------------|
|- attemptProvoke	-|
|--------------------|
SUB check_warProvoke(provokeDisc)
/if (${Debug}) /echo |- check_warProvoke ==>

	/if (!${Defined[MinBellowEndurance]}) {
		/if (${provokeDisc.Equal[Enraged Scowl Rk. III]}) {
			/declare MinBellowEndurance int outer 320
		} else /if (${provokeDisc.Equal[Enraged Scowl Rk. II]}) {
			/declare MinBellowEndurance int outer 335
		} else /if (${provokeDisc.Equal[Enraged Scowl Rk. I]}) {
			/declare MinBellowEndurance int outer 340
		} else /if (${provokeDisc.Equal[Ancient: Chaos Cry]}) {
			/declare MinBellowEndurance int outer 300
		} else /if (${provokeDisc.Equal[Bellow of the Mastruq]}) {
			/declare MinBellowEndurance int outer 275
		} else /if (${provokeDisc.Equal[Incite]}) {
			/declare MinBellowEndurance int outer 250
		} else /if (${provokeDisc.Equal[Berate]}) {
			/declare MinBellowEndurance int outer 200
		} else /if (${provokeDisc.Equal[Bellow]}) {
			/declare MinBellowEndurance int outer 175
		} else /if (${provokeDisc.Equal[Provoke]}) {
			/declare MinBellowEndurance int outer 85
		}
	}
	
	/if (${Me.CombatAbilityReady[${provokeDisc}]}) {
	
		| check endurance
		/if (${Me.Endurance} < ${MinBellowEndurance}) {
			/if (${Debug}) /echo |- attemptProvoke -| I do not have enough endurance to use [${provokeDisc}].
		} else {
	
			/if (${provokeTimer_${Target.ID}} && ${Spawn[${Me.TargetOfTarget}].CleanName.Equal[${Me}]}) {
				/if (${Debug}) /echo |- attemptProvoke -| I still have aggro, and have not met my recast timer for [${provokeDisc}] [${provokeTimer_${Target.ID}}].
			} else {
	
				/call useDisc 0 "${provokeDisc}"
				/call CreateTimer provokeTimer_${Target.ID} 600
			}
		}
	}

/if (${Debug}) /echo <== check_warProvoke -|
/RETURN



Sub WAR_Setup
/if (${Debug}) /echo |- WAR_Setup ==>

	/call IniToVar "${MacroData_Ini},Class Specific Info,Warrior Provoke Disciplines" warriorBellows string outer
	/call IniToVar "${Character_Ini},Warrior,Commanding Voice (On/Off)" CommandVoice bool outer 

/if (${Debug}) /echo <== WAR_Setup -|
/return



Sub WAR_Background_Events

/if (${CommandVoice} && ${Me.Combat} && ${Me.CombatAbilityReady[Commanding Voice]} && !${Me.Song[Commanding Voice].ID})  {

/disc Commanding Voice

}


/return



SUB WAR_MacroSettings
/if (${Debug}) /echo |- WAR_MacroSettings ==>

	| MacroData settings
	/call WriteToIni "${MacroData_Ini},Class Specific Info,Warrior Provoke Disciplines" "Provoke,Bellow,Berate,Incite,Bellow of the Mastruq,Ancient: Chaos Cry,Enraged Scowl Rk. I,Enraged Scowl Rk. II,Enraged Scowl Rk. III" 0
	
	| AdvSettings
	/call WriteToIni "${advSettings_Ini},WAR Functions,WAR Function#1" "check_Burns" 1
	/call WriteToIni "${advSettings_Ini},WAR Functions,WAR Function#2" "check_CombatBuffs" 1
	/call WriteToIni "${advSettings_Ini},WAR Functions,WAR Function#3" "check_Buffs" 1
	
/if (${Debug}) /echo <== WAR_MacroSettings -|
/RETURN



SUB WAR_CharacterSettings
/if (${Debug}) /echo |- WAR_CharacterSettings ==>

/call WriteToIni "${Character_Ini},${Me.Class},Commanding Voice (On/Off)" On

/if (${Debug}) /echo <== WAR_CharacterSettings -|
/RETURN



Sub WAR_Aliases
/if (${Debug}) /echo |- WAR_Aliases ==>

/if (${Debug}) /echo <== WAR_Aliases -|
/return


