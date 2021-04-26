#ifndef OTHELLOASSIGNMENT_20338321_VALIDMOVE_H
#define OTHELLOASSIGNMENT_20338321_VALIDMOVE_H

#endif //OTHELLOASSIGNMENT_20338321_VALIDMOVE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "initialise.h"
// Importing the required files


// Function prototypes
void flipHorizontal(player InfoPlayer[], board infoBoard[], int playerTurns, int row,int start, int end);
void flipVertical(player InfoPlayer[], board infoBoard[], int playerTurns, int col,int start, int end);
void flipDiagonal(player InfoPlayer[], board infoBoard[], int playerTurns, int col,int start, int end, int side);
bool sideDiffHorizontal(player InfoPlayer[], board infoBoard[], int playerTurns);
bool sideDiffVertical(player InfoPlayer[], board infoBoard[], int playerTurns);
bool sideDiffDiagonal(player InfoPlayer[], board infoBoard[], int playerTurns);
bool emptyCheck(board infoBoard[]);
bool horizontalCheck(player InfoPlayer[], board infoBoard[], int playerTurn);
bool verticalCheck(player InfoPlayer[], board infoBoard[], int playerTurn);
bool diagonalCheck(player InfoPlayer[], board infoBoard[], int playerTurn);
bool availableMoveChecker(player InfoPlayer[], board infoBoard[], int playerTurn);
bool availableMove(player InfoPlayer[], board infoBoard[], int playerTurn);
bool condition(player InfoPlayer[], board infoBoard[], int playerTurn);
bool availablePlayerMoves(player InfoPlayer[], board infoBoard[], int playerTurn);
bool makeMove(player InfoPlayer[], board infoBoard[], int playerTurn);
