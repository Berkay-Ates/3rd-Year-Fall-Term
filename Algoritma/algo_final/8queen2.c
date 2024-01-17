#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 4
 
void printSolution(int board[N][N]){
	int i,j;
	for ( i = 0; i < N; i++)
	{
		for ( j = 0; j < N; j++)
		{
			if(board[i][j])
				printf("Q ");
			else 
				printf(". ");
		}
		printf("\n");
	}
}

bool isSafe(int board[N][N],int row,int col){
	int i , j;

	// satirin devaminin safe olup olmadigini kontrol edelim 
	for ( i = 0; i < col; i++)
	{
		if(board[row][i]){
			return false;
		}
	}

	// ust caprazi kontrol edelim 
	for ( i = row,j=col; i>=0 && j>=0; i--,j--){
		if(board[i][j]){
			return false;
		}
	}

	// sol alt caprazi kontrol edelim 
	for ( i = row, j = col; i < N && j>=0; i++,j--){
		if(board[i][j]){
			return false;}
	}

	// tum kontrolleri gectiyse return true
	return true;
}


bool solveNQUtil(int board[N][N], int col){
	int i = 0;

	if(col>=N){
		return true;
	}

	for ( i = 0; i < N; i++)
	{
		if (isSafe(board,i,col))
		{
			board[i][col] = 1;

			if(solveNQUtil(board,col+1))
				return true;

			board[i][col] = 0;
		}
	}
	return false;
}

bool solveNQ(){
	int board[N][N] = {
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 }
    };

	if(solveNQUtil(board,0) == false){
		printf("Solution does not exists");
		return false;
	}

	printSolution(board);
	return true;
}

int main(){
	solveNQ();

	return 0;
}