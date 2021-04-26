#include <stdio.h>
#include <string.h>
#include "initialise.h"

void initializePlayers(player InfoPlayer[])
{
    int choice, checker = 1;

    printf("\n\t\t\t***  Welcome to Othello!  ***\n\n");

    printf("\nPlayer 1 please enter your name:\n");
    scanf("%s", InfoPlayer[0].name);
    printf("\nPlayer 2 please enter your name:\n");
    scanf("%s", InfoPlayer[1].name);

    while(checker == 1) {
        printf("\n\n%s(player 1) please chose a colour:\n\n"
               "For white type: 1,\n"
               "\tOr\n"
               "For black type: 2,\n", InfoPlayer[0].name);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(InfoPlayer[0].colour, "(W)");
                printf("\n**%s is White(W)**\n", InfoPlayer[0].name);
                strcpy(InfoPlayer[1].colour, "(B)");
                printf("**%s is Black(B)**\n", InfoPlayer[1].name);
                checker = -1;
                break;
            case 2:
                strcpy(InfoPlayer[0].colour, "(B)");
                printf("\n**%s is Black(B)**\n", InfoPlayer[0].name);
                strcpy(InfoPlayer[1].colour, "(W)");
                printf("**%s is White(W)**\n", InfoPlayer[1].name);
                checker = -1;
                break;
            default:
                puts("\nInvalid Input! Please Try again.\n");
                break;
        }
    }
}

void startBoard(board infoBoard[], player InfoPlayer[])
{
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i == 3 && j == 3) || (i == 4 && j == 4)){
                strcpy(infoBoard[i].boards[j],"(W)");
            }
            else if((i == 4 && j == 3) || (i == 3 && j == 4)){
                strcpy(infoBoard[i].boards[j],"(B)");
            }
            else{
                strcpy(infoBoard[i].boards[j],"   ");
            }
        }
    }
    InfoPlayer[0].score = 2;
    InfoPlayer[1].score = 2;
}

void boardPrinter(board info[], player InfoPlayer[])
{
    if(strcmp(InfoPlayer[0].colour, "(B)") == 0){
        printf("\n\n\tScore: %s(Black %s) %d:%d %s(White %s)\n", InfoPlayer[0].name, InfoPlayer[0].colour, InfoPlayer[0].score, InfoPlayer[1].score,InfoPlayer[1].name, InfoPlayer[1].colour);
    }
    else{
        printf("\n\tScore: %s (Black %s) %d:%d %s (White %s)\n", InfoPlayer[1].name, InfoPlayer[1].colour, InfoPlayer[1].score, InfoPlayer[0].score,InfoPlayer[0].name, InfoPlayer[0].colour);
    }
    printf("\n     a     b     c     d     e     f     g     h  ");
    puts("\n   _____ _____ _____ _____ _____ _____ _____ _____");
    for(int i=0;i<8;i++){
        printf("%d |", i+1);
        for(int j=0;j<8;j++){
            printf(" %s |",  info[i].boards[j]);
        }
        printf(" %d\n   _____ _____ _____ _____ _____ _____ _____ _____\n", i+1);
    }
    puts("     a     b     c     d     e     f     g     h  ");
}

void initializeBeg(player InfoPlayer[], board infoBoard[])
{
    initializePlayers(InfoPlayer);
    startBoard(infoBoard, InfoPlayer);
    boardPrinter(infoBoard, InfoPlayer);
}