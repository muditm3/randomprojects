//Program to play rock, paper and scissors

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <cs50.h>

void game();

int main(void)
{

    printf("Let's play Rock, Paper and Scissors\n");
    printf("\nYou have to win 5 times first to win. And you have to type in what you choose\n");

    printf("\n\n\t\tDEMO\n");
    printf("\nYour turn: rock\t\tComputer's Turn: paper\n");
    printf("\nComputer wins\n");

    char play = 'y';

    do
    {
        game();
        printf("\nDo you wanna play again?");
        scanf("%s", &play);
        printf("okay\n");

    }while(play != '0');
}

void game()
{
    int playerWins = 0, compWins= 0;

    while(playerWins < 5  &&  compWins < 5)
    {
        char yourTurn[9], compTurn[9];
        int comp;

        printf("\nYour turn: ");
        scanf("%s", yourTurn);

        printf("\nComputer's Turn: ");

        srand(time(0));
        comp = rand() % 3;

        switch(comp)
        {
            case 0: strcpy(compTurn, "rock");
                    printf("%s\n", compTurn);
                    break;
            case 1: strcpy(compTurn, "paper");
                    printf("%s\n", compTurn);
                    break;
            case 2: strcpy(compTurn, "scissor");
                    printf("%s\n", compTurn);
                    break;
        }

        if((!strcmp(yourTurn, "rock")  &&  !strcmp(compTurn, "scissor"))  ||  (!strcmp(yourTurn, "paper")  &&  !strcmp(compTurn, "rock"))  ||  (!strcmp(yourTurn, "scissor")  &&  !strcmp(compTurn, "paper")))
        {
            playerWins++;
        }
        else if((!strcmp(yourTurn, "rock")  &&  !strcmp(compTurn, "paper"))  ||  (!strcmp(yourTurn, "paper")  &&  !strcmp(compTurn, "scissor"))  ||  (!strcmp(yourTurn, "scissor")  &&  !strcmp(compTurn, "rock")))
        {
            compWins++;
        }

        printf("\n\nYour Wins: %i\t\tComp's Wins: %i\n", playerWins, compWins);
    }

    if(playerWins == 5)
        printf("\nYou Win!\n");
    else
        printf("\nComputer Wins!\n");
}