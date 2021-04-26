#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
// importing the required files

// struct
typedef struct{
    char name[50];
    char colour[50];
    int score;
}player;

// struct
typedef struct{
    char boards[20][10];
    int rows;
    int columns;
    int horizontalEnd;
    int rowFlip;
    int verticalEnd;
    int diagonalEnd;
    int diagonalSide;
}board;

// functions prototypes
void initializePlayers(player InfoPlayer[]);
void startBoard(board infoBoard[], player InfoPlayer[]);
void boardPrinter(board info[], player InfoPlayer[]);
void initializeBeg(player InfoPlayer[], board infoBoard[]);
