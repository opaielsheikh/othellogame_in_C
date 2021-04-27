# othellogame_Assignment_20338321
Othello game assignment made by opai elsheikh student number 20338321

i first implemented two struct, 
The first struct i made is called player which will contain each player name colour disc and their score for the game.
The second struct i made is called the board which will contain the board rows and columns and the flips index for the discs,
I initialised the first struct by asking the two players to enter each of their name and ask the first player what colour the first player
want, than initialise the second player with the other colour.
i set the score to 2 for each player as its the start of the game.

Then i initialised the second struct that will contain the middle board the four squares with the black (B) and white(W) i chose the (B)&(W) design 
because it looks better to the user than W && B.

I than asked each player to chose a move after he input the move in the formate ld where l represent the letters a->h and d represent the digits 1 -> 8
I than have 3 checks which returns true if any one is true as a boolean or else false the first one is horizontal one it checks if the one after it is not the same 
colour and than checks if anyone after is the same colour once their is it returns true and saves the index in the board struct for the horizontal 
than it flips the discs and have the same thing for the other 2 vertical and diagnoal and checks if it is a valid move it returns true.

I done a function that checks if their is a valid move for a particulare player before the player plays if their isn't it passes to the next player
it finishes once their is no move left for both player.

it displays the scores for the winner/draw and the time of the game and the date and it also appends the results to the file with the final board 
