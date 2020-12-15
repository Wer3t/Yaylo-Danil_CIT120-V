#include <iostream>
#include <cstdlib>
#include<stdio.h>

int main()
{
    srand(time(0));
    #define N 3
    int mas[N][N];
    int i2,j2,sum; 
    int masr[N][N];
    for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++){
        mas[i][j] = rand()%100;
        masr[i][j] = 0;
        }
  }
    
     for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++){
            for(int k=0; k<N; k++){
            	masr[i][j]+=mas[i][k]*mas[k][j];
            }     
            
       } 
  }
    for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++)
    {
        printf( "%d ", masr[i][j] );
    }
    printf( "\n" );
  }
    return 0;
}
