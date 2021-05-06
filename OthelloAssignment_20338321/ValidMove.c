#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ValidMove.h"
// Importing the required files


void flipHorizontal(player InfoPlayer[], board infoBoard[], int playerTurns, int row,int start, int end)
{ // Function to flip the disc in horizontal to the other color
    int i = row; // declaring variables

    if(start < end){ // if the beginning index is less than last it flips index as it goes right in the board
        for(int j=start; j<end;j++){
            strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
        }
    }
    else{ // else it goes left in the board and flip the disc colour
        for(int j=start; j>end;j--){
            strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
        }
    }
}

void flipVertical(player InfoPlayer[], board infoBoard[], int playerTurns, int col,int start, int end)
{ // Function to flip the disc in vertical to the other color
    int j = col; // declaring variables

    if(start < end){ // if the beginning index is less than last it flips index as it goes forward in the board
        for(int i=start; i<end;i++){
            strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
        }
    }
    else{ // else it goes backwards in the board and flip the disc colour
        for(int i=start; i>end;i--){
            strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
        }
    }

}

void flipDiagonal(player InfoPlayer[], board infoBoard[], int playerTurns, int col,int start, int end, int side)
{ // Function to flip the disc in diagonal to the other color
    int j = col; // declaring variables

    if(start < end) { // if the beginning index is less than last it flips index as it goes forward in the board
        if(side == 1) { // side 1 means that its going backward to the right
            for (int i = start; i < end; i++) {
                strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
                j++;
            }
        }
        else if(side == 2){ // side 2 means that its going backward to the left
            for (int i = start; i < end; i++) {
                strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
                j--;
            }
        }
    }
    else if(start > end){ // else it goes backwards in the board and flip the disc colour
        if(side == 3) { // side 3 means that its going backward to the left
            for (int i = start; i > end; i--) {
                strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
                j--;
            }
        }
        else if(side == 4){ // side 4 means that its going backward to the right
            for (int i = start; i > end; i--) {
                strcpy(infoBoard[i].boards[j], InfoPlayer[playerTurns].colour);
                j++;
            }
        }
    }
}

bool emptyCheck(board infoBoard[])
{ // checks if the square they pick is empty or not if it is empty it returns true else false
    if(strcmp(infoBoard[infoBoard->rows - 1].boards[infoBoard->columns], "   ") == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

bool horizontalCheck(player InfoPlayer[], board infoBoard[], int playerTurn)
{ // Function to check if the their is a valid horizontal move
    // declaring variables
    bool checker = false;
    int i= infoBoard->rows - 1, end=0;

    if(strcmp(infoBoard[infoBoard->rows - 1].boards[infoBoard->columns+1], InfoPlayer[playerTurn].colour) != 0) { // make sure the one beside it is not the same colour
        for (int j = infoBoard->columns + 1; j < 8; j++) { // loops through the board
            if (strcmp(infoBoard[i].boards[j], "   ") == 0) { // if it reaches a blank square it breaks
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[i].boards[j]) == 0) {
                checker = true; // if it finds the same colour in the board to it, it returns true
                end = j;
                break;
            }
        }
    }

    if(strcmp(infoBoard[infoBoard->rows - 1].boards[infoBoard->columns-1], InfoPlayer[playerTurn].colour) != 0){ // make sure the one beside it is not the same colour
        for (int j = infoBoard->columns - 1; j > 0; j--) { // loops through the board
            if(strcmp(infoBoard[i].boards[j], "   ") == 0){ // if it reaches a blank square it breaks
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[i].boards[j]) == 0) { // make sure the one beside it is not the same colour
                checker = true; // if it finds the same colour in the board to it, it returns true
                end = j;
                break;
            }
        }
    }

    // initialise the index where it is up to if it returns true to be used
    infoBoard->horizontalEnd = end;
    infoBoard->rowFlip = i;
    return checker; // returns the boolean variable
}

bool verticalCheck(player InfoPlayer[], board infoBoard[], int playerTurn)
{ // Function to check if the their is a valid vertical move
    // declaring variables
    bool checker = false;
    int i= infoBoard->columns, end=0;

    if(strcmp(infoBoard[infoBoard->rows].boards[infoBoard->columns], InfoPlayer[playerTurn].colour) != 0) { // make sure the one beside it is not the same colour
        for (int j = infoBoard->rows; j < 8; j++) { // loops through the board
            if (strcmp(infoBoard[j].boards[i], "   ") == 0) { // if it reaches a blank square it breaks
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[i]) == 0) {
                checker = true; // if it finds the same colour in the board to it, it returns true
                end = j;
                break;
            }
        }
    }
    if(strcmp(infoBoard[infoBoard->rows - 2].boards[infoBoard->columns], InfoPlayer[playerTurn].colour) != 0){ // make sure the one beside it is not the same colour
        for (int j = infoBoard->rows - 2; j > 0; j--) { // loops through the board
            if(strcmp(infoBoard[j].boards[i], "   ") == 0){ // if it reaches a blank square it breaks
                break;
            }
            if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[i]) == 0) {
                checker = true; // if it finds the same colour in the board to it it returns true
                end = j;
                break;
            }
        }
    }

    // initialise the index where it is up to if it returns true to be used
    infoBoard->verticalEnd = end;
    return checker; // returns the boolean variable
}

bool diagonalCheck(player InfoPlayer[], board infoBoard[], int playerTurn)
{ // Function to check if the their is a valid diagonal move

    // declaring variables
    bool checker = false;
    int i = infoBoard->columns+1, end=0, index2Forward = infoBoard->columns-1, index2Backwords = infoBoard->columns+1, side=0;

     if(strcmp(infoBoard[infoBoard->rows].boards[infoBoard->columns+1], InfoPlayer[playerTurn].colour) != 0) { // make sure the one beside it is not the same colour
         for (int j = infoBoard->rows; j < 8; j++) { // loops through the board
             if (strcmp(infoBoard[j].boards[i], "   ") == 0) {
                 break; // if it reaches a blank square it breaks
             }
             if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[i]) == 0) {
                 checker = true; // if it finds the same colour in the board to it it returns true
                 end = j;
                 side = 1;
                 break;
             }
             i++;
         }
     }
     if(strcmp(infoBoard[infoBoard->rows].boards[infoBoard->columns-1], InfoPlayer[playerTurn].colour) != 0) { // make sure the one beside it is not the same colour
         for (int j = infoBoard->rows; j < 8; j++) {
             if (strcmp(infoBoard[j].boards[index2Forward], "   ") == 0) {
                    break;
             }
             if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[index2Forward]) == 0) {
                 checker = true; // if it finds the same colour in the board to it it returns true
                 end = j;
                 side = 2;
                 break;
             }
             index2Forward--;
         }
     }

     if(strcmp(infoBoard[infoBoard->rows - 2].boards[infoBoard->columns-1], InfoPlayer[playerTurn].colour) != 0) { // make sure the one beside it is not the same colour
         i = infoBoard->columns - 1; // reassigning back to its column for the next loop
         for (int j = infoBoard->rows - 2; j > 0; j--) { // loops through the board
             if (strcmp(infoBoard[j].boards[i], "   ") == 0) {
                 break; // if it reaches a blank square it breaks
             }
             if (strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[i]) == 0) {
                 checker = true; // if it finds the same colour in the board to it it returns true
                 end = j;
                 side = 3;
                 break;
             }
             i--;
         }
     }
     if(strcmp(infoBoard[infoBoard->rows - 2].boards[infoBoard->columns+1], InfoPlayer[playerTurn].colour) != 0){ // make sure the one beside it is not the same colour
        for (int j = infoBoard->rows - 2; j > 0; j--) {
             if(strcmp(infoBoard[j].boards[index2Backwords], "   ") == 0){
                 break; // if it reaches a blank square it breaks
             }
             if(strcmp(InfoPlayer[playerTurn].colour, infoBoard[j].boards[index2Backwords]) == 0){
                 checker = true; // if it finds the same colour in the board to it it returns true
                 end = j;
                 side = 4;
                 break;
             }
             index2Backwords++;
        }
     }

    // initialise the index where it is up to if it returns true to be used
    infoBoard->diagonalEnd = end;
    infoBoard->diagonalSide = side;

    return checker; // returns the boolean variable
}

bool availableMoveChecker(player InfoPlayer[], board infoBoard[], int playerTurn)
{ // Function to check if their is a available move for a specific player if their is it returns true else returns false
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
{ // check if the move is valid for different possibilities if it is it flips the discs and returns true
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
{ // return true if their is a move else returns false
    return availableMove(InfoPlayer, infoBoard, playerTurn);
}

bool availablePlayerMoves(player InfoPlayer[], board infoBoard[], int playerTurn)
{ // loops to check if any move is valid if their is it returns true else false
    bool check = false;
    for(int i=1;i<8;i++){
        for(int j=0;j<8;j++){
            infoBoard->rows = i;
            infoBoard->columns = j;
            if(availableMoveChecker(InfoPlayer, infoBoard, playerTurn)){
                check = true;
                break;
            }
        }
        if(check == true){
            break;
        }
    }
    return check;
}

bool makeMove(player InfoPlayer[], board infoBoard[], int playerTurn)
{ // function to do the move
    bool checker = false;

    if(condition(InfoPlayer, infoBoard, playerTurn)){
        strcpy(infoBoard[infoBoard->rows - 1].boards[infoBoard->columns], InfoPlayer[playerTurn].colour);
        checker = true;
    }else{
        printf("\nInvalid Move! Pls try again.\n");
    }

    return checker;
}
