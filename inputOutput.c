#include <stdio.h>
#include <string.h>
#include "inputOutput.h"


//TODO: impliment a find invalid strings / find exit condition
//For testing weather the user input is valid
/*int isValidEquation(char *eqaStr)
{

}*/

int isQuitString(char *eqaStr)
{
    if (*eqaStr == 'q' || *eqaStr == 'Q')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// TODO: add error checking
void getUserEquation(char *eqaStr)
{
    char *eqaStrBegining = eqaStr;

    // clear the equation string so it can be reused
    memset(eqaStr, 0, EQUATION_STR_LEN);

    char tmpChar = 0xff;
    printf(":");

    int i;
    for (i = 0; i < EQUATION_STR_LEN; i++)
    {
        tmpChar = getchar();

        if (tmpChar == '\n')
        {
            break; // If the user presses enter
        }
        else if (tmpChar == EOF)
        {
            // fake a quit command at the start of the string
            *eqaStrBegining = 'q';
            eqaStr++;
            // fake a return key press
            puts("");
            break;
        }

        if (tmpChar != ' ') // Ignore spaces
        {
            *eqaStr = tmpChar;
            eqaStr++;
        }
    }
    *eqaStr = '\0';
}

void printResault(double *resault)
{
    // This is only a stub
    printf("= %.2f\n", *resault);
}
