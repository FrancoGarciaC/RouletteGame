# RouletteGame

### Rules of the game ###

The game consists of a roulette with numbers ranging from 0 to 36 in which 0 is independent and the rest can be either Red or Black. The players are meant to place a simple bet consisting of a type which can be:
* Zero only for 0
* Red for every red number
* Black for every black number
* High for numbers over 18
* Low for numbers lesser or equal to 18
* Even for even numbers
* Uneven for uneven numbers
Players also need to bet a certain amount each round which is determined by a record which in the basic composition is 1 - 2 - 3 - 4 and the amount is determined by a sum of the first and last element of this record. If the record consists of only one number it only takes that one. This amount has to be at least 5 and not greater than 4000 in the basic composition. If it's outside this range, the record has to be reseted to initial record and start again.
The record is changed every round according to the result of the roulette. If the player wins, they add their previous bet to the end of the record, if they lose they have to remove their bet, whether it's the first and last elements of the record or the only element if there is only one.
Every player has their own balance that changes each round according to the result of the roulette. As we are working on the assumption that the players have infinite money, the balance can be negative and the players can play as many rounds as they wish.
On the basic configuration we play 10.000 rounds with 6 players who always bet on the same type with exception of Zero. After all these rounds, the final balance of each player and the total balance of all the players as a group is given.

### Compilation ###
To compile this in linux you just have to type `make` in a terminal targeting the repository folder. And to run it `./main` after the compilation is done. The results are going to be recorded in the "PreviousGame" file.

### Cleaning ###
To clean just run `make clean` on a terminal targeting the repository folder.