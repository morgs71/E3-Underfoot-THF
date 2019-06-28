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
	 /doevents stop
		/if (${FindItem[=Charm of Queen Adrianne].ID})  {
			/call e3_Cast ${Me.ID} "Charm of Queen Adrianne"
		} else /if (${FindItem[=Advanced Charm of Queen Adrianne].ID})  {
			/call e3_Cast ${Me.ID} "Advanced Charm of Queen Adrianne" 
		} else /if (${FindItem[=Magical Charm of Queen Adrianne].ID})  {
			/call e3_Cast ${Me.ID} "Magical Charm of Queen Adrianne" 
		} else /if (${FindItem[=Advanced Magical Charm of Queen Adrianne].ID})  {
			/call e3_Cast ${Me.ID} "Advanced Magical Charm of Queen Adrianne" 
		} else /if (${FindItem[=Superior Magical Charm of Queen Adrianne].ID})  {
			/call e3_Cast ${Me.ID} "Superior Magical Charm of Queen Adrianne" 
		} else /if (${FindItem[=Exceptional Charm of Queen Adrianne].ID})  {
			/call e3_Cast ${Me.ID} "Exceptional Charm of Queen Adrianne" 
		} else /if (${FindItem[=Exquisite Charm of Queen Adrianne].ID})  {
			/call e3_Cast ${Me.ID} "Exquisite Charm of Queen Adrianne" 
		}
	
/return

|---------------Hidden Vale Gate-----------------|

#event valegate "<#1#> valegate"
#event valegate "you tell your party, 'valegate'"
#event valegate "#1# tells the group, 'valegate'"
#event valegate "#1# tells you, 'valegate'"
sub Event_valegate
	 
/doevents stop		
/if (${FindItem[=Token of the Vale].ID})  {
	/call e3_Cast ${Me.ID} "Token of the Vale"
}
	
/return



|-------------- Gather Mana Items -----------------|

Sub check_GatherMana

/if (${Me.PctMana} < 60 && ${Me.PctHPs} > 35)  {
	/if (${Me.Combat} && ${Select[${Me.Class.ShortName},BST,PAL,RNG,SHD]})  {
		/return	
	} else /if (${Me.PctMana} < 20 && ${FindItemCount[Fire Crystal Wristguard]} && ${FindItem[Fire Crystal Wristguard].Timer}==0)  {
		/call e3_Cast 0 "Fire Crystal Wristguard" 
	} else /if (${Me.PctMana} < 30 && ${FindItemCount[Powerful Silk Slippers]} && ${FindItem[Powerful Silk Slippers].Timer}==0)  {
		/call e3_Cast 0 "Powerful Silk Slippers" 
	} else /if (${Me.PctMana} < 35 && ${FindItemCount[Silver Chains]} && ${FindItem[Silver Chains].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]})  {
		/call e3_Cast 0 "Silver Chains" 
	} else /if (${Me.PctMana} < 40 && ${FindItemCount[Orb of Spirits]} && ${FindItem[Orb of Spirits].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]})  {
		/call e3_Cast 0 "Orb of Spirits" 
	} else /if (${Me.PctMana} < 50 && ${FindItemCount[Tears of Frozen Mana]} && ${FindItem[Tears of Frozen Mana].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]})  {
		/call e3_Cast 0 "Tears of Frozen Mana" 
	} else /if (${Me.PctMana} < 50 && ${FindItemCount[Tears of Frozen Spirits]} && ${FindItem[Tears of Frozen Spirits].Timer}==0 &&  !${FindItemCount[Powerful Silk Slippers]})  {
		/call e3_Cast 0 "Tears of Frozen Spirits" 
	}
}	
		
/Return		
		

		
		
| -------------------------------------------------------------------------------------------------------|
| -- Call of the Hero: Single Target, Group, All (Netbots)          Written by Muergan                  -|
|========================================================================================================|
| -- Single Target - Tell bot:   cohme		(Pulls sender of tell to bot recieving command)				-|
| -- Group - Tell bot:   cohgroup			(Pulls Group to bot that recieved command)					-|
| -- CoH all Netbots - Tell bot:   cohall	(Pulls all Netbots to bot that recieved command				-|
| -------------------------------------------------------------------------------------------------------|

#event cohme "#1# tells you, 'cohme'"
#event cohgroup "#1# tells you, 'cohgroup'"
#event cohall "#1# tells you, 'cohall'"
		

		
|-- CoH Me Event --|		
		
		
sub Event_cohme(string line, string ChatSender)
	
|-Verify the event
		/call verifyEvent "${ChatSender}" "${line}"
		/if (${Defined[ChatSender]}) /varset ChatSender ${Macro.Return.Arg[1,_]}
		|    |-----------Valid User----------|
		/if (!${Bool[${Macro.Return.Arg[2,_]}]}) {

			/call IniToVar "${genSettings_Ini},Buff Requests,Allow Buff Requests (On/Off)" allow_BuffRequests bool local
			
			| If the user is not valid, check allow_BuffRequests
			/if (${Macro.Return}) {
		
				| If allow_BuffRequests=TRUE, check restricked PCs
				/if (!${Select[${ChatSender},${Ini[${Macro_Ini},Buff Requests,Restricted PCs]}]}) /goto :allowAccess
			}
		} else  { 
		
			:allowAccess
	
			 /if (${Me.Combat})  { 
				/tell ${ChatSender} I'm in Combat please try again in a few !
				/return
			} else /if (!${Me.Combat})  { 
			
				/if (!${SpawnCount[pc ${ChatSender}]})  {
					/tell ${ChatSender} Your not in my Zone.
					/Return
				} else /if (${Me.Class.ShortName.Equal[MAG]})  {
					/tell ${ChatSender} Call of Hero is Incoming...Please Standby.
					/call e3_Cast ${Spawn[${ChatSender}].ID} "Call of the Hero"		
				} else /if (!${Me.Class.ShortName.Equal[MAG]} && ${FindItemCount[Arion, Skull of the Ancient]} && ${FindItem[Arion, Skull of the Ancient].Timer}==0)  {
					/tell ${ChatSender} Call of Hero is Incoming...Please Standby.
					/call e3_Cast ${Spawn[${ChatSender}].ID} "Arion, Skull of the Ancient"
				} else /if (!${Me.Class.ShortName.Equal[MAG]} && ${FindItemCount[Orb of the Crimson Bull]} && ${FindItem[Orb of the Crimson Bull].Timer}==0)  {
					/tell ${ChatSender} Call of Hero is Incoming...Please Standby.
					/call e3_Cast ${Spawn[${ChatSender}].ID} "Orb of the Crimson Bull"
				} else /if (!${Me.Class.ShortName.Equal[MAG]} && !${FindItemCount[Arion, Skull of the Ancient]} && !${FindItemCount[Orb of the Crimson Bull]})  {
					/tell ${ChatSender} Sorry I am not capable of casting Call of the Hero.
				}
			}	
		}
/return
		


		
|-- CoH All Event -- |		
		



sub Event_cohall(string line, string ChatSender)


| -Verify the event
		/call verifyEvent "${ChatSender}" "${line}"
		/if (${Defined[ChatSender]}) /varset ChatSender ${Macro.Return.Arg[1,_]}
		|    |-----------Valid User----------|
		/if (!${Bool[${Macro.Return.Arg[2,_]}]}) {

			/call IniToVar "${genSettings_Ini},Buff Requests,Allow Buff Requests (On/Off)" allow_BuffRequests bool local
			
			| If the user is not valid, check allow_BuffRequests
			/if (${Macro.Return}) {
		
				| If allow_BuffRequests=TRUE, check restricked PCs
				/if (!${Select[${ChatSender},${Ini[${Macro_Ini},Buff Requests,Restricted PCs]}]}) /goto :allowAccess
			}
		} else {
		
			:allowAccess
			
			/if (${Me.Combat}) {
				/tell ${ChatSender} I'm in Combat please try again in a few !	
				/return
				
			} else /if (!${Me.Class.ShortName.Equal[MAG]} && !${FindItemCount[Arion, Skull of the Ancient]} && !${FindItemCount[Orb of the Crimson Bull]}) {
				/tell ${ChatSender} Sorry I am not capable of casting Call of the Hero!	
				/return
			
			} else /if (!${Me.Combat}) { 
			
				/declare i int local
			
				/for i 1 to ${NetBots.Counts}
				
					/if (!${SpawnCount[pc ${NetBots.Client[${i}]}]}) { 
						/docommand ${ChatToggle} (${NetBots.Client[${i}]}) is not in zone!
						
						
					} else /if (${NetBots[${NetBots.Client[${i}]}].Zone} && ${Spawn[pc ${NetBots.Client[${i}]}].Distance} < 20)  {
						/docommand ${ChatToggle} (${NetBots.Client[${i}]}) is already here!
				
					} else /if (${NetBots[${NetBots.Client[${i}]}].Zone} && ${Spawn[pc ${NetBots.Client[${i}]}].Distance} > 20)  {
						
						
						/if (${Me.Class.ShortName.Equal[MAG]}) { 		 
							/docommand ${ChatToggle} Call of Hero is Incoming on (${NetBots.Client[${i}]})!
							/call e3_Cast ${NetBots[${NetBots.Client[${i}]}].ID} "Call of the Hero/giveuptimer|45s"	
							/delay 5s
					
						} else /if ( !${Me.Class.ShortName.Equal[MAG]} && ${FindItemCount[Ino's Lost Trinket]} && ${FindItem[Ino's Lost Trinket].Timer}==0)  {			
							/docommand ${ChatToggle} Call of Hero is Incoming on (${NetBots.Client[${i}]})!
							/call e3_Cast ${NetBots[${NetBots.Client[${i}]}].ID} "Ino's Lost Trinket"	
							/delay 7s
					
						} else /if ( !${Me.Class.ShortName.Equal[MAG]} && ${FindItemCount[Arion, Skull of the Ancient]} && ${FindItem[Arion, Skull of the Ancient].Timer}==0)  {
							/docommand ${ChatToggle} Call of Hero is Incoming on (${NetBots.Client[${i}]})!
							/call e3_Cast ${NetBots[${NetBots.Client[${i}]}].ID} "Arion, Skull of the Ancient"	
							/delay 7s
					
						} else /if ( !${Me.Class.ShortName.Equal[MAG]} && ${FindItemCount[Orb of the Crimson Bull]} && ${FindItem[Orb of the Crimson Bull].Timer}==0)  {
							/docommand ${ChatToggle} Call of Hero is Incoming on (${NetBots.Client[${i}]})!
							/call e3_Cast ${NetBots[${NetBots.Client[${i}]}].ID} "Orb of the Crimson Bull"
							/delay 13s		
						}	

					}
				
				/next i
				
			}
			/docommand ${ChatToggle} I'm done CoHing all Netbots in Zone!
		}
	
/return
		
		
		
| -------------------------------------------------------------------------------------------------------|
| -- Attendance: Bot Roll Call        use: /attendance      Written by Smaht        Edited by: Muergan  -|
| -------------------------------------------------------------------------------------------------------|

#EVENT attendance "<#1#> attendance"

SUB EVENT_attendance(line, ChatSender)

| ---------------- If I made the attendance call, continue, otherwise exit
/if (${Me.CleanName.Equal[${ChatSender}]}) {

	/declare e3xUtilitiesDebug bool local FALSE
	/declare shortDistList string local
	/declare medDistList string local
	/declare feetwetList string local
	/declare drowningList string local
	/declare outOfZoneList string local

	| ---------------- Distances against which to check
	/declare shortDistance int local 50
	/declare medDistance int local 85

	/declare i int local

	| ---------------- Set targetlist to the NetBots.Client list
	/for i 1 to ${NetBots.Counts}

    	| ---------------- For any NetBots.Client, if InZone and (Distance3D > shortDistance) and !Me add to shortDistList
		/if (${NetBots[${NetBots.Client.Arg[${i}]}].InZone} && (${Spawn[${NetBots.Client.Arg[${i}]}].Distance3D} > ${shortDistance}) && !${NetBots.Client.Arg[${i}].Equal[${Me.Name}]}) /varset shortDistList ${shortDistList} ${NetBots.Client.Arg[${i}]}

		| ---------------- For any NetBots.Client, if !InZone add to outOfZoneList
		/if (!${NetBots[${NetBots.Client.Arg[${i}]}].InZone}) /varset outOfZoneList ${outOfZoneList} ${NetBots.Client.Arg[${i}]}

		| ---------------- Debug info
		/if (${Debug_Thf} || ${Debug}) {
			/echo shortdistList : ${NetBots.Client.Arg[${i}]} : ${Spawn[${NetBots.Client.Arg[${i}]}].Distance3D} : InZone=${NetBots[${NetBots.Client.Arg[${i}]}].InZone}
			/echo Current list for shortDistList is: ${shortDistList}
    		/echo outOfZoneList : ${NetBots.Client.Arg[${i}]} : InZone=${NetBots[${NetBots.Client.Arg[${i}]}].InZone}
			/echo Current list for outOfZoneList is: ${outOfZoneList}
		}

        /next i

    | ---------------- Report outOfZoneList
    /if (${outOfZoneList.Length}) /bc [+r+] Out of Zone: ${outOfZoneList}

	| ---------------- If no one in the list, report everyone present and goto underwater checks
	/if (!${shortDistList.Length}) /multiline ; /bc [+r+] Everyone present.;/goto :underwater

	| ---------------- Debug info
	/if (${Debug_Thf} || ${Debug}) /echo shortdistList length is ${Math.Calc[${shortDistList.Count[ ]} + 1]}

	/varset i 1
    /for i 1 to ${Math.Calc[${shortDistList.Count[ ]} + 1]}

		| ---------------- For any shortDistList member, if (Distance3D > medDistance) add to medDistList
		/if (${Spawn[${shortDistList.Arg[${i}]}].Distance3D} > ${medDistance} || !${Spawn[${shortDistList.Arg[${i}]}].LineOfSight}) /varset medDistList ${medDistList} ${shortDistList.Arg[${i}]}

		| ---------------- Debug info
		/if (${Debug_Thf} || ${Debug}) {
			/echo medDistList : ${shortDistList.Arg[${i}]} : ${Spawn[${shortDistList.Arg[${i}]}].Distance3D}
			/echo Current list for medDistList is: ${medDistList}
		}

		/next i

	| ---------------- Report shortDistList members and medDistList members if they exist
	/if (!${medDistList.Length}) /bc The following are close but not present: ${shortDistList}
	/if (${medDistList.Length}) /bc The following are Lost or Stuck: ${medDistList}

	:underwater

	| ---------------- If I am feetwet skip, otherwise figure out who is in the water
	/if (!${Me.FeetWet}) {

		/varset i 1
    	/for i 1 to ${NetBots.Counts}

    		/if (${Spawn[${NetBots.Client.Arg[${i}]}].FeetWet}) /varset feetwetList ${feetwetList} ${NetBots.Client.Arg[${i}]}

    		| ---------------- Debug info
			/if (${Debug_Thf} || ${Debug}) {
				/echo FeetWet: ${NetBots.Client.Arg[${i}]} : ${Spawn[${NetBots.Client.Arg[${i}]}].FeetWet}
				/echo Current list for feetwetList is: ${feetwetList}
			}

			/next i

		/if (${feetwetList.Length}) /bc [+r+] The following are in the drink! ${feetwetList}
	}

}

/return


|-------------- Rallos Zek Event  -----------------|
|  Enables Bots to use Blue Rof of Zek             |
| /ralloson   - Starts Bane Nuking                 |
| /rallosoff  - Stops Bane Nuking (resets on zone) |
|--------------------------------------------------|


#event RallosZekOn "<#1#> ralloszek on"
		
		
sub Event_RallosZekOn

/if (${Select[${Me.Class.ShortName},CLR,DRU,SHM,WIZ,NEC,ENC,MAG]} && ${FindItem[=Blue Rod of Zek].ID})  {
	/varset RallosZek True
	/docommand ${ChatToggle} Rallos Zek will burn! BANE NUKES ENGAGED !!!!
}	
/RETURN	

#event RallosZekOff "<#1#> ralloszek off"
		
		
sub Event_RallosZekOff

/if (${Select[${Me.Class.ShortName},CLR,DRU,SHM,WIZ,NEC,ENC,MAG]} && ${FindItem[=Blue Rod of Zek].ID})  {
	/varset RallosZek False
	/docommand ${ChatToggle} Rallos Zek Bane mode DISABLED!!
}	
/RETURN	
	


|-----------------Macro Shared Events-------By Bazillions & Muergan--------|


Sub IsTank
/varset TankName ${Me.TargetOfTarget.CleanName}
/if (${Select[${Me.Class.ShortName},PAL,SHD,WAR]} && ${Me.TargetOfTarget.CleanName.Equal[${Me.CleanName}]})  {
	/varset IsTank TRUE
} else /if (!${Select[${Me.Class.ShortName},PAL,SHD,WAR]} || !${Me.TargetOfTarget.CleanName.Equal[${Me.CleanName}]})  {
	/varset IsTank FALSE
}
/return
		
		

Sub WaitUntilNotMoving
	:WaitUntilNotMovingLoop
		/delay 4
		/doevents
	/if (${Me.Moving})  {
		/goto :WaitUntilNotMovingLoop
	}
/return


Sub DraekonCalled
	:DraekonCalledLoop
		/delay 4
		/doevents
	/if (${DraekonCall}==1)  {
		/goto :DraekonCalledLoop
	}
/return


Sub DraekonGrass
	:DraekonGrassLoop
		/delay 4
		/doevents
	/if (${DraekonGrass}==1)  {
		/goto :DraekonGrassLoop
	}
/return

Sub ReaperDuck
	:ReaperDuckLoop
		/delay 4
		/doevents
	/if (${ReaperDucking}==1)  {
		/goto :ReaperDuckLoop
	}
/return

Sub ReaperFarAway
	:ReaperFarAwayLoop
		/delay 4
		/doevents
	/if (${ReaperFar}==1)  {
		/goto :ReaperFarAwayLoop
	}
/return

Sub SeravinceStun
	:SeravinceStunLoop
		/delay 4
		/doevents
	/if (${SeravinceStun}==1)  {
		/goto :SeravinceStunLoop
	}
/return


Sub ValikWait
	:ValikWaitLoop
		/delay 4
		/doevents
	/if (${ValikWait}==1)  {
		/goto :ValikWaitLoop
	}
/return
	

|---------------Reaper of Mortality-----------------------Original by Bazillions--Editited for E3 by Muergan------|
|																												  |
|  *Note -  Start all character in Melee Range																	  |
|-----------------------------------------------------------------------------------------------------------------|

#Event ReaperOfMortalityDuck "The Reaper of Mortality levels his eyes with your throat."
#Event ReaperOfMortalityUnduck "You feel the hand of death steal the mortality of those who are too afraid to stand toe-to-toe with their foe."
#Event ReaperOfMortalityMoveClose "Come Foolish Mortals, if you wish to play, then so be it. We shall see how brave you really are! Come to Me!"
#Event ReaperOfMortalityUnmoveClose "You feel the hand of death steal the mortality of those who are too afraid to stand toe-to-toe with their foe."
#Event ReaperOfMortalityMoveFar "Come Foolish Mortals, if you wish to play, then so be it. We shall play a quick game of cat and mouse.  Run fools!"
#Event ReaperOfMortalityUnmoveFar "You feel the hand of death steal the mortality of those who dare approach too closely."



Sub Event_ReaperOfMortalityDuck(string line)
	/call IsTank
	/popup Duck!!!
	/if (${IsTank}) /return
	/varset ReaperDucking 1
	/keypress d
	/call ReaperDuck

/return

Sub Event_ReaperOfMortalityUnduck(string line)
	/call IsTank
	/popup Ducking finished
	/if (${IsTank}) /goto :SkipDuck
	/varset ReaperDucking 0
	/keypress d
	:SkipDuck
	/if (${IsTank})  {
		/call KillReaper
	} else /if (!${IsTank})  {	
		/if (${MainAssist.Equal[${Me.CleanName}]})  {
			/call KillReaper
		}
	}

/return

Sub Event_ReaperOfMortalityMoveClose(string line)
	/call IsTank
	/popup Move close!!!
	/if (${IsTank})  {  
		/rsay Move close to reaper !
		/return
	}
	/call Event_MoveToReaper
/return


Sub Event_ReaperOfMortalityMoveFar(string line)
	/call IsTank
	/popup Run away!!!
	/if (${IsTank})  {
		/rsay Move away from reaper !
		/return
		} 
	/varset ReaperFar 1
	/stick off
	/attack off
	/moveto loc 37 -34
	/call WaitUntilNotMoving
	/if (${Select[${Me.Class.ShortName},MAG,DRU,WIZ,SHM,NEC,ENC]})  {
		/return
		}
	/call ReaperFarAway
/return

Sub Event_ReaperOfMortalityUnmoveFar(string line)
	/call IsTank
	/popup Run away finished
	/if (${IsTank})  {
		/rsay Safe to move !
		/return
	} 
	/varset ReaperFar 0
	/call Event_MoveToReaper
/return


Sub Event_MoveToReaper

 /bc [Event] - Returning to The Reaper of Mortality
	/call IsTank
	/if (${IsTank})  {
		/rsay Safe to move back ${Time}
		/delay 20
		/goto :KillReaper
		}
	:MoveToReaper
	/if (${Spawn[NPC =The Reaper of Mortality].ID} && ${Spawn[NPC =The Reaper of Mortality].Distance} > 12)  {
		/moveto id ${Spawn[NPC =The Reaper of Mortality].ID}
		/delay 5
		}
    /if (${Spawn[NPC =The Reaper of Mortality].ID}!=NULL && ${Spawn[NPC =The Reaper of Mortality].Distance} > 12) /goto :MoveToReaper
	/call WaitUntilNotMoving
	:KillReaper
	/if (${IsTank})  {
		/call KillReaper
	} else /if (!${IsTank})  {	
		/if (${MainAssist.Equal[${Me.CleanName}]})  {
			/call KillReaper
		}
	}

/return


Sub KillReaper

/bc Assist ${TankName} on ${Spawn[NPC =The Reaper of Mortality].ID}
/return
		
	
	
|----------------------------Draekon HoH---------------Originals by Bazillions & Rafe--Editited for E3 by Muergan------|

#Event DraekonMoveToNpc "You hear the voice of #1# calling to you, 'Come to me young one, we must combine our might to destroy him!'"
#Event DraekonGoToGrass "The world begins to spin as Draekon starts to chant an evil spell pulling you towards him."
#Event DraekonGoToMelee "The world begins to spin as Draekon starts to chant a powerful spell pushing you away from him"
#Event DraekonSafeFromGrass "You escape the power of Draekon's spell"
#Event DraekonVoiceEnd "You join your powers with #1#, preventing Draekon from attacking!"


Sub Event_DraekonMoveToNpc(string line, string NpcName)
	/call IsTank
	/if (${IsTank}) /return
	/varset DraekonCall 1
	/stick off
	/attack off
	/target npc ${NpcName}
	/delay 3
	/stick hold
	/call WaitUntilNotMoving
	/call DraekonCalled
/return

Sub Event_DraekonGoToGrass(string line)
	/call IsTank
	/if (${IsTank})  {
		/rsay Everyone move to grass ${Time}
		/return
		}
	/varset DraekonGrass 1
	/stick off
	/attack off
	/moveto loc 335.71 -1582.96
	/call WaitUntilNotMoving
	/if (${Select[${Me.Class.ShortName},MAG,DRU,WIZ,SHM,NEC,ENC]})  {
		/return
		}
	/call DraekonGrass
/return

Sub Event_DraekonGoToMelee(string line)
	/call IsTank
	/if (${IsTank})  {
		/rsay Everyone move to melee range ${Time}
		/return
		}
	/stick off
	/call Event_MoveToDraekon
/return

Sub Event_DraekonSafeFromGrass(string line)
	/varset DraekonGrass 0
	/call Event_MoveToDraekon
/return


Sub Event_DraekonVoiceEnd(string Line, string targetName)

	/varset DraekonCall 0
    /call Event_MoveToDraekon

/return

	
Sub Event_MoveToDraekon

	/call IsTank
	/if (${IsTank})  {
		/rsay Safe to move back ${Time}
		/delay 30
		/goto :MovedtoDraekonNowKill
	}
	:MoveToDraekon
	/if (${Spawn[NPC =Lord Draekon].ID} && ${Spawn[NPC =Lord Draekon].Distance} > 20)  {
		/moveto id ${Spawn[NPC =Lord Draekon].ID}
		/delay 5
	}
    /if (${Spawn[NPC =Lord Draekon].ID}!=NULL && ${Spawn[NPC =Lord Draekon].Distance} > 20) /goto :MoveToDraekon
	/call WaitUntilNotMoving
	:MovedtoDraekonNowKill
	/if (${IsTank})  {
		/rsay Kill Draekon !!!
		/call KillDraekon
	} else /if (!${IsTank})  {	
		/if (${MainAssist.Equal[${Me.CleanName}]})  {
			/rsay Kill Draekon !!!
			/call KillDraekon
		}
	}
/return


Sub KillDraekon
/delay 30
/bc Assist ${TankName} on ${Spawn[NPC =Lord Draekon].ID}
/return


	
	
	
|------------------Seravince---------------Originals by Bazillions--Editited for E3 by Muergan------|
|																									|
|  ***Start all Characters middle of stairs facing away from him***									|
|---------------------------------------------------------------------------------------------------|	
	
	
#Event SeravinceAoeStun "Emperor Seravince body goes rigid as he begins to look around at his attackers!"
#Event SeravinceAoeStunComplete "You avoid the gaze of Seravince!"
#Event SeravinceCreatesAdds "Seravince calls forth his advisors as he shouts, 'You will never be able to control or strike fear into the hearts of those whom follow their true Emperor!'"
#Event SeravinceCallsAddsToAttack "The world begins to spin rapidly as Seravince calls forth his guardians!"
	
	
	
Sub Event_SeravinceAoeStun(string line)
	/call IsTank
	/varset SeravinceStun 1
	/popup AoE Stun
	/if (${Select[${Me.Class.ShortName},MAG,DRU,WIZ,SHM,NEC,ENC,CLR,DRU,SHM]})  {
		/return
	} else /if (${IsTank})  {
		/rsay Turn Away !!!
		}
	/face away
	/call SeravinceStun
/return

Sub Event_SeravinceAoeStunComplete(string line)
	/call IsTank
	/varset SeravinceStun 0
	/popup AoE Stun Complete
	/if (${Select[${Me.Class.ShortName},MAG,DRU,WIZ,SHM,NEC,ENC,CLR,DRU,SHM]})  {
		/return
		}
	/face fast
	/if (${IsTank})  {
		/rsay Safe to Attack !!!
		/call KillSeravince
	} else /if (!${IsTank})  {	
		/if (${MainAssist.Equal[${Me.CleanName}]})  {
			/rsay Safe to Attack !!!
			/call KillSeravince
		}
	}
/return

Sub Event_SeravinceCreatesAdds(string line)
	/call IsTank
	/popup Seravince Created Adds
	/if (${IsTank})  {
		/rsay Seravince Created Adds
		/return
	}
	/if (${Me.Class.ShortName.Equal[ENC]})  {
		/doevents BackOff
		/pet get lost
		/moveto loc 2.02 -1030.79
		/call WaitUntilNotMoving
		/call SeravinceMez
	}
/return

Sub Event_SeravinceCallsAddsToAttack(string line)
	/call IsTank
	/popup Seravince Adds Attacking!!!
	/if (${IsTank})  {
		/rsay Seravince Adds Attacking!!!
		/return
		}
	/return	
		
Sub SeravinceMez	
	/if (${Me.Class.ShortName.Equal[ENC]}) {
		:EnchanterSeravinceLoop
		/target Advisor Tel`Quka
		/call MezmerizeTarget
		/delay 20
		/target Advisor Vulth`Rak
		/call MezmerizeTarget
		/delay 20
		/target Advisor Zser`Vith
		/call MezmerizeTarget
		/delay 20
		/doevents
		/if (${SpawnCount[npc "Emperor Seravince"]} > 0) {
			/goto :EnchanterSeravinceLoop
		}
	}
/return

Sub KillSeravince

/bc Assist ${TankName} on ${Spawn[NPC =Emperor Seravince].ID}
/return



	
	
|--------------------------Vistrinda-------By Muergan--------------------|

#Event VistrindaEggs "Out of the corner of your eye you see Vistrinda's Eggs begin to wobble as a strange voice enters your mind, 'Free me mortal! Only your words can break this shelled prison!'"	
#Event VistrindaAddADead "a corrupted caretaker has been slain by #*#!"
#event VistrindaAddADead "You have slain a corrupted caretaker!"
#Event VistrindaAddA "A corrupted caretaker hits YOU for #*# points of damage."
#Event VistrindaAddBDead "A Corrupted Dragorn has been slain by #*#!"
#event VistrindaAddbDead "You have slain A Corrupted Dragorn!"
#Event VistrindaAddB "A Corrupted Dragorn hits YOU for #*# points of damage."



Sub	Event_VistrindaEggs


/popup EGGS HAVE SPAWNED !!!!
/return


Sub	Event_VistrindaAddA

/if (${VistrindaAddATimer} == 0)  {
	/if (${SpawnCount[npc "a corrupted caretaker"]})  {
		/varset VistrindaAddATimer 1
	}
}
/call IsTank
/if (${IsTank})  {
	/rsay Kill a corrupted caretaker!!!
	/call KillVistrindaAddA
}
/if (!${IsTank})  {	
	/if (${MainAssist.Equal[${Me.CleanName}]})  {
		/rsay Kill a corrupted caretaker!!!
		/call KillVistrindaAddA
	}
}
/return

	
Sub	Event_VistrindaAddADead

/if (${SpawnCount[npc "a corrupted caretaker"]} == 0) {
	/varset VistrindaAddATimer 0
	}
/call IsTank
/if (${IsTank})  {
		/if (${IsTank})  {	
			/call KillVistrinda
		}
	/return
}
/if (!${IsTank})  {
	/if (${MainAssist.Equal[${Me.CleanName}]})  {
		/call KillVistrinda
	}
}
/return

Sub	Event_VistrindaAddB

/if (${VistrindaAddBTimer} == 0)  {
	/if (${SpawnCount[npc "A Corrupted Dragorn"]})  {
		/varset VistrindaAddBTimer 1	
	}
/call IsTank
/if (${IsTank})  {
	/rsay Kill A Corrupted Dragorn!!!
	/call KillVistrindaAddB
}
/if (!${IsTank})  {	
	/if (${MainAssist.Equal[${Me.CleanName}]})  {
		/rsay Kill A Corrupted Dragorn!!!
		/call KillVistrindaAddB
	}
}
/return

	
Sub	Event_VistrindaAddBDead

/if (${SpawnCount[npc "A Corrupted Dragorn"]} == 0) {
	/varset VistrindaAddBTimer 0
	}
/call IsTank
/if (${IsTank})  {
		/if (${IsTank})  {	
			/call KillVistrinda
		}
	/return
}
/if (!${IsTank})  {
	/if (${MainAssist.Equal[${Me.CleanName}]})  {
		/call KillVistrinda
	}
}
/return


	
Sub KillVistrinda
/delay 20
/bc Assist ${TankName} on ${Spawn[NPC =Vistrinda, The Brood Mother].ID}
/return


Sub KillVistrindaAddA
/delay 20
/bc Assist ${TankName} on ${Spawn[NPC =a corrupted caretaker].ID}
/return

Sub KillVistrindaAddB
/delay 20
/bc Assist ${TankName} on ${Spawn[NPC =A Corrupted Dragorn].ID}
/return



|-----------------------Valik the First Creation----------------By Muergan----|
|																    		  |
|      Park all in sight of Valik, hide only clerics behind wall & engage     |
|-----------------------------------------------------------------------------|

#Event ValikBegin "You feel a sense of coming doom and horror as Valik begins to chant a powerful spell!"	
#Event ValikEnd "Valik releases his spell causing those within his sight to be flung down the spire in a state of Vertigo!"	

Sub	Event_ValikBegin
/popup RUN AWAY !!!!
/varset ValikWait 1
/call IsTank
/if (${IsTank} || ${Select[${Me.Class.ShortName},CLR]})  {
	/if (${IsTank})  {
		/rsay Run away you Fools!!!
	}
	/return
	}
/if (!${IsTank})  {	
	/stick off
	/attack off
	/moveto loc 5.71 -60.22
	/call WaitUntilNotMoving
	/moveto loc -8.23 -84.46
	/call WaitUntilNotMoving
	/call ValikWait
}
/RETURN


Sub KillValik
/delay 20
/bc Assist ${TankName} on ${Spawn[NPC =Valik the First Creation].ID}	
/return


Sub	Event_ValikEnd
/popup SAFE TO RETURN !!!
/varset ValikWait 0
/call IsTank
/if (${IsTank} || ${Select[${Me.Class.ShortName},CLR]})  {
		/if (${IsTank})  {			
			/delay 20
			/goto :KillValik
		}
	/return
}
	/moveto loc 5.71 -60.22
	:KillValik
/if (${IsTank})  {	
			/rsay Return to the fight!!!
			/call KillValik		
} else /if (!${IsTank})  {	
	/if (${MainAssist.Equal[${Me.CleanName}]})  {
		/rsay Return to the fight!!!
		/call KillValik
	}
}
/return






	

Sub Thf_Setup
/if (${Debug}) /echo |- Thf_Setup ==>
	
/declare DraekonCall int outer 0
/declare DraekonGrass int outer 0
/declare ReaperDucking int outer 0
/declare ReaperFar int outer 0
/declare SeravinceStun int outer 0
/declare VistrindaAddATimer int outer 0
/declare VistrindaAddBTimer int outer 0
/declare IsTank bool outer FALSE
/declare ValikWait int outer 0	
/declare TankName string outer NULL
	
/if (${Debug}) /echo <== Thf_Setup -|
/return



Sub Thf_Background_Events


/return


Sub thf_Aliases
/if (${Debug} || ${Debug_Thf}) /echo |- thf_Aliases ==>

	/squelch /alias /thfgate /bc thfgate
	/squelch /alias /valegate /bc valegate
	/squelch /alias /xeru /bc Xeru deathtouch
	/squelch /alias /attendance /bc attendance
	/squelch /alias /ralloson /bc ralloszek on
	/squelch /alias /rallosoff /bc ralloszek off
	/squelch /alias /mezit /bc Mez on ${Target.ID}


/if (${Debug} || ${Debug_Thf}) /echo <== thf_Aliases -|
/return

SUB THF_CharacterSettings
/if (${Debug}) /echo |- THF_CharacterSettings ==>

	



/if (${Debug}) /echo <== THF_CharacterSettings -|
/RETURN


