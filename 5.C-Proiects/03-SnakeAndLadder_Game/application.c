#include "application.h"

Std_ReturnType StdRet = E_NOT_OK;

int main()
{
    uint32 P1_Pos = 0;
    uint32 P2_Pos = 0;
    uint32 DiceValue_P1 = 0;
    uint32 DiceValue_P2 = 0;
    uint32 NumOfPlayers = 0;
    char ch;
    /*Welcome screen*/
    welcome_screen();
    /*Choose 2 players or one player*/
    printf("Choose number of players : 1 playing with computer(press 1)  \n");
    printf("                           2 players (Press 2)     \n");
    scanf(" %i", &NumOfPlayers);
    /*start game*/
    printf("Player 1 Position is : %i\n", P1_Pos);
    /*One player or 2 players*/
    switch (NumOfPlayers)
    {
    case 1:
        printf("Player 2 is a computer, Position is : %i\n", P2_Pos);
        break;
    case 2:
        printf("Player 2 Position is : %i\n", P2_Pos);
        break;

    default:
        printf("Invalid number of players \n");
        exit(0);
        break;
    }

    printf("(P1&P2)\n");
    StdRet = display_snake_ladder(&P1_Pos, &P2_Pos);

    while (1)
    {
        /*Player 1 will play*/
        printf("Player 1 to roll the dice write 'a'\n,If you want to exit write 'x'\n");
        scanf(" %c", &ch);
        /*Check input 1*/
        if (ch == 'a')
        {
            /*Clear screen*/
            system("cls");
            /*rolling dice and set player 1 position*/
            rolling_dice();
            StdRet |= dice_select_value(&DiceValue_P1);
            P1_Pos += DiceValue_P1;
            /*Check player 1 position will meet snake or ladder*/
            set_ladder_snake_Pos(&P1_Pos);
            /*Display the positions  */
            printf("Player 1 Position is : %i\n", P1_Pos);
            switch (NumOfPlayers)
            {
            case 1:
                printf("Player 2 is a computer, Position is : %i\n", P2_Pos);
                break;
            case 2:
                printf("Player 2 Position is : %i\n", P2_Pos);
                break;

            default:
                break;
            }
            StdRet = display_snake_ladder(&P1_Pos, &P2_Pos);
        }
        else if (ch == 'x')
        {
            exit(0);
        }
        else
        {
            printf("Player 1 invalid input !!. Missed your chance, try next round\n");
        }
        /*Player 2 will play*/
        switch (NumOfPlayers)
        {
        case 1:
            printf("Press 'b' to the computer rolling the dice\n,If you want to exit write 'x'  \n");
            scanf(" %c", &ch);
            break;
        case 2:
            printf("Player 2 to roll the dice write 'b'\n,If you want to exit write 'x'\n");
            scanf(" %c", &ch);
            break;

        default:
            break;
        }
        /*Check input 2*/
        if (ch == 'b')
        {
            /*Clear screen*/
            system("cls");
            /*rolling dice and set player 2 position*/
            rolling_dice();
            StdRet |= dice_select_value(&DiceValue_P2);
            P2_Pos += DiceValue_P2;
            /*Check player 1 position will meet snake or ladder*/
            set_ladder_snake_Pos(&P2_Pos);
            /*Display the positions  */
            printf("Player 1 Position is : %i\n", P1_Pos);
            switch (NumOfPlayers)
            {
            case 1:
                printf("Player 2 is a computer, Position is : %i\n", P2_Pos);
                break;
            case 2:
                printf("Player 2 Position is : %i\n", P2_Pos);
                break;

            default:
                break;
            }
            StdRet = display_snake_ladder(&P1_Pos, &P2_Pos);
        }
        else if (ch == 'x')
        {
            exit(0);
        }
        else
        {
            printf("Player 2 invalid input !!. Missed your chance, try next round\n");
        }

        // Display Who is a winner
        if (P1_Pos >= 100)
        {
            printf("Player 1 is a winner \n");
            exit(0);
        }
        else if (P2_Pos >= 100)
        {
            switch (NumOfPlayers)
            {
            case 1:
                printf("Computer is a winner \n");
                break;
            case 2:
                printf("Player 2 is a winner \n");
                break;
            default:
                break;
            }
            exit(0);
        }
        else
        { /*Nothing*/
        }
    }

    return 0;
}

Std_ReturnType dice_select_value(uint32 *DiceValue)
{
    Std_ReturnType StdRet = E_NOT_OK;
    uint32 CheckVal = 0;

    if (NULL == DiceValue)
    {
        StdRet = E_NOT_OK;
    }
    else
    {
        /*Select random every time*/
        srand(time(NULL));
        /*Range of random number less than 7 -> 0 : 6 */
        CheckVal = rand() % 7;
        /*We dont need 0 so check it to avoid 0 value*/
        if (0 == CheckVal)
        {
            *DiceValue = CheckVal + 1;
        }
        else
        {
            *DiceValue = CheckVal;
        }
        StdRet = E_OK;
    }
    return StdRet;
}

Std_ReturnType display_snake_ladder(uint32 *Player1_Pos, uint32 *Player2_Pos)
{
    uint32 NumberCounter = 0;
    sint32 RowCounter = 0;
    sint32 ColumnCounter = 0;

    for (RowCounter = 0; RowCounter <= 11; RowCounter++)
    {
        for (ColumnCounter = 0; ColumnCounter <= 11; ColumnCounter++)
        {

            if ((0 == RowCounter) || (11 == RowCounter))
                printf("------");
            else if ((0 == ColumnCounter) || (11 == ColumnCounter))
            {
                printf("|    ");
            }
            else
            {
                NumberCounter++;

                if ((*Player1_Pos == NumberCounter))
                { // Player 1 Position
                    if (*Player1_Pos == *Player2_Pos)
                    {
                        printf("(P1&P2)");
                    }
                    else
                    {
                        display_Player(1);
                    }
                }
                else if (*Player2_Pos == NumberCounter)
                { // Player 2 Position
                    if (*Player1_Pos == *Player2_Pos)
                    {
                        printf("(P1&P2)");
                    }
                    else
                    {
                        display_Player(2);
                    }
                }
                else if (NumberCounter < 10)
                { // Number is 1 Digit
                    printf(" %i     ", NumberCounter);
                }
                else if (100 == NumberCounter)
                { // Number is 3 Digit
                    printf("%i    ", NumberCounter);
                }
                /*Ladder:- 70 to 93, 60 to 83, 13 to 42.*/
                else if ((13 == NumberCounter) || (42 == NumberCounter))
                { // Ladder 1
                    display_ladder(1);
                }
                else if ((60 == NumberCounter) || (83 == NumberCounter))
                { // Ladder 2
                    display_ladder(2);
                }
                else if ((70 == NumberCounter) || (93 == NumberCounter))
                { // Ladder 3
                    display_ladder(3);
                }
                /*Snakes:- 99 to 1, 65 to 40, 25 to 9.*/
                else if ((25 == NumberCounter) || (9 == NumberCounter))
                { // Snake 1
                    display_snake(1);
                }
                else if ((65 == NumberCounter) || (40 == NumberCounter))
                { // Snake 2
                    display_snake(2);
                }
                else if ((99 == NumberCounter) || (1 == NumberCounter))
                { // Snake 3
                    display_snake(3);
                }
                else
                {
                    // Number is 2 Digit from 11 : 99
                    printf("%i     ", NumberCounter);
                }
            }
        }
        printf("\n\n");
    }
}

void display_ladder(uint32 LadderNum)
{
    printf("<#%i>   ", LadderNum);
}
void display_snake(uint32 SnakeNum)
{
    printf("<$%i>   ", SnakeNum);
}
void display_Player(uint32 PlayerNum)
{
    printf("(P%i)   ", PlayerNum);
}

void rolling_dice(void)
{
    uint32 Counter = 0;
    printf("Rolling Dice \n");
    for (Counter = 0; Counter < 6; Counter++)
    {
        printf(SmileFace " ");
        Sleep(0.25 * SEC);
    }
    printf("\n");
    system("cls");
}

void set_ladder_snake_Pos(uint32 *PlayerPos)
{
    switch (*PlayerPos)
    {
    case 13:
        *PlayerPos = 42;
        printf("Stairs at 13 " SmileFace "\n");
        break;
    case 60:
        *PlayerPos = 83;
        printf("Stairs at 60 " SmileFace "\n");
        break;
    case 70:
        *PlayerPos = 93;
        printf("Stairs at 70 " SmileFace "\n");
        break;
    case 99:
        *PlayerPos = 1;
        printf("Sad news .Snake at 99 !! \n");
        break;
    case 65:
        *PlayerPos = 40;
        printf("Sad news .Snake at 65 !! \n");
        break;
    case 25:
        *PlayerPos = 9;
        printf("Sad news .Snake at 25 !! \n ");
        break;
    default:
        break;
    }
}
void welcome_screen(void)
{
    uint32 Counter = 0;
    printf(" ___   ____   ___       _____ \n");
    printf("|     |    | |   | | / |      \n");
    printf("|___  |    | |___| |/  |_____ \n");
    printf("    | |    | |   | |\\  |      \n");
    printf(" ___| |    | |   | | \\ |_____ \n");

    Sleep(1 * SEC);
    system("cls"); // calls the cls command.
    printf("  ___   ____        | \n");
    printf(" |   | |    |       | \n");
    printf(" |___| |    |  _____| \n");
    printf(" |   | |    | |     | \n");
    printf(" |   | |    | |_____| \n");

    Sleep(1 * SEC);
    system("cls"); // calls the cls command.
    printf("         ___                 _____   ___  \n");
    printf("|       |   |       |      ||       |   |\n");
    printf("|       |___|  _____| _____||_____  |___|\n");
    printf("|       |   | |     ||     ||       | \\ \n");
    printf("|_____  |   | |_____||_____||_____  |  \\\n");

    Sleep(1 * SEC);
    system("cls");
    printf("************* Loading ************* \n");

    for (Counter = 0; Counter < 18; Counter++)
    {
        printf(SmileFace); // smile face
        Sleep(0.5 * SEC);
    }
    Sleep(1 * SEC);
    system("cls");
}