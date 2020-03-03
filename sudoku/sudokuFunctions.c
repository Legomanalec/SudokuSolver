#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudokuFunctions.h"

int **sudokuBoard;

//Function to read a file and 
//convert it to a single char* string
//*Done*
char* boardStr(char* filename)
{
	FILE *fptr;
	filename[100];
	char c;
	char *board = malloc(400 * sizeof(char));

	fptr = fopen(filename, "r");
	
	if(fptr == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}

	c = fgetc(fptr);

	int i = 0;
	while(c != EOF)
	{
		board[i] = c;
		c = fgetc(fptr);
		i++;
	}
	
	fclose(fptr);
	return board;

}
//Function to take in a string and 
//turn it into a Sudoku board.
int **boardStrToArr(char *str)
{

	printf("Entered boardStrToArr\n");
	//Use ascii value to check if numbers in string should be saved
	//
	int** array = createArray(9, 9);
	int i;
	int x = 0;
	int y = 0;
	

	
	for(i = 0; i < strlen(str); i++)
	{

		//checks ascii values in the string
		if(str[i] - 48 <= 9 && str[i] - 48 >= 0)
		{
			 					
			array[y][x] = str[i] - 48;
			if(x == 9)
			{
				y++;
				x = 0;
				
			}
			x++;	
		}	
	}
	return array;
}


//Function to create a 2D array
//ashepler on stackoverflow
int **createArray(int m, int n)
{
	int *column = calloc(m*n, sizeof(int));
	int **row = malloc(n*sizeof(int*));
	for(int i = 0; i < n; i++)
	{
		row[i] = column + i*m;
	}
	return row;
}


//check if value tested is possible

//*Done*
int isPossible(int** array, int x, int y, int n)
{
	//Numbers in front
	//Y
	for(int i = 1; i < 9; i++)
	{
		if((i+y) > 8)
			break;
		else if(n == array[x][y+i])
			return 0;
			
	}	
	//X
	for(int i = 1; i < 9; i++)
	{
		if((i+x) > 8)
			break;
		else if(n == array[x+i][y])
			return 0;
		
	}

	//Numbers behind
	//Y
	for(int i = 1; i < 9; i++)
	{
		if((y-i) < 0)
			break;
		else if(n == array[x][y-i])
			return 0;
	}
	//X
	for(int i = 1; i < 9; i++)
	{
		if((x-i) < 0)
			break;
		else if (n == array[x-i][y])
			return 0;
	}

	int i = x / 3;
	int j = y / 3;
	
	for(int k = 3*i; k < (3*i)+3; k++)
	{
	       for(int l = 3*j; l < (3*j)+3; l++)
	       {
	      		if(n == array[k][l])
			{
				return 0;
			}			
	       }
	}
	return 1;
}

//solve using recursion and backtracking
int solveSudoku()
{
	
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(sudokuBoard[i][j] == 0)
			{
				for (int n = 1; n < 10; n++)
				{
					if(isPossible(sudokuBoard, i, j, n) == 1)
					{
						sudokuBoard[i][j] = n;
						if(solveSudoku() == 1)
						{
							return 1;
						}
						else
						{
							sudokuBoard[i][j] = 0;
						}						
					}
				}
				return 0;
			}
		}
	}
	return 1;
	
}

//convert array to string
char *printArray(int **board)
{
	char *str;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			printf("%d ", board[i][j]);	
		}
		printf("\n");
	}
}

