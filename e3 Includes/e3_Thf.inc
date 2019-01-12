|----------------------------------------------------------------|
|- THF.inc ( designed to work with e3.mac )	                    -|
|- Written by Muergan									        -|
|----------------------------------------------------------------|
|- Contains various events for The Hidden Forest Server			-|
|----------------------------------------------------------------|

|---------------THF Forest Gate-----------------|

#event thfgate "<#1#> thfgate"
#event thfgate "you tell your party, 'thfgate'"
#event thfgate "#1# tells the group, 'thfgate'"
#event thfgate "#1# tells you, 'thfgate'"
sub Event_thfgate
	 
		/if (${FindItem[=Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Charm of Queen Adrianne"
			} else /if (${FindItem[=Advanced Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Advanced Charm of Queen Adrianne" 
			} else /if (${FindItem[=Magical Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Magical Charm of Queen Adrianne" 
			} else /if (${FindItem[=Advanced Magical Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Advanced Magical Charm of Queen Adrianne" 
			} else /if (${FindItem[=Superior Magical Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Superior Magical Charm of Queen Adrianne" 
			} else /if (${FindItem[=Exceptional Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Exceptional Charm of Queen Adrianne" 
			} else /if (${FindItem[=Exquisite Charm of Queen Adrianne].ID}) {
				/call e3_Cast ${Me.ID} "Exquisite Charm of Queen Adrianne" 
		}
	
/return

|---------------Hidden Vale Gate-----------------|

#event valegate "<#1#> valegate"
#event valegate "you tell your party, 'valegate'"
#event valegate "#1# tells the group, 'valegate'"
#event valegate "#1# tells you, 'valegate'"
sub Event_valegate
	 
		
/if (${FindItem[=Token of the Vale].ID}) {
				/call e3_Cast ${Me.ID} "Token of the Vale"
}
	
/return



|-------------- Gather Mana Items -----------------|

Sub check_GatherMana

/if (${Me.PctMana} < 60 && ${Me.PctHPs} > 35) {
	/if (${Me.Combat} && ${Select[${Me.Class.ShortName},BST,PAL,RNG,SHD]}) {
		/return	
	} else /if (${Me.PctMana} < 20 && ${FindItemCount[Fire Crystal Wristguard]} && ${FindItem[Fire Crystal Wristguard].Timer}==0) {
		/call e3_Cast 0 "Fire Crystal Wristguard" 
	} else /if (${Me.PctMana} < 30 && ${FindItemCount[Powerful Silk Slippers]} && ${FindItem[Powerful Silk Slippers].Timer}==0) {
		/call e3_Cast 0 "Powerful Silk Slippers" 
	} else /if (${Me.PctMana} < 40 && ${FindItemCount[Silver Chains]} && ${FindItem[Silver Chains].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]}) {
		/call e3_Cast 0 "Silver Chains" 
	} else /if (${Me.PctMana} < 40 && ${FindItemCount[Orb of Spirits]} && ${FindItem[Orb of Spirits].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]}) {
		/call e3_Cast 0 "Orb of Spirits" 
	} else /if (${Me.PctMana} <  && ${FindItemCount[Tears of Frozen Mana]} && ${FindItem[Tears of Frozen Mana].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]}) {
		/call e3_Cast 0 "Tears of Frozen Mana" 
	} else /if (${Me.PctMana} <  && ${FindItemCount[Tears of Frozen Spirits]} && ${FindItem[Tears of Frozen Spirits].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]}) {
		/call e3_Cast 0 "Tears of Frozen Spirits" 
	}
}	
		
/Return		
		

		
		
|-- Xeru the Arbiter --|

#event Xeru "<#1#>Xeru deathtouch"

Sub event_Xeru

/target Xeru
/pause 2s
/if (${Target.ID} == 1002841 && ${Target.Distance} <= 15) {	
	/if (${FindItem[=Chains of Reflection].ID} && ${FindItem[=Chains of Reflection].Timer}==0) {
		/call e3_Cast ${Target.ID} "Chains of Reflection"
		}
} else /if (${Target.ID} == 1002922 && ${Target.Distance} <= 15) {
	/if (${FindItem[=Chains of Reflection].ID} && ${FindItem[=Chains of Reflection].Timer}==0) {
		/call e3_Cast ${Target.ID} "Chains of Reflection"
		}		
	}
/return	
	

Sub Thf_Setup
/if (${Debug}) /echo |- Thf_Setup ==>
	
	/call INItoVar "${Character_Ini},THF,Auto-HealBot (On/Off)" autohealbot bool outer	
	
	
/if (${Debug}) /echo <== Thf_Setup -|
/return



Sub Thf_Background_Events


/return


Sub thf_Aliases
/if (${Debug} || ${Debug_Thf}) /echo |- thf_Aliases ==>

	/squelch /alias /thfgate /bc thfgate
	/squelch /alias /valegate /bc valegate
	/squelch /alias /healbot /bc healbot
	/squelch /alias /xeru /bc Xeru deathtouch


/if (${Debug} || ${Debug_Thf}) /echo <== thf_Aliases -|
/return

SUB THF_CharacterSettings
/if (${Debug}) /echo |- THF_CharacterSettings ==>

	
	/call WriteToIni "${Character_Ini},THF,Auto-HealBot (On/Off)"


/if (${Debug}) /echo <== THF_CharacterSettings -|
/RETURN


