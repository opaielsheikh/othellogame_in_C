#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "othello.h"

int main(void)
{
    struct tm* ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt);
    printf("\n\t\t\t testing: %s", asctime(ptr));
    player *Players = malloc(sizeof(char));
    board *Board = malloc(sizeof(char));
    initializeBeg(Players, Board);
    playGame(Players, Board);
    return 0;
}

