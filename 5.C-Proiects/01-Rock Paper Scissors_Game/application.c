
#include "application.h"

int main()
{
    char ComputerChoice = 0;
    char UserChoice = 0;
    int CloseGame = 0;
    /*Welcome screen */
    welcome_screen();
    do
    {
        /*Chose randomly by computer */
        computer_choice(&ComputerChoice);
        /*Take input from the user */
        user_choice(&UserChoice);
        /*Call game procedure*/
        game_procedure(UserChoice, ComputerChoice);
        /*Close program or not*/
        printf(" To close the game press <0> ,To play again press <1> \n");
        scanf(" %i", &CloseGame);
    } while (CloseGame != 0);
    return 0;
}

/*Welcome screen */
void welcome_screen(void)
{
    uint32 Counter = 0;

    printf(" ___   _____   _____      \n");
    printf("|   | |     | |       | /\n");
    printf("|___| |     | |       |/ \n");
    printf("| \\   |     | |       |\\ \n");
    printf("|  \\  |_____| |_____  | \\\n");

    Sleep(1 * Sec);
    system("cls"); // calls the cls command.
    printf(" ___      _     ___   _____  ___ \n");
    printf("|   |    / \\   |   | |      |   |\n");
    printf("|___|   /___\\  |___| |_____ |___|\n");
    printf("|      /     \\ |     |      | \\ \n");
    printf("|     /       \\|     |_____ |  \\\n");

    Sleep(1 * Sec);
    system("cls"); // calls the cls command.
    printf(" ___    _____     ___   ___    _____    ___   ___ \n");
    printf("|      |       | |     |      |     |  |   | |    \n");
    printf("|___   |       | |___  |___   |     |  |___| |___ \n");
    printf("    |  |       |     |     |  |     |  | \\      |\n");
    printf(" ___|  |_____  |  ___|  ___|  |_____|  |  \\  ___|\n");

    Sleep(1 * Sec);
    system("cls");
    printf("************* Loading ************* \n");
    for (Counter = 0; Counter < 18; Counter++)
    {
        printf("\u263A "); // smile face
        Sleep(0.5 * Sec);
    }
}
/*Computer Side */
void computer_choice(char *ComputerChoice)
{
    uint32 RandomNumber = 0;
    /*Select random every time*/
    srand(time(NULL));
    /*Range of random number less than 100*/
    RandomNumber = rand() % 100;
    /*Select computer choice */
    if ((RandomNumber >= 0) && (RandomNumber < 33))
    {
        *ComputerChoice = ROCK;
    }
    else if ((RandomNumber >= 33) && (RandomNumber < 66))
    {
        *ComputerChoice = PAPER;
    }
    else if ((RandomNumber >= 66) && (RandomNumber <= 100))
    {
        *ComputerChoice = SCISSORS;
    }
    else
    {
        /*Nothing*/
    }
}
/*User Side*/
void user_choice(char *RetChoice)
{
    char UserInput = 0;
    printf("\nPlease Enter your Input \n");
    printf("r -> Rock ,, p -> Paper ,, s -> Scissor \n");
    scanf(" %c", &UserInput);
    // UserInput = getchar();
    switch (UserInput)
    {
    case 'r':
        *RetChoice = ROCK;
        break;
    case 'p':
        *RetChoice = PAPER;
        break;
    case 's':
        *RetChoice = SCISSORS;
        break;

    default:
        *RetChoice = Error;
        printf("Your input invalid\n");
        break;
    }

    // UserInput = getchar();
    //  gets(UserInput);
}
/*Game procedure*/
void game_procedure(char UserInput, char ComputerInput)
{
    if (UserInput == ComputerInput)
    {
        printf(" No winner \n");
    }
    else
    {
        if ((UserInput == ROCK) && (ComputerInput == PAPER))
        {
            printf("The Computer choose the PAPER  :) \n");
            printf("### Bad news. You are a loser  :( ###\n");
        }
        else if ((UserInput == PAPER) && (ComputerInput == ROCK))
        {
            printf("The Computer choose the ROCK  !! \n");
            printf("### Congratulations. You are a winner :)  ### \n");
        }
        else if ((UserInput == SCISSORS) && (ComputerInput == PAPER))
        {
            printf("The Computer choose the PAPER  :( \n");
            printf("### Congratulations. You are a winner  :) ###\n");
        }
        else if ((UserInput == PAPER) && (ComputerInput == SCISSORS))
        {
            printf("The Computer choose the SCISSORS :) \n");
            printf("### Bad news. You are a loser  !! ### \n");
        }
        else if ((UserInput == ROCK) && (ComputerInput == SCISSORS))
        {
            printf("The Computer choose the SCISSORS :) \n");
            printf("### Congratulations. You are a winner  :) ###\n");
        }
        else if ((UserInput == SCISSORS) && (ComputerInput == ROCK))
        {
            printf("The Computer choose the ROCK  :) \n");
            printf("### Bad news. You are a loser  !! ### \n");
        }
    }
}
