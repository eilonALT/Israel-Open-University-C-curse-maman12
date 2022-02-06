/*
Author: Eilon Alter
ID: 208500603
*/

#define N 5

void addToString(char *char_array, char c);
void addToSquare(int square[N][N], char *tempInputArr, int row, int place);
bool findWhitespace(char c);
bool isMagicSquare(int square[N][N]);
void printSquare(int square[N][N]);
bool getInputs(int square[N][N]);