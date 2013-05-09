# Game Design Document

## Game Overview
This game is a side scrolling action game. Players control an avatar with the keyboard and attack using the keyboard. 

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
    - Sound Arguments move in clockwise square formations triggered at fixed intervals by a timer. Contact with a player will reduce player health. Can be destroyed by player.  

	![Sound Argument Monster](/graphics/monsters/Sulfuric_Acid_Molecule_VdW.png)

- Anxieties
    - Anxieties move randomly about the map. If they collide with an
Contradiction Monster, they die. Can be destroyed by player. Anxieties
generate Mean Words.  

	![Anxiety Monster](/graphics/monsters/anxiety01.png)

- Mean Words
    - Mean Words moves toward player. If Mean Words hits player, player
loses hit points. Player must attack Mean Words mutliple times to defeat.
Mean Words are projectiles launched by Anxieties.  

	![Mean Words Monster](/graphics/monsters/meanwords.png)

- Text will move horizontally. Conceptually, I want to show literal attacks 
being uttered at the User's consciousness.  

- Depression
	- Depression fulfills the PA6 Requirement of having a player-aware monster. 
This monster will follow and hover over the player doing damage until it is 
destroyed.  

	![Depression Monster](/graphics/monsters/depression.png)

- Despair
	- Despair fulfills the PA6 Requirement of having a player-aware monster. 
This monster will rapidly approach the player's location and self-destruct 
doing damage upon contact with the player.  

	![Despair Monster](/graphics/monsters/despair01.png)

###Player Abilities

- Psychic Attack
    - By clicking on certain monsters, the player can reduce these monster's
    health and eventually make them disappear. An animation of a wavering
    purple energy ball will represent this object.  

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

###High Scores

- This functionality has been added to fulfill the requirement for PA6. To 
access High Scores, simply click the "High Scores" button at any time. 
- New scores will be stored in the text file scores.txt when a player dies. 
Whenever a new entry is made via the player dying, this document will be 
updated. 
- High Scores can be accessed at any time.

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

Player Sign-In:

![Player Sign In](/screenshots/name_entry.png)

Opening Screen:

![Opening Screen](/screenshots/opening_screen.png)

Game Play:

![Game Play](/screenshots/game_play.png)

Game Over:

![Game Over](/screenshots/game_over.png)

### Licensing Information

"Lapse into Solipsism" is a 2D action game.
Copyright (C) 2013 Alan Wong

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

The author of this software can be contacted via e-mail at captainalan@gmail.com.

A copy of this License should be found under the LICENSE directory as "license.txt".


