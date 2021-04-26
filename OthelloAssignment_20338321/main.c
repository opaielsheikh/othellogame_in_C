#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "othello.h"
// importing the required libraries 

int main(void)
{
    // declaring variables 
    struct tm* ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt);
    
    // display the time and calling the function for the othello game
    printf("\n\t\t\t %s", asctime(ptr));
    player *Players = malloc(sizeof(char));
    board *Board = malloc(sizeof(char));
    initializeBeg(Players, Board);
    playGame(Players, Board);
    return 0;
}
