#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) { return a>b ? a : b;}

int knapSack(int W, int wt[],int val[],int n ){

    if (W == 0 || n == 0){
        return 0;
    }
    if(wt[n-1] > W){
        return knapSack(W,wt,val,n-1);
    }else return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
}

int main(){

    int profit[] = { 25, 20, 15,40,50 }; 
	int weight[] = { 3, 2, 1,4,5 }; 
    int W = 6;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("Value is : %d",knapSack(W,weight,profit,n));
    return 0;   
}