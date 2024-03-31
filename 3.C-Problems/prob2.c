/*Write a function which, given a string, 
return TRUE if all characters are distinct and FALSE if any character is repeated.
*/

/************ Includes ***********************/
#include <stdio.h>
#include <stdbool.h>

/********** Functions Declarations ***********/
bool areAllCharactersDistinct(const char* str) ;
bool areAllCharactersDistinct_2(const char* str) ;

/********** Start of main functions *********/
int main() {
    // Example usage
    const char* testString1 = "abcdefg";
    const char* testString2 = "belal abdalaziz";

    if (areAllCharactersDistinct_2(testString1)) {
        printf("%s: All characters are distinct!\n", testString1);
    } else {
        printf("%s: Characters are not distinct!\n", testString1);
    }

    if (areAllCharactersDistinct_2(testString2)) {
        printf("%s: All characters are distinct!\n", testString2);
    } else {
        printf("%s: Characters are not distinct!\n", testString2);
    }

    return 0;
}

/********** Functions Definations ***********/
bool areAllCharactersDistinct(const char* str) {
    // Assuming ASCII characters (0-127)
    bool charSet[128] = {false};

    while (*str) {
        // If the character is already existed, return FALSE
        if (true == charSet[(int)*str]) {
            return false;
        }

        // Mark the character as encountered
        charSet[(int)*str] = true;

        // Move pointer to the next character in the string
        str++;
    }

    // If the loop completes, all characters are distinct
    return true;
}
/*The*/
bool areAllCharactersDistinct_2(const char* str) 
{
    bool Ret;
    bool ASCII_Charecter_Representation[128]={false};
    char repeatationFlag =0;
    while (*str)
    {
        //if the chareacter is alreeady existed it is repeated
        if(true == ASCII_Charecter_Representation[(int)*str])
        {
            repeatationFlag = 1;
            break;
        }
        else{/*Nothing*/}
        // Mark the character as encountered
        ASCII_Charecter_Representation[(int)*str] = true;
        /*move pointer to next character*/
        str++;
    }
    
    if (1 == repeatationFlag)
    {
        Ret = false;
    }
    else if (0 == repeatationFlag)
    {
        Ret = true;
    }
    else{/*Nothing*/}
    
    
    return Ret;
}

