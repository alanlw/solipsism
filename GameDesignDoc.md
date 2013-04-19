# Game Design Document
This is the beginning of my Game Design Document. 

## Game Overview
This game is a side scrolling game set on a background that looks like lined paper. The player is a small hand-drawn-looking character that can move or attack to overcome various obstacles.

###Monsters
- Pile of Dung
    - You cannot touch pile of dung. If you do, you will instantly die. 
Dung stays still and stinks. Piles of dung will momentarily emit stink. If you get collid with the stink your life will be reduced. Cannot be destroyed by player.

- Automatic Vacuum Cleaner
    - These small machines move in straight lines and turn at right angles 
randomly triggered at fixed intervals by a timer. Contact with a player will
reduce player health, and vacuum cleaner will reverse direction as if it hit
a wall. Can be destroyed by player.

- Cute Dust Ball
    - Cute dust balls move randomly about the map. If they collide with an
automatic vacuum cleaner, they die. Can be destroyed by player.

- Eraser-Hand
    - Eraser-Hand moves up and down the screen. If player contacts Eraser-Hand,
player dies instantly.

- Aggressive Kid
    - Aggressive kid moves toward player. If aggressive kid hits player, player
loses hit points. Player must attack agressive kid mutliple times to defeat 
him. If player clears a stage without attack Aggressive Kid, then he gets a 
score bonus for being non-violent. 


## The Implementation
