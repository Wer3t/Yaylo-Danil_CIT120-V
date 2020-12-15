/**
 * @mainpage
 * # Загальне завдання
 * 1. Дано масив з  цілих чисел. Елементи головної діагоналі **записати** в одновимірний масив, 
 * отриманий масив **упорядкувати** за зростанням
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

#include "stdio.h"
#include "stdarg.h"

int task(int N);

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - вивід результату роботи функції @function task
 * @return успішний код повернення з програми (0)
 */
int main() {
	int const N =5;
    task(N);
    return (0);
}

/**
 * @function task
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *	 @param mas Масив масивів вказівників на псевдовипадкові числа
 * - Заповнення масиву випадковими числами
 * - @param masr Масив вказівників з результуючими числами 
 * - Виписування головної діагоналі масиву masr 
 * - Сортування методом бульбашки
 * - Вивід на екран результату виконання операцій
 */
int task(int N){
	srand(time(0));
	
	int *masr = (int*)calloc(N, sizeof(int));
	
	int **mas= (int **)calloc(N, sizeof(int *));
	for(int i=0;i<N;i++){
		mas[i] = (int*)calloc(N, sizeof(int));
	}
	for(int i =0; i<N; i++){
		for(int j=0;j<N;j++){
			*(*(mas+i)+j)=rand()%10;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ", *(*(mas+i)+j));
		}
		printf("\n");
	}
	int j=0;
	
	for(int i=0;i<N; i++){
		*(masr+i)=*(*(mas+i)+j);
		j++;
		}
		
	printf("\n");
	for(int i=0;i<N;i++){
		printf("%d ", *(masr+i));
	}
	
	for(int i=0; i<N-1; i++){
		for(int j=0; j<N-i-1; j++){
			if(*(masr+j)>*(masr+j+1)){
				int a=*(masr+j);
				*(masr+j)=*(masr+j+1);
				*(masr+j+1)=a;
			}
		}
	}
	
	/*Вывод максимальной строки массива*/
	printf("\n");
	for(int i=0;i<N;i++){
		printf("%d ", *(masr+i));
	}
	/*Освобождение памяти*/
	free(masr);
	for(int i=0; i<N; i++){
		free(mas[i]);
	}
	free(mas);
}
