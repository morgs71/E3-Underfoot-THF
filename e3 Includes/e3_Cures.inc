Sub check_Cures
	/declare curePlayer string local
	/declare cureEffect string local	
	/declare cureSpell string local
	/declare cureRange int local 100
	/declare i int local	
	/declare a int local

	
	
/if (${doCures}) {
	/for i 1 to ${cureAllTargets.Size[1]}	
	/varset cureEffect ${cureAllTargets[${i}]}
	/varset cureSpell  ${cures[${i}]}
		
	/if (${Math.Rand[2]}==0) {
      /for a 1 to ${NetBots.Counts}
    } else {
      /for a ${NetBots.Counts} downto 1
	}	
		
			
			/if (${SpawnCount[pc =${NetBots.Client[${a}]}]} && ${NetBots[${NetBots.Client[${a}]}].Buff.Find[${Spell[${cureEffect}].ID}]} ) {
					/call e3_Cast ${NetBots[${NetBots.Client[${a}]}].ID} "${cureSpell}/GiveUpTimer|3"
					/bc Cured ${cureEffect} on ${NetBots.Client[${a}]} with ${cureSpell} 				
			}
		/next a
	/next i
}		
/return

Sub cures_Setup
	/declare doCures bool outer TRUE
	
	/if (${Ini[${Character_Ini},Cures,Cure#1].Length}) {
		/call IniToArray "${Character_Ini},Cures,Cure#" cures
	}

	/if (${Ini[${Character_Ini},CuresAll,CureAll#1].Length}) {
		/call IniToArray "${Character_Ini},CuresAll,CureAll#" cureAllTargets
	}
/return

Sub cures_Background_Events
/return

SUB cures_CharacterSettings
/RETURN