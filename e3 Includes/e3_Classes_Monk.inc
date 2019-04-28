|------------------------------------------------------------------------|
|- e3_Classes_Monk.inc v3.0 ( originally designed to work with e3.mac )	-|
|- Written by Killians of PEQ											-|
|------------------------------------------------------------------------|
|- Contains Monk specific functions related to,							-|
|-		Setup and Ini entry information									-|
|-		MainLoop, and AssistLoop hooks									-|
|-		Over-all functionality / flow									-|
|------------------------------------------------------------------------|



Sub MNK_Setup
/if (${Debug}) /echo |- MNK_Setup ==>
	
/call IniToVar "${Character_Ini},Monk,Combat Song (On/Off)" MonkSong bool outer	
/call IniToVar "${Character_Ini},Monk,Combat Song Discipline" MonkSongDisc string outer
	
/if (${Debug}) /echo <== MNK_Setup -|
/return



Sub MNK_Background_Events

/if (${MonkSong} && ${Me.Combat} && ${Me.CombatAbilityReady[${MonkSongDisc}]} && !${Me.Song[${MonkSongDisc}].ID}) {

/disc ${MonkSongDisc}
}



/return



SUB MNK_MacroSettings
/if (${Debug}) /echo |- MNK_MacroSettings ==>

	| Adv Settings
	/call WriteToIni "${advSettings_Ini},MNK Functions,MNK Function#1" "check_Burns" 1
	/call WriteToIni "${advSettings_Ini},MNK Functions,MNK Function#2" "check_CombatBuffs" 1
	/call WriteToIni "${advSettings_Ini},MNK Functions,MNK Function#3" "check_Buffs" 1

/if (${Debug}) /echo <== MNK_MacroSettings -|
/RETURN



SUB MNK_CharacterSettings
/if (${Debug}) /echo |- MNK_CharacterSettings ==>

/call WriteToIni "${Character_Ini},${Me.Class},Combat Song (On/Off)" On
/call WriteToIni "${Character_Ini},${Me.Class},Combat Song Discipline"

/if (${Debug}) /echo <== MNK_CharacterSettings -|
/RETURN



Sub MNK_Aliases
/if (${Debug}) /echo |- MNK_Aliases ==>

/if (${Debug}) /echo <== MNK_Aliases -|
/return