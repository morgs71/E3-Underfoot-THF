|----------------------------------------------------------------------------|
|- e3_Classes_Wizard.inc v3.0 ( originally designed to work with e3.mac )	-|
|- Written by Killians of PEQ												-|
|----------------------------------------------------------------------------|
|- Contains Wizard specific functions related to,							-|
|-		Setup and Ini entry information										-|
|-		MainLoop, and AssistLoop hooks										-|
|-		Over-all functionality / flow										-|
|----------------------------------------------------------------------------|



SUB check_Harvest	

	/if (${autoHarvest} && ${Me.PctMana} < 80 && ${Me.PctHPs} > 35 && ${Me.AltAbilityReady[Harvest of Druzzil]})  /call e3_Cast 0 "Harvest of Druzzil"
		
	/if (${autoHarvest} && ${Me.PctMana} < 65 && ${Me.PctHPs} > 35) {
		
			/declare castName string local
			/declare i int local
			
			/for i 1 to ${harvestSpells.Size}
			
				/varset castName ${harvestSpells[${i}].Arg[1,/]}
				/call e3_Cast 0 "${harvestSpells[${i}]}/giveuptimer|${If[${Me.Gem[${castName}]} || ${FindItemCount[=${castName}]},0,80]}

	}
	
/RETURN


|------------------------------------------------------|

Sub WIZ_Setup
/if (${Debug}) /echo |- WIZ_Setup ==>
	
	/declare i int local
	
	/call INItoVar "${Character_Ini},Wizard,Evac Spell" Evac_Spell string outer
	/call INItoVar "${Character_Ini},Wizard,Auto-Harvest (On/Off)" autoHarvest bool outer
	/call IniToArray "${Character_Ini},Wizard,Harvest#" harvestSpells
	
	| Look for a familiar to cast
	/if (${Defined[SelfBuffs]}) {
		/for i 1 to ${SelfBuffs.Size}
			
			
		/next i
	}

/if (${Debug}) /echo <== WIZ_Setup -|
/return



Sub WIZ_Background_Events

/if (${Me.Pet.ID} && ${Me.Pet.CleanName.Find[${Me.CleanName}`s Familiar]} && ${MacroQuest.Server.Equal[HiddenForest]}) /pet get lost
	
/if (${Bool[${Me.AltAbility[Mind Crash]}]} && ${Me.AltAbilityReady[Mind Crash]}) {
     /if (${Assisting} && ${Me.CombatState.Equal[Combat]} && ${Target.Named} && ${Target.Level} >= ${Math.Calc[${Me.Level}+3]} && ${Me.TargetOfTarget.CleanName.Equal[${Me.CleanName}]})  {
     /if (${Me.Casting.ID}) /call interrupt
      /delay 1s !${Me.Casting.ID}
      /echo \say I have aggro on a dangerous target, casting Mind Crash!
      /e3_Cast "Mind Crash"
    }
  }

/return



SUB WIZ_MacroSettings
/if (${Debug}) /echo |- WIZ_MacroSettings ==>

	/call WriteToIni "${advSettings_Ini},WIZ Functions,WIZ Function#1" "check_Burns" 1
	/call WriteToIni "${advSettings_Ini},WIZ Functions,WIZ Function#2" "check_CombatBuffs" 1
	/call WriteToIni "${advSettings_Ini},WIZ Functions,WIZ Function#3" "check_Rain" 1
	/call WriteToIni "${advSettings_Ini},WIZ Functions,WIZ Function#4" "check_Nukes" 1
	/call WriteToIni "${advSettings_Ini},WIZ Functions,WIZ Function#5" "check_Harvest" 1
	/call WriteToIni "${advSettings_Ini},WIZ Functions,WIZ Function#6" "check_Buffs" 1
	/call WriteToIni "${advSettings_Ini},WIZ Functions,WIZ Function#7" "check_GatherMana" 1

/if (${Debug}) /echo <== WIZ_MacroSettings -|
/RETURN



SUB WIZ_CharacterSettings
/if (${Debug}) /echo |- WIZ_CharacterSettings ==>

	/call WriteToIni "${Character_Ini},Wizard,Evac Spell"
	/call WriteToIni "${Character_Ini},Wizard,Auto-Harvest (On/Off)"
	/call WriteToIni "${Character_Ini},Wizard,Harvest#1"

/if (${Debug}) /echo <== WIZ_CharacterSettings -|
/RETURN



Sub WIZ_Aliases
/if (${Debug}) /echo |- WIZ_Aliases ==>

/if (${Debug}) /echo <== WIZ_Aliases -|
/return