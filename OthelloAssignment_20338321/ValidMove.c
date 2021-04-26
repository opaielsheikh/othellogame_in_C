#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ValidMove.h"


void flipHorizontal(player InfoPlayer[], board infoBoard[], int playerTurns, int row,int start, int end)
{
    int i = row;
    if(start < end){
        for(int j=start; j<end;j++){
            strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
        }
    }
    else{
        for(int j=start; j>end;j--){
            strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
        }
    }
}

void flipVertical(player InfoPlayer[], board infoBoard[], int playerTurns, int col,int start, int end)
{
    int j = col;
    if(start < end){
        for(int i=start; i<end;i++){
            strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
        }
    }
    else{
        for(int i=start; i>end;i--){
            strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
        }
    }

}

void flipDiagonal(player InfoPlayer[], board infoBoard[], int playerTurns, int col,int start, int end, int side)
{
    int j = col;
    if(start < end) {
        if(side == 1) {
            for (int i = start; i < end; i++) {
                strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
                j++;
            }
        }
        else if(side == 2){
            for (int i = start; i < end; i++) {
                strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
                j--;
            }
        }
    }
    else if(start > end){
        if(side == 3) {
            for (int i = start; i > end; i--) {
                strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
                j--;
            }
        }
        else if(side == 4){
            for (int i = start; i > end; i--) {
                strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
                j++;
            }
        }
    }
}

bool sideDiffHorizontal(player InfoPlayer[], board infoBoard[], int playerTurns)
{
    if(strcmp(infoBoard[infoBoard->rows - 1].boards[infoBoard->columns+1], InfoPlayer[playerTurns].colour) == 0){
        return false;
    }
    else if(strcmp(infoBoard[infoBoard->rows - 1].boards[infoBoard->columns-1], InfoPlayer[playerTurns].colour) == 0){
        return false;
    }
    else{
        return true;
    }
}

bool sideDiffVertical(player InfoPlayer[], board infoBoard[], int playerTurns)
{
    if(strcmp(infoBoard[infoBoard->rows].boards[infoBoard->columns], InfoPlayer[playerTurns].colour) == 0){
        return false;
    }
    else if(strcmp(infoBoard[infoBoard->rows - 2].boards[infoBoard->columns], InfoPlayer[playerTurns].colour) == 0){
        return false;
    }
    else{
        return true;
    }
}

bool sideDiffDiagonal(player InfoPlayer[], board infoBoard[], int playerTurns)
{
    if(strcmp(infoBoard[infoBoard->rows].boards[infoBoard->columns+1], InfoPlayer[playerTurns].colour) == 0){
        return false;
    }
    else if(strcmp(infoBoard[infoBoard->rows - 2].boards[infoBoard->columns-1], InfoPlayer[playerTurns].colour) == 0){
        return false;
    }
    else if(strcmp(infoBoard[infoBoard->rows].boards[infoBoard->columns-1], InfoPlayer[playerTurns].colour) == 0){
        return false;
    }
    else if(strcmp(infoBoard[infoBoard->rows - 2].boards[infoBoard->columns+1], InfoPlayer[playerTurns].colour) == 0){
        return false;
    }
    else{
        return true;
    }
}

bool emptyCheck(board infoBoard[])
{
    if(strcmp(infoBoard[infoBoard->rows - 1].boards[infoBoard->columns], "   ") == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

bool horizontalCheck(player InfoPlayer[], board infoBoard[], int playerTurn)
{
    bool checker = false;
    int i= infoBoard->rows - 1, end=0;

    if(sideDiffHorizontal(InfoPlayer, infoBoard, playerTurn)) {
        for (int j = infoBoard->columns + 1; j < 8; j++) {
            if(strcmp(infoBoard[i].boards[j], "   ") == 0){
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[i].boards[j]) == 0){
                checker = true;
                end = j;
                break;
            }
        }
        for (int j = infoBoard->columns - 1; j > 0; j--) {
            if(strcmp(infoBoard[i].boards[j], "   ") == 0){
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[i].boards[j]) == 0) {
                checker = true;
                end = j;
                break;
            }
        }
    }
    infoBoard->horizontalEnd = end;
    infoBoard->rowFlip = i;
    return checker;
}

bool verticalCheck(player InfoPlayer[], board infoBoard[], int playerTurn)
{
    bool checker = false;
    int i= infoBoard->columns, end=0;

    if(sideDiffVertical(InfoPlayer, infoBoard, playerTurn)){
        for (int j = infoBoard->rows; j < 8; j++) {
            if(strcmp(infoBoard[j].boards[i], "   ") == 0){
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[i]) == 0){
                checker = true;
                end = j;
                break;
            }
        }
        for (int j = infoBoard->rows - 2; j > 0; j--) {
            if(strcmp(infoBoard[j].boards[i], "   ") == 0){
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[i]) == 0) {
                checker = true;
                end = j;
                break;
            }
        }
    }

    infoBoard->verticalEnd = end;
    return checker;
}

bool diagonalCheck(player InfoPlayer[], board infoBoard[], int playerTurn)
{
    bool checker = false;
    int i = infoBoard->columns+1, end=0, index2Forward = infoBoard->columns-1, index2Backwords = infoBoard->columns+1, side=0;

    if(sideDiffDiagonal(InfoPlayer, infoBoard, playerTurn)){
        for (int j = infoBoard->rows; j < 8; j++) {
            if(strcmp(infoBoard[j].boards[i], "   ") == 0 && strcmp(infoBoard[j].boards[index2Forward], "   ") == 0){
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[i]) == 0){
                checker = true;
                end = j;
                side = 1;
                break;
            }
            if(strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[index2Forward]) == 0){
                checker = true;
                end = j;
                side = 2;
                break;
            }
            i++;
            index2Forward--;
        }
        i = infoBoard->columns-1;
        for (int j = infoBoard->rows - 2; j > 0; j--) {
            if(strcmp(infoBoard[j].boards[i], "   ") == 0 && strcmp(infoBoard[j].boards[index2Backwords], "   ") == 0){
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[i]) == 0){
                checker = true;
                end = j;
                side = 3;
                break;
            }
            if(strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[index2Backwords]) == 0){
                checker = true;
                end = j;
                side = 4;
                break;
            }
            i--;
            index2Backwords++;
        }
    }

    infoBoard->diagonalEnd = end;
    infoBoard->diagonalSide = side;

    return checker;
}

bool availableMoveChecker(player InfoPlayer[], board infoBoard[], int playerTurn)
{
    bool check = false;
    if(emptyCheck(infoBoard)){
        if(horizontalCheck(InfoPlayer, infoBoard, playerTurn) && verticalCheck(InfoPlayer, infoBoard, playerTurn) && diagonalCheck(InfoPlayer, infoBoard, playerTurn)){
            check = true;
        }
        else if(horizontalCheck(InfoPlayer, infoBoard, playerTurn) && verticalCheck(InfoPlayer, infoBoard, playerTurn)){
            check = true;
        }
        else if(horizontalCheck(InfoPlayer, infoBoard, playerTurn) && diagonalCheck(InfoPlayer, infoBoard, playerTurn)){
            check = true;
        }
        else if(verticalCheck(InfoPlayer, infoBoard, playerTurn) && diagonalCheck(InfoPlayer, infoBoard, playerTurn)){
            check = true;
        }
        else if(horizontalCheck(InfoPlayer, infoBoard, playerTurn) || verticalCheck(InfoPlayer, infoBoard, playerTurn) || diagonalCheck(InfoPlayer, infoBoard, playerTurn))
        {
            check = true;
        }
    }
    else{
        return false;
    }
    return check;
}

bool availableMove(player InfoPlayer[], board infoBoard[], int playerTurn)
{
    bool check = false;
    if(emptyCheck(infoBoard)){
        if(horizontalCheck(InfoPlayer, infoBoard, playerTurn) && verticalCheck(InfoPlayer, infoBoard, playerTurn) && diagonalCheck(InfoPlayer, infoBoard, playerTurn)){
            flipHorizontal(InfoPlayer, infoBoard, playerTurn, infoBoard->rowFlip, infoBoard->columns, infoBoard->horizontalEnd);
            flipVertical(InfoPlayer, infoBoard, playerTurn, infoBoard->columns, infoBoard->rows - 1, infoBoard->verticalEnd);
            flipDiagonal(InfoPlayer, infoBoard, playerTurn, infoBoard->columns, infoBoard->rows - 1, infoBoard->diagonalEnd, infoBoard->diagonalSide);
            check = true;
        }
        else if(horizontalCheck(InfoPlayer, infoBoard, playerTurn) && verticalCheck(InfoPlayer, infoBoard, playerTurn)){
            flipHorizontal(InfoPlayer, infoBoard, playerTurn, infoBoard->rowFlip, infoBoard->columns, infoBoard->horizontalEnd);
            flipVertical(InfoPlayer, infoBoard, playerTurn, infoBoard->columns, infoBoard->rows - 1, infoBoard->verticalEnd);
            check = true;
        }
        else if(horizontalCheck(InfoPlayer, infoBoard, playerTurn) && diagonalCheck(InfoPlayer, infoBoard, playerTurn)){
            flipHorizontal(InfoPlayer, infoBoard, playerTurn, infoBoard->rowFlip, infoBoard->columns, infoBoard->horizontalEnd);
            flipDiagonal(InfoPlayer, infoBoard, playerTurn, infoBoard->columns, infoBoard->rows - 1, infoBoard->diagonalEnd, infoBoard->diagonalSide);
            check = true;
        }
        else if(verticalCheck(InfoPlayer, infoBoard, playerTurn) && diagonalCheck(InfoPlayer, infoBoard, playerTurn)){
            flipVertical(InfoPlayer, infoBoard, playerTurn, infoBoard->columns, infoBoard->rows - 1, infoBoard->verticalEnd);
            flipDiagonal(InfoPlayer, infoBoard, playerTurn, infoBoard->columns, infoBoard->rows - 1, infoBoard->diagonalEnd, infoBoard->diagonalSide);
            check = true;
        }
        else if(horizontalCheck(InfoPlayer, infoBoard, playerTurn) || verticalCheck(InfoPlayer, infoBoard, playerTurn) || diagonalCheck(InfoPlayer, infoBoard, playerTurn))
        {
            if(horizontalCheck(InfoPlayer, infoBoard, playerTurn)){
                flipHorizontal(InfoPlayer, infoBoard, playerTurn, infoBoard->rowFlip, infoBoard->columns, infoBoard->horizontalEnd);
            }
            else if(verticalCheck(InfoPlayer, infoBoard, playerTurn)){
                flipVertical(InfoPlayer, infoBoard, playerTurn, infoBoard->columns, infoBoard->rows - 1, infoBoard->verticalEnd);
            }
            else{
                flipDiagonal(InfoPlayer, infoBoard, playerTurn, infoBoard->columns, infoBoard->rows - 1, infoBoard->diagonalEnd, infoBoard->diagonalSide);
            }
            check = true;
        }
    }
    else{
        return false;
    }
    return check;
}

bool condition(player InfoPlayer[], board infoBoard[], int playerTurn)
{
    return availableMove(InfoPlayer, infoBoard, playerTurn);
}

bool availablePlayerMoves(player InfoPlayer[], board infoBoard[], int playerTurn)
{
    bool check = false;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            infoBoard->rows = i;
            infoBoard->columns = j;
            if(availableMoveChecker(InfoPlayer, infoBoard, playerTurn)){
                check = true;
                break;
            }
        }
    }

    return check;
}

bool makeMove(player InfoPlayer[], board infoBoard[], int playerTurn)
{
    bool checker = false;

    if(condition(InfoPlayer, infoBoard, playerTurn)){
        strcpy(infoBoard[infoBoard->rows - 1].boards[infoBoard->columns], InfoPlayer[playerTurn].colour);
        checker = true;
    }else{
        printf("\nInvalid Move! Pls try again.\n");
    }

    return checker;
}
