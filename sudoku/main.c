#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudokuFunctions.c"
//Main
//1. Read in as a string
//2. convert string to a 2D array 
int** sudokuBoard;
int main(){

	char filename[100];

	printf("Enter file name\n");
	scanf("%s", filename);

	//print initial board
	char *array = boardStr(filename);
	printf("%s", array);
	
	int **boardArr;
        boardArr = boardStrToArr(array);
	sudokuBoard = boardArr; 
	
	solveSudoku();
	printArray(sudokuBoard);

	//block of code used for testing "isPossible" function
//	int test1 = isPossible(sudokuBoard, 4, 4, 1);
//	printf("position (4, 4) testing number 1 is: %d\n", test1);
//	int test2 = isPossible(sudokuBoard, 4, 4, 2);	
//	printf("position (4, 4) testing number 2 is: %d\n", test2);	
//	int test3 = isPossible(sudokuBoard, 4, 4, 3);	
//	printf("position (4, 4) testing number 3 is: %d\n", test3);	
//	int test4 = isPossible(sudokuBoard, 4, 4, 4);	
//	printf("position (4, 4) testing number 4 is: %d\n", test4);	
//	int test5 = isPossible(sudokuBoard, 4, 4, 5);	
//	printf("position (4, 4) testing number 5 is: %d\n", test5);	
//	int test6 = isPossible(sudokuBoard, 4, 4, 6);	
//	printf("position (4, 4) testing number 6 is: %d\n", test6);	
//	int test7 = isPossible(sudokuBoard, 4, 4, 7);	
//	printf("position (4, 4) testing number 7 is: %d\n", test7);		
//	int test8 = isPossible(sudokuBoard, 4, 4, 8);	
//	printf("position (4, 4) testing number 8 is: %d\n", test8);	
//	int test9 = isPossible(sudokuBoard, 4, 4, 9);	
//	printf("position (4, 4) testing number 9 is: %d\n", test9);	
	

	return 0;
}




