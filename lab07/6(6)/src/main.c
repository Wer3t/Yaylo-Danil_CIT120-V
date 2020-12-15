/**
 * @mainpage
 * # Загальне завдання
 * 1. Дано двовимірний масив NxN цілих чисел. **Помножити матрицю** саму на себе
 * елементів рядків масиву в напряму справа наліво
 * @author Yaylo D.
 * @date 22-nov-2020
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Yaylo D.
 * @date 22-nov-2020
 * @version 1.0
 */
#include <iostream>
#include <cstdlib>
#include<stdio.h>
int task(N);

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - Задання константи розміру масиву
 *   @param N Розмір масиву
 * - вивід результату роботи функції @function task
 * @return успішний код повернення з програми (0)
 */
int main(){
    int const N = 3;
    task(N);
    return 0;
}

/**
 * @function task
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *	@param N Розмір масиву
 *	@param mas[][] Масив початковий
 *	@param masr[][] Результуючий масив, після виконанння операції множення
 * - Заповнення масиву за алгоритмом
 * - Поступове множення масиву за правилами множення матриць
 * - Вивід на екран результату зрушення
 */
int task(int N){
    srand(time(0));
    int mas[N][N];
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
    }
}
    printf( "\n" );
    }
}
