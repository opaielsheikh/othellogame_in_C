#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "ValidMove.h"
// importing the required libraries

int playerTurn(int currentTurn)
{ // function to check the turn and return the other player turn either 0 or 1
    if(currentTurn == 0) {
        return 1;
    }
    else{
        return 0;
    }
}

int column(const char col)
{ // Function that convert the letter to number for the column index
    int val=-1;
    switch (col){
        case 'a':
            val = 0;
            break;
        case 'b':
            val = 1;
            break;
        case 'c':
            val = 2;
            break;
        case 'd':
            val = 3;
            break;
        case 'e':
            val = 4;
            break;
        case 'f':
            val = 5;
            break;
        case 'g':
            val = 6;
            break;
        case 'h':
            val = 7;
            break;
        default:
            break;
    }
    return val;
}

void playerScores(board infoBoard[], player InfoPlayer[])
{ // updating the score for the player
    int player1Score = 0, player2Score = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(strcmp(infoBoard[i].boards[j], InfoPlayer[0].colour) == 0){
                player1Score++;
            }
            if(strcmp(infoBoard[i].boards[j], InfoPlayer[1].colour) == 0){
                player2Score++;
            }
        }
    }
    InfoPlayer[0].score = player1Score;
    InfoPlayer[1].score = player2Score;
}

void finalBoardAppendToFile(board info[], player InfoPlayer[], FILE *fptr)
{ // appends the final board to the file
    if(strcmp(InfoPlayer[0].colour, "(B)") == 0){
        fprintf(fptr,"\n\n\tScore: %s(Black %s) %d:%d %s(White %s)\n", InfoPlayer[0].name, InfoPlayer[0].colour, InfoPlayer[0].score, InfoPlayer[1].score,InfoPlayer[1].name, InfoPlayer[1].colour);
    }
    else{
        fprintf(fptr,"\n\tScore: %s (Black %s) %d:%d %s (White %s)", InfoPlayer[1].name, InfoPlayer[1].colour, InfoPlayer[1].score, InfoPlayer[0].score,InfoPlayer[0].name, InfoPlayer[0].colour);
    }
    fprintf(fptr,"\n     a     b     c     d     e     f     g     h  ");
    fprintf(fptr,"\n   _____ _____ _____ _____ _____ _____ _____ _____\n");
    for(int i=0;i<8;i++){
        fprintf(fptr,"%d |", i+1);
        for(int j=0;j<8;j++){
            fprintf(fptr," %s |",  info[i].boards[j]);
        }
        fprintf(fptr," %d\n   _____ _____ _____ _____ _____ _____ _____ _____\n", i+1);
    }
    fprintf(fptr,"     a     b     c     d     e     f     g     h  \n");
}

void winnerResultDisplayPrinter(board infoBoard[], player InfoPlayer[], time_t timetaken)
{ // Function that displays the winner/draw to the user and board and time of the game and date and append to the file with all that info othello-results.txt
    struct tm* ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt);

    FILE *fptr;
     // open to append to the file the result
    if((fptr = fopen("othello-results.txt", "a")) == NULL){
        puts("Error! File is not opening");
    }
    else{
        // if statements to check which got the higher score and the append the result to the file
        if(InfoPlayer[0].score > InfoPlayer[1].score){
            fprintf(fptr,"\n %s\n", asctime(ptr));
            fprintf(fptr,"\n%s(Player 1) is the winner! Congrats.\n", InfoPlayer[0].name);
            fprintf(fptr,"\nThe Time taken for the game: %ld mins", timetaken/60);
            fprintf(fptr,"\nThe Final Score is %d:%d", InfoPlayer[0].score, InfoPlayer[1].score);
            fprintf(fptr,"\nThe Final Board is:\n");
            finalBoardAppendToFile(infoBoard, InfoPlayer, fptr);
        }
        else if(InfoPlayer[0].score < InfoPlayer[1].score){
            fprintf(fptr,"\n %s\n", asctime(ptr));
            fprintf(fptr,"\n%s(Player 2) is the winner! Congrats.\n", InfoPlayer[1].name);
            fprintf(fptr,"\nThe Time taken for the game: %ld mins", timetaken/60);
            fprintf(fptr,"\nThe Final Score is %d:%d", InfoPlayer[0].score, InfoPlayer[1].score);
            fprintf(fptr,"\nThe Final Board is:\n");
            finalBoardAppendToFile(infoBoard, InfoPlayer, fptr);
        }
        else if(InfoPlayer[0].score == InfoPlayer[1].score){
            fprintf(fptr,"\n %s\n", asctime(ptr));
            fprintf(fptr,"\nIts A Draw!");
            fprintf(fptr,"\nThe Time taken for the game: %ld mins", timetaken/60);
            fprintf(fptr,"\nThe Final Score is %d:%d", InfoPlayer[0].score, InfoPlayer[1].score);
            fprintf(fptr,"\nThe Final Board is:\n");
            finalBoardAppendToFile(infoBoard, InfoPlayer, fptr);
        }
    }

    // if statements to check which got the higher score and print the result to the user
    if(InfoPlayer[0].score > InfoPlayer[1].score){
        printf("\n %s\n", asctime(ptr));
        printf("\n%s(Player 1) is the winner! Congrats.\n", InfoPlayer[0].name);
        printf("\nThe Time taken for the game: %ld mins", timetaken/60);
        printf("\nThe Final Score is %d:%d", InfoPlayer[0].score, InfoPlayer[1].score);
        printf("\nThe Final Board is:\n");
        boardPrinter(infoBoard, InfoPlayer);
    }
    else if(InfoPlayer[0].score < InfoPlayer[1].score){
        printf("\n %s\n", asctime(ptr));
        printf("\n%s(Player 2) is the winner! Congrats.\n", InfoPlayer[1].name);
        printf("\nThe Time taken for the game: %ld mins", timetaken/60);
        printf("\nThe Final Score is %d:%d", InfoPlayer[0].score, InfoPlayer[1].score);
        printf("\nThe Final Board is:\n");
        boardPrinter(infoBoard, InfoPlayer);
    }
    else if(InfoPlayer[0].score == InfoPlayer[1].score){
        printf("\n %s\n", asctime(ptr));
        printf("\nIts A Draw!");
        printf("\nThe Time taken for the game: %ld mins", timetaken/60);
        printf("\nThe Final Score is %d:%d", InfoPlayer[0].score, InfoPlayer[1].score);
        printf("\nThe Final Board is:\n");
        boardPrinter(infoBoard, InfoPlayer);
    }

}


void playGame(player InfoPlayer[], board infoBoard[])
{ // function that plays the game
    // declaring variables
    char col, colm[0];
    int playerCurrent, row=0;
    bool checker = false;
    time_t start, end;
    start = time(NULL);

    // sets the black player to play first
    if(strcmp(InfoPlayer[0].colour, "(B)") == 0){
        playerCurrent = 0;
    }
    else{
        playerCurrent = 1;
    }
    // loops while their is a available move
    while(availablePlayerMoves(InfoPlayer, infoBoard, 0) || availablePlayerMoves(InfoPlayer, infoBoard, 1)){
        if(availablePlayerMoves(InfoPlayer, infoBoard, 0) == false && playerCurrent == 0){ // if their is no available move for player 1 it passes to the next player
            printf("\nNo available moves for %s(player 1), Passed to the next player\n", InfoPlayer[0].name);
            playerCurrent = 1;
        }
        if(availablePlayerMoves(InfoPlayer, infoBoard, 1) == false && playerCurrent == 1){ // if their is no available move for player 1 it passes to the next player
            printf("\nNo available moves for %s(player 2), Passed to the next player\n", InfoPlayer[1].name);
            playerCurrent = 0;
        }
        // getting the input from the user for the postion they want to place their disc and keeps loops unless it is valid move
        printf("\n%s(player %d) Please enter the rows and columns you want to position(i.e d2): \n", InfoPlayer[playerCurrent].name, playerCurrent+1);
        scanf("%1s%d", colm, &row);
        col = colm[0];
        infoBoard->rows = row;
        infoBoard->columns = column(col);
        checker = makeMove(InfoPlayer, infoBoard, playerCurrent);
        if(checker == false){
            while(checker != true){
                printf("\n%s(player %d) Please enter the rows and columns you want to position(i.e d2): \n", InfoPlayer[playerCurrent].name, playerCurrent+1);
                scanf("%1s%d", colm, &row);
                col = colm[0];
                infoBoard->rows = row;
                infoBoard->columns = column(col);
                checker = makeMove(InfoPlayer, infoBoard, playerCurrent);
            }
        }
        // displays the board and players score and set the next player
        playerScores(infoBoard, InfoPlayer);
        boardPrinter(infoBoard, InfoPlayer);
        playerCurrent = playerTurn(playerCurrent);
    }
    // if their is no more valid move for either player it calls the function that diplays the winner,time,date,score, and append all that info to the file
        end = time(NULL);
        winnerResultDisplayPrinter(infoBoard, InfoPlayer, difftime(end, start));
}
