
#include<stdio.h>
#define N 3
int main()
{
    int a;
    int mas[N][N];
    for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) //Заполнение ячеек массива случайными числами
        mas[i][j] = i+j;
  }
   for (int i=0;i<N;i++) { //движение по строкам массива
        a=mas[i][0];
        for (int j=0;j<N;j++){ //движение по элементам строки и их перестановка
                mas[i][j]=mas[i][j+1];
       } 
       mas[i][N-1]=a;
  }
    for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++)
    {
        printf( "%d ", mas[i][j] );
    }
    printf( "\n" );
  }
    return 0;
}
