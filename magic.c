/*
This program gets input from user/file and return if the input create magic square and prints the square

The N number is defined at the util.h file , you can change it there as you wish

Author: Eilon Alter
ID: 208500603
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "util.h"

/*-----------------------------Main run fuction getting user input, calling util functions and prints the result.--------------------*/
int main()
{
    bool magic; /* a value that tracks the program steps and changes to false if one of them didn't go throw */
    
    int square[N][N];

    magic = getInputs(square);

    if (!magic)
    {
        return -1;
    }

    printSquare(square);

    magic = isMagicSquare(square);

    if (magic)
    {
        printf("The given inputs makes a magic square!\n");
    }
    else
    {
        printf("The given inputs do not make a magic square!\n");
    }
    return 0;
}