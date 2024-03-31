
#include "application.h"

int main()
{
    Std_ReturnType StdRet = E_NOT_OK;

    double Num1 = 0;
    double Num2 = 0;
    char Symbol = 0;
    char ExitCheck = 0;
    double Result = 0;

    while (1)
    {
        /*Display welcome screen*/
        welcome_screen();
        /*Print list include operations we can support*/
        print_operation_list();
        /*Take symbol from the user */
        printf("Please Enter symbol for your operation depend on previous table \n");
        scanf(" %c", &Symbol);
        /*Select operation */
        switch (Symbol)
        {
        case '+':
            /*Take inputs from the user*/
            printf("Please Enter 1st Number \n");
            scanf(" %lf", &Num1);
            printf("Please Enter 2nd Number \n");
            scanf(" %lf", &Num2);
            /*Print the result*/
            StdRet = add(&Num1, &Num2, &Result);
            printf("%.2lf %c %.2lf =  %.2lf \n ", Num1, Symbol, Num2, Result);
            break;
        case '-':
            /*Take inputs from the user*/
            printf("Please Enter 1st Number \n");
            scanf(" %lf", &Num1);
            printf("Please Enter 2nd Number \n");
            scanf(" %lf", &Num2);
            /*Print the result*/
            StdRet = sub(&Num1, &Num2, &Result);
            printf("%.2lf %c %.2lf =  %.2lf \n ", Num1, Symbol, Num2, Result);
            break;
        case '*':
            /*Take inputs from the user*/
            printf("Please Enter 1st Number \n");
            scanf(" %lf", &Num1);
            printf("Please Enter 2nd Number \n");
            scanf(" %lf", &Num2);
            /*Print the result*/
            StdRet = multiply(&Num1, &Num2, &Result);
            printf("%.2lf %c %.2lf =  %.2lf \n ", Num1, Symbol, Num2, Result);
            break;
        case '/':
            /*Take inputs from the user*/
            printf("Please Enter 1st Number \n");
            scanf(" %lf", &Num1);
            printf("Please Enter 2nd Number \n");
            scanf(" %lf", &Num2);
            /*Print the result*/
            StdRet = division(&Num1, &Num2, &Result);
            printf("%.2lf %c %.2lf =  %.2lf \n ", Num1, Symbol, Num2, Result);
            break;
        case 'l':
            /*Take inputs from the user*/
            printf("Please Enter the number need to calculate log \n");
            scanf(" %lf", &Num1);
            /*Print the result*/
            StdRet = logarithm(&Num1, &Result);
            printf(" Log[ %.2lf ]=  %.2lf \n ", Num1, Result);
            break;
        case 'r':
            /*Take inputs from the user*/
            printf("Please Enter the number need to calculate square root \n");
            scanf(" %lf", &Num1);
            /*Print the result*/
            StdRet = sq_root(&Num1, &Result);
            printf("SqRoot[ %.2lf ] =  %.2lf \n ", Num1, Result);
            break;
        }

        printf("If you want to exit press < x > for continuing press any key  \n");
        scanf(" %c", &ExitCheck);
        if ('x' == ExitCheck)
        {
            exit(0);
        }

        system("cls");
    }

    return 0;
}

Std_ReturnType add(double *Num1, double *Num2, double *Result)
{
    Std_ReturnType Ret = E_NOT_OK;
    if (NULL == Result)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        *Result = *Num1 + *Num2;
        Ret = E_OK;
    }
    return Ret;
}
Std_ReturnType sub(double *Num1, double *Num2, double *Result)
{
    Std_ReturnType Ret = E_NOT_OK;
    if (NULL == Result)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        *Result = *Num1 - *Num2;
        Ret = E_OK;
    }
    return Ret;
}
Std_ReturnType multiply(double *Num1, double *Num2, double *Result)
{
    Std_ReturnType Ret = E_NOT_OK;
    if (NULL == Result)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        *Result = (*Num1) * (*Num2);
        Ret = E_OK;
    }
    return Ret;
}
Std_ReturnType division(double *Num1, double *Num2, double *Result)
{
    Std_ReturnType Ret = E_NOT_OK;
    if (NULL == Result)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        *Result = *Num1 / *Num2;
        Ret = E_OK;
    }
    return Ret;
}
Std_ReturnType logarithm(double *Num, double *Result)
{
    Std_ReturnType Ret = E_NOT_OK;
    if (NULL == Result)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        *Result = log((*Num));
        Ret = E_OK;
    }
    return Ret;
}
Std_ReturnType sq_root(double *Num, double *Result)
{
    Std_ReturnType Ret = E_NOT_OK;
    if (NULL == Result)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        *Result = sqrt((*Num));
        Ret = E_OK;
    }
    return Ret;
}

void welcome_screen(void)
{
    uint32 Counter = 0;

    printf(" ___      _________   ___          _____ \n");
    printf("|     |  |    |    | |   | |      |      \n");
    printf("|___  |  |    |    | |___| |      |_____ \n");
    printf("    | |  |    |    | |     |      |      \n");
    printf(" ___| |  |    |    | |     |_____ |_____ \n");

    Sleep(1 * Sec);
    system("cls"); // calls the cls command.
    printf(" _____  ___          _____                 ___   _______   _____   ___ \n");
    printf("|      |   | |      |      |     | |      |   | |   |   | |     | |   |\n");
    printf("|      |___| |      |      |     | |      |___|     |     |     | |___|\n");
    printf("|      |   | |      |      |     | |      |   |     |     |     | | \\ \n");
    printf("|_____ |   | |_____ |_____ |_____| |_____ |   |     |     |_____| |  \\\n");

    Sleep(1 * Sec);
    system("cls");
    printf("************* Loading ************* \n");

    for (Counter = 0; Counter < 18; Counter++)
    {
        printf("\u263A "); // smile face
        Sleep(0.5 * Sec);
    }
    Sleep(1 * Sec);
    system("cls");
}
void print_operation_list(void)
{
    printf("List of mathematical operation we can support \n");
    printf("--------------------------------------------- \n");
    printf("|       Operation         |       Symbol    | \n");
    printf("--------------------------------------------- \n");
    printf("|       Adding            |         +       | \n");
    printf("|       Subtraction       |         -       | \n");
    printf("|       Division          |         /       | \n");
    printf("|       Multiplication    |         *       | \n");
    printf("|       Logarithm         |         l       | \n");
    printf("|       Square Root       |         r       | \n");
    printf("--------------------------------------------- \n");
}