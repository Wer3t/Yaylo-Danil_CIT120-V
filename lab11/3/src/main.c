/**
 * @mainpage
 * # Загальне завдання
 * 1. Дано масив з  речовинних чисел. **Підрахувати** кількість ділянок, 
 * які утворюють безперервні послідовності чисел з не-зменшуваними значеннями.
 * Максимальну ділянку **переписати** у інший масив.
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
void print1(double ** masr,int N);

void print2(double ** masr,int N,int max);

double task(double N, ...);

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - вивід результату роботи функції @function task
 * @return успішний код повернення з програми (0)
 */
int main() {
	task(10, 1.1, 1.2, 1.5, 1.3, 1.2, 1.3, 1.4, 1.5, 1.1, 1.2);
	return(0);
}

/**
 * @function task
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *	 @param mas Масив вказівників на числа, 
 * 	        які передаються за допомогою варівтивної функції
 *	 @param masr Масив масивів вказівників з строками,
 *	 	які утворюють безперервні послідовності чисел з не-зменшуваними значеннями.
 * - Заповнення масиву mas за допомогою варівтивної функції
 * - Перевірка на виконання умови
 * - Виписування всих ділянок, які утворюють безперервні послідовності 
 *   чисел з не-зменшуваними значеннями.
 * - Знаходження найбільшої, за сумою всих елементів, ділянки
 * - Вивід на екран результату виконання операцій
 */
double task(double N, ...){
	va_list args;/**Початок роботи з варіативними аргументами */
	va_start(args, N);
	
	double *mas = (double*)calloc(N, sizeof(double));
	for (int i =0; i<N; i++){
		double value = va_arg(args, double);
		*(mas+i)=value;
	}
	
	double **masr= (double **)calloc(N, sizeof(double *));
	for(int i=0;i<N;i++){
		masr[i] = (double*)calloc(N, sizeof(double));
	}
	
	int j =0,max=0,k=0;
	
	for(int i=0;i<N; i++){
	/*Отдельная проверка для последнего элемента что б не выходить за размер массива*/
		if(i==N-1){
			if(*(mas+i)>=*(mas+i-1)){
				*(*(masr+j))+=*(mas+i);
				*(*(masr+j)+k+1)=*(mas+i);
				break;
			} else {
				j++;
				*(*(masr+j))+=*(mas+i);
				*(*(masr+j)+1)=*(mas+i);
				break;
			}
		}
	/*Проверка на выполнение условия*/
		if(*(mas+i)<=*(mas+i+1)){
			*(*(masr+j))+=*(mas+i);
			*(*(masr+j)+k+1)=*(mas+i);
			k++;
		} else {
			j++;
			*(*(masr+j))+=*(mas+i);
			*(*(masr+j)+1)=*(mas+i);
			k=1;
		}
		
	}
	
	print1((double**)masr, N);
	
	/*Нахождение максимальной строки массива*/
	for(int i=1;*(*(masr+i))!=0;i++){
		if(*(*(masr+i))>*(*(masr+i-1))){
			if(*(*(masr+i))>*(*(masr+max))){
				max=i;
			}
		}
	}	
	
	print2((double**) masr, N, max);
	
	/*Освобождение памяти*/
	free(mas);
	for(int i=0; i<N; i++){
		free(masr[i]);
	}
	free(masr);
		
	va_end(args);
}

void print1(double ** masr,int N){
	for(int i=0;i<N;i++){
		for(int p=0;p<N;p++){
			printf("%f ", *(*(masr+i)+p));
		}
		printf("\n");
	}
}

void print2(double ** masr,int N,int max){
	/*Вывод максимальной строки массива*/
	printf("\n");
	for(int i=0;*(*(masr+max)+i)!=0;i++){
		printf("%f ", *(*(masr+max)+i));
	}
}
