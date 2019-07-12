@ECHO OFF
C:
CHOICE /C YN /N /T 5 /D Y /M "Do you wish to launch the WinEQ and MQ2?"
IF ERRORLEVEL 2 GOTO G1
@ECHO Launching MQ2
CD \KilliansMQ2
START C:\KilliansMQ2\MacroQuest2.exe
PING localhost -n 2 -w 1000 >> NULL
@ECHO Launching WinEQ
CD \WinEQ2
START C:\WinEQ2\WinEQ2.exe
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching EQBCS
CD \KilliansMQ2
START C:\KilliansMQ2\eqbcs.exe 
PING localhost -n 5 -w 1000 >> NULL
:G1
CD C:\WinEQ2\
CHOICE /C YN /N /T 5 /D Y /M "Do you wish to launch Group 1?"
IF ERRORLEVEL 2 GOTO G2
@ECHO Launching Muergan
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Muergan"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Irontail
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Irontail"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Pigs
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Pigs"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Splatts
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Splats"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Pooks
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Pooks"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Swiftwynd
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Swiftwynd"
PING localhost -n 10 -w 1000 >> NULL
:G2
CD C:\WinEQ2\
CHOICE /C YN /N /T 5 /D Y /M "Do you wish to launch Group 2?"
IF ERRORLEVEL 2 GOTO G3
@ECHO Launching Alphie
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Alphie"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Majuna
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Majuna"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Fishytooth
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Fishytooth"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Anjeni
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Anjeni"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Kline
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Kline"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Abagaile
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Abagaile"
PING localhost -n 10 -w 1000 >> NULL
:G3
CD C:\WinEQ2\
CHOICE /C YN /N /T 5 /D Y /M "Do you wish to launch Group 3?"
IF ERRORLEVEL 2 GOTO G4
@ECHO Launching Meatsac
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Meatsac"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Leezardman
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Leezardman"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Daisey
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Daisey"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Cultu
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Cultu"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Auroras
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Auroras"
PING localhost -n 10 -w 1000 >> NULL
@ECHO Launching Rory
START C:\WinEQ2\WinEQ2.exe /plugin:WinEQ2-EQ.dll "Rory"
PING localhost -n 10 -w 1000 >> NULL