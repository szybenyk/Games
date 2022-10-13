This is a simple console game where you fight monsters. 
The goal of the game is to collect as much gold as you can before you die or get to level 20 to win.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    BUILD
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Run Makefile in your console:
``` bash
make
```

Result is in .bin subfolder. 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    RUN the game
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Run the binary from .bin folder in your console:
``` bash
./bin/monster_fight
```

There is also clean up rule:
``` bash
make clean
```


Here are the rules for the game:

The player encounters one randomly generated monster at a time.
For each monster, the player has two choices: (R)un or (F)ight.
If the player decides to Run, they have a 50% chance of escaping.
If the player escapes, they move to the next encounter with no ill effects.
If the player does not escape, the monster gets a free attack, and the player chooses their next action.
If the player chooses to fight, the player attacks first. The monster’s health is reduced by the player’s damage.
If the monster dies, the player takes any gold the monster is carrying. The player also levels up, increasing their level and damage by 1.
If the monster does not die, the monster attacks the player back. The player’s health is reduced by the monster’s damage.
The game ends when the player has died (loss) or reached level 20 (win)
If the player dies, the game should tell the player what level they were and how much gold they had.
If the player wins, the game should tell the player they won, and how much gold they had

