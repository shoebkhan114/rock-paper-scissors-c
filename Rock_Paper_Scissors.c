#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int check(char c, char comp)
{
    if (c == comp)
    {
        return 0; // TIE
    }
    if (c == 'r' && comp == 's' || c == 'p' && comp == 'r' || c == 's' && comp == 'p')
    {
        return 1; // Player Wins
    }
    else
    {
        return -1; // Computer Wins
    }
}
int main()
{
    int number, r, attempts = 1, result = -2;
    char comp, player, Playerchoice[10], Computerchoice[10];

    printf("Welcome to the Rock, Paper, Scissors game!\n");
    printf("        *** By SHOEB KHAN ***\n");
    srand(time(0));
    do
    {
        result = -2; // Reset result for each new game
        number = rand() % 3;
        if (number == 0)
        {
            comp = 'r';
            strcpy(Computerchoice, "Rock");
        }
        else if (number == 1)
        {
            comp = 'p';
            strcpy(Computerchoice, "Paper");
        }
        else
        {
            comp = 's';
            strcpy(Computerchoice, "Scissors");
        }
        do
        {
            r = 0;
            printf("Choose your move:\n");
            printf("Press 'r' for Rock\n");
            printf("Press 'p' for Paper\n");
            printf("Press 's' for Scissors\n");
            printf("Enter your choice: ");
            scanf(" %c", &player);
            switch (player)
            {
            case 'r':
                strcpy(Playerchoice, "Rock");
                result = check('r', comp);
                break;
            case 'p':
                strcpy(Playerchoice, "Paper");
                result = check('p', comp);
                break;
            case 's':
                strcpy(Playerchoice, "Scissors");
                result = check('s', comp);
                break;
            default:
                r = 1;
                printf("Invalid choice! Please try again.\n");
            }
        } while (r);
        printf("\nYour Choice: '%s'\nComputer Choice: '%s'\n", Playerchoice, Computerchoice);

        if (result == 1)
        {
            printf("Congratulations! You won in %d attempt(s).\n", attempts);
        }
        else if (result == -1)
        {
            printf("You lost! Try again...\n\n");
        }
        else
        {
            printf("It's a Tie! Play Again...\n\n");
        }
        attempts++;
    } while (result != 1);
    return 0;
}
