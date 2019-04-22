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
							/call e3_Cast ${NetBots[${NetBots.Client[${i}]}].ID} "Call of the Hero"	
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
	
		

|-----------------------------------------------------Reaper of Mortality-----------------------Original by Bazillions--Editited for E3 by Muergan------|

#Event ReaperOfMortalityDuck "The Reaper of Mortality levels his eyes with your throat."
#Event ReaperOfMortalityUnduck "You feel the hand of death steal the mortality of those who are too afraid to stand toe-to-toe with their foe."
#Event ReaperOfMortalityMoveClose "Come Foolish Mortals, if you wish to play, then so be it. We shall see how brave you really are! Come to Me!"
#Event ReaperOfMortalityUnmoveClose "You feel the hand of death steal the mortality of those who are too afraid to stand toe-to-toe with their foe."
#Event ReaperOfMortalityMoveFar "Come Foolish Mortals, if you wish to play, then so be it. We shall play a quick game of cat and mouse.  Run fools!"
#Event ReaperOfMortalityUnmoveFar "You feel the hand of death steal the mortality of those who dare approach too closely."



Sub Event_ReaperOfMortalityDuck(string line)
	/popup Duck!!!
	/if (${IsTank}) /return
	/keypress d

/return

Sub Event_ReaperOfMortalityUnduck(string line)
	/popup Ducking finished
	/if (${IsTank}) /return
	/keypress d
	/doevents Assist

/return

Sub Event_ReaperOfMortalityMoveClose(string line)
	/popup Move close!!!
	/if (${IsTank})  {  
		/rsay Move close to reaper !
		/return
	}
	/squelch /stick moveback snaproll 15 uw
	/delay 10 !${Me.Moving} || ${Target.Distance} < 15
	/squelch /stick hold moveback behind ${AssistStickDistance} uw	
	/delay 10 ${Me.Moving}
/return

Sub Event_ReaperOfMortalityUnmoveClose(string line)
	/popup Move close finished 
	/if (${IsTank})  {
		/rsay Safe to move away !
		/return
	}
	/unstick
	/doevents Assist

/return

Sub Event_ReaperOfMortalityMoveFar(string line)
	/popup Run away!!!
	/if (${IsTank})  {
		/rsay Move away from reaper !
		/return
	} 
	/doevents Backoff
	/moveto loc 37 -34
	/if (${Select[${Me.Class.ShortName},BST,PAL,SHD,ROG,MNK,WAR,RNG,BRD,BER]})  {
		/return
	}
	/doevents Assist
	
	
/return

Sub Event_ReaperOfMortalityUnmoveFar(string line)
	/popup Run away finished
	
	/if (${IsTank})  {
		/rsay Safe to move !
		/return
	} 
	/doevents Assist

/return
		
	
	
	
	
	
	
	
	
	
	

Sub Thf_Setup
/if (${Debug}) /echo |- Thf_Setup ==>
	

	
	
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

/if (${Debug} || ${Debug_Thf}) /echo <== thf_Aliases -|
/return

SUB THF_CharacterSettings
/if (${Debug}) /echo |- THF_CharacterSettings ==>

	



/if (${Debug}) /echo <== THF_CharacterSettings -|
/RETURN


