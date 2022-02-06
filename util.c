/*
Author: Eilon Alter
ID: 208500603
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#include "util.h"

/* ----------------------- An util function to print the square-----------------------------*/
void printSquare(int square[N][N])
{
    int row;
    int position;
    for (row = 0; row < N; row++)
    {
        for (position = 0; position < N; position++)
        {
            printf("%d ", square[row][position]);
        }
        printf("\n");
    }
}

/* -------------------------------------------- An util function to append string ----------------------------------------------*/
void addToString(char *char_array, char c)
{
    int length = strlen(char_array);
    char_array[length] = c;
    char_array[length + 1] = '\0';
}

/* --------------------------------------------- An util function to append the square --------------------------------------*/
void addToSquare(int square[N][N], char *tempInputArr, int row, int position)
{
    int number = atoi(tempInputArr);
    square[row][position] = number;
}

/* --------------------------------------------- An util function to check if a char is whitespace --------------------------------------*/
bool findWhiteSpace(char c)
{
    return c == ' ' || c == '\n' || c == '\t';
}

/* ----------------------------- An util function to check if a square is magicsquare --------------------------------------- */
bool isMagicSquare(int square[N][N])
{
    int i;
    int j;
    int expectedSum = 0;
    int rowSum = 0;
    int columnSum = 0;
    int firstdiagonalSum = 0;
    int secondDiagonalSum = 0;

    for (i = 0; i < N; i++)
    {
        expectedSum += square[0][i];
    }

    for (i = 0; i < N; i++)
    {
        rowSum = 0;
        columnSum = 0;
        for (j = 0; j < N; j++)
        {
            rowSum += square[i][j];
            columnSum += square[j][i];
        }
        if (rowSum != expectedSum || columnSum != expectedSum)
        {
            return false;
        }
    }
    for (i = 0; i < N; i++)
    {
        firstdiagonalSum += square[i][i];
        secondDiagonalSum += square[i][N - 1 - i];
    }

    if (firstdiagonalSum != expectedSum || secondDiagonalSum != expectedSum)
    {
        return false;
    }
    return true;
}

/*----------------------An util function that gets input and return if valid or not -------------------------------*/
bool getInputs(int square[N][N])
{
    char cInput;
    int row = 0;
    int position = 0;
    char tempInputArr[10];
    bool hasSeenWhitespace = false;
    while (true)
    {
        cInput = getchar();
        if (isdigit(cInput))
        {
            if (row == N)
            {
                printf("ERROR - too many numbers has given.\n");
                return false;
            }
            addToString(tempInputArr, cInput);
            hasSeenWhitespace = false;
        }
        else if (findWhiteSpace(cInput) || cInput == EOF)
        {
            if (!hasSeenWhitespace)
            {
                addToSquare(square, tempInputArr, row, position);
                strcpy(tempInputArr, "");
                if (position == N - 1)
                {
                    position = 0;
                    row++;
                }
                else
                {
                    position++;
                }
                hasSeenWhitespace = true;
            }
            if (cInput == EOF)
            {
                break;
            }
        }
        else
        {
            printf("ERROR - given input is not a digit (or a whitespace).\n");
            return false;
        }
    }
    if (row < N)
    {
        printf("ERROR - not enought numbers has given.\n");
        return false;
    }
    else
    {
        return true;
    }
}