# Game Design Document
This is the beginning of my Game Design Document. 

## Game Overview
This game is a side scrolling game set on a background that looks like lined 
paper. 

###The Player

The player is a [Brain in a Vat](http://www.iet.utm.edu/brainvat/), or
perhaps more accurately, a Brain in a Vat on a rolling cart that can dodge
obstacles.

The player must survive by dodging obstacles and using psychic attacks to 
vanquish intellectual challenges. Points are accumulated only while the 
player is living.  

![Brain in Vat](/graphics/player/brain_in_vat.png)

###Monsters
- Contradiction
    - Contradictions are very robust and will take multiple attacks.
to destroy. Contact with a Contradiction reduces hitpoints.  

	![Contradiction Monster](/graphics/monsters/contradiction.png)

- Sound Arguments
    - Sound Arguments move in clockwise square formations triggered at fixed intervals by a timer. Contact with a player will reduce player health. Will reverse direction if hit by a Contradiction. Can be destroyed by player.  

	![Sound Argument Monster](/graphics/monsters/Sulfuric_Acid_Molecule_VdW.png)

- Anxieties
    - Anxieties move randomly about the map. If they collide with an
Contradiction Monster, they die. Can be destroyed by player. Anxieties
generate Mean Words.  

	![Anxiety Monster](/graphics/monsters/anxiety.png)

- Mean Words
    - Mean Words moves toward player. If Mean Words hits player, player
loses hit points. Player must attack Mean Words mutliple times to defeat.
Mean Words are projectiles launched by Anxieties.  

These words will appear as words, example:
BAKABAKABAKABAKABAKA

- Text will move in streams. Conceptually, I want to show literal attacks 
being uttered at the User's consciousness.  

###Player Abilities

- Psychic Attack
    - By clicking on certain monsters, the player can reduce these monster's
    health and eventually make them disappear. An animation of a rippling
    purple circles will represent this object.  

    ![Psychic Attack](/graphics/attacks/psychic_attack.png)


## The Implementation

###Game Play

- Players use W-A-S-D to control the movement of the avatar. The mouse is 
used to launch psychic attacks.

- Instructions will initially be put on the screen to show how the user 
pause the game. The Start and Quit buttons are located at the top of the 
scren. The Escape key will be used to pause the game. 

- Players can restart the game by pressing the "Start" button again, even 
after the game is already started.

- When players die, a death screen is displayed. Players must click the 
"Start" button to try playing again.

- The game will become progressively more difficult by speeding up and the
 spawning of more monsters.

###Scoring

- For each monster that is destroyed, points are awarded. Scores cannot go down.

###Player Lives

- Players will begin with three lives, which will be stored in a variable 
in the GamePlay class. Players will also have a finite number of hit points.
Once hit points are depleted, the player will lose a life.

- Players die when they run out of lives. They will then have to restart the 
game if they want to try to get a better score.

###User Interface

Players will be prompted for their name when the game starts, after they click
 the "Start Game" button. After they enter their name, there will be a slight 
delay, and game play will launch into the screen shown below. 



Here is an image of the user interface:  

![Game Design Doc](/game_design_doc.jpg)
