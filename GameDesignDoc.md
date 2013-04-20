# Game Design Document
This is the beginning of my Game Design Document. 

## Game Overview
This game is a side scrolling game set on a background that looks like lined 
paper. 

The player is a [Brain in a Vat](http://www.iet.utm.edu/brainvat/), or
perhaps more accurately, a Brain in a Vat on a rolling cart that can dodge
obstacles.

The player must survive by dodging obstacles and using psychic attacks to 
vanquish intellectual challenges.

###Monsters
- Contradiction (Mujun)
    - You cannot touch or defeat a contradiction.
	![Contradiction Monster](/graphics/monsters/contradiction.png)

- Sound Arguments
    - Sound Arguments move in straight lines and turn at right angles 
randomly triggered at fixed intervals by a timer. Contact with a player will
reduce player health, and vacuum cleaner will reverse direction as if it hit
a wall. Can be destroyed by player.
	![Sound Argument Monster](/graphics/monsters/Sulfuric_Acid_Molecule_VdW.png)

- Anxieties
    - Anxieties move randomly about the map. If they collide with an
automatic vacuum cleaner, they die. Can be destroyed by player. Anxieties
generate Mean Words.
	![Anxiety Monster](/graphics/monsters/anxiety.png)

- Mean Words
    - Mean Words moves toward player. If Mean Words hits player, player
loses hit points. Player must attack agressive kid mutliple times to defeat 
Mean Words.

These words will appear as words, example:
BAKABAKABAKABAKABAKA

###Player Abilities

- Psychic Attack
    - By clicking on certain monsters, the player can reduce these monster's
    health and eventually make them disappear. An animation of a rippling
    purple circles will represent this object.
    ![Psychic Attack](/graphics/attacks/psychic_attack.png)


## The Implementation
