#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** sudokuBoard;
char* boardStr(char* filename);
int** boardStrToArr(char* str);
int** createArray(int m, int n);
int isPossible(int** array, int x, int y, int n);
int solveSudoku();
char* printArray(int** board);
