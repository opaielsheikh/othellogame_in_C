#ifndef OTHELLOASSIGNMENT_20338321_OTHELLO_H
#define OTHELLOASSIGNMENT_20338321_OTHELLO_H

#endif //OTHELLOASSIGNMENT_20338321_OTHELLO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "ValidMove.h"

int playerTurn(int currentTurn);
int column(char col);
void playerScores(board infoBoard[], player InfoPlayer[]);
void winnerResultDisplayPrinter(board infoBoard[], player InfoPlayer[], time_t timetaken);
void finalBoardAppendToFile(board info[], player InfoPlayer[], FILE *fptr);
void playGame(player InfoPlayer[], board infoBoard[]);
