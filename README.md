# MiniAntiCheat
A project that represents a mini simple Anti-Cheat. There is a user mode app (representing a game), and a Driver (the Anti-Cheat). The Anti-Cheat scans for a blacklisted app (in this case Notepad.exe):
- If the game is opened, you can't open Notepad
- If the game is closed, you can
- If Notepad is opened, you can't open the game

## MiniAntiCheat.cpp
This is the Driver

## Game.cpp
This is the Game

## MiniAntiCheatCommon.h
A header file that has data used by both the driver and the game
