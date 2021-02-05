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
 * @date 11-jan-2021
 * @version 1.0
 */

#include "stdio.h"


void start_print(void);

void print(double ** masr,double N,int max);

void filling(double N, double * mas);

double task(double N, double * mas, double ** masr);

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - вивід результату роботи функції @function task
 * @return успішний код повернення з програми (0)
 */
int main() {
	start_print();
	int N= filling_N();
	
	double *mas= (double*)calloc(N, sizeof(double));
	double **masr= (double **)calloc(N, sizeof(double *));
	for(int i=0;i<N;i++){
		masr[i] = (double*)calloc(N, sizeof(double));
	}
	
	filling(N, (double*) mas);
	
	int max= task(N, (double*) mas, (double**) masr);
	
	print((double**) masr, N, max);
	
	/*Освобождение памяти*/
	free(mas);
	for(int i=0; i<N; i++){
		free(masr[i]);
	}
	free(masr);
	return 0;
}
/**
 * @function start_print
 *
 * Послідовність дій:
 * - Виведення на консоль повідомлення
 * - Зчитування прізвища та першої літери імені 
 * - Виведення повідомлень про автора, тему та номер роботи
 */
void start_print(){
	char surname[10];
	char name;
	
	printf("Введите фамилию: ");
	gets(surname);
	printf("Введите имя(только инициалы): ");
	name=getc(stdin);
	printf("\nauthor %s %c. \n", surname, name);
	puts("lab:");
	char Num = 'N';
	write(1, &Num, 1);
	putc('1',stdout);
	putc('2', stdout);
	printf("\ntheme: input and output mechanism \n");

}
/**
 * @function filling_N
 *
 * Послідовність дій:
 * - Виведення на консоль повідомлення
 * - Введення розміру масиву @param n
 * - Зчитування розміру за допомогою функції read
 * - Повернення розміру масиву n
 */
int filling_N(){
	printf("Введите размер входного массива: \n");
	char N1,N2;
	int n;
	read(0, &N1,1);
	int n1 = N1 - '0';
	read(0, &N2,1);
	int n2 = N2 - '0';
	if(n2>=0){
		n = n1*10+n2;
	}else{
		n=n1;
	}

	return n;
}
/**
 * @function filling
 *
 * Послідовність дій:
 * - Виведення на консоль повідомлення, який елемент масиву потрібно записати
 * - Введення числа та зчитування його за допомогою функції scanf
 */
void filling(double N, double * mas){
	for(int i=0; i<N; i++){
		printf("Введите элемент массива %d: ", i);
		scanf("%lf",&*(mas+i));
		printf("\n");
	}
	
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
double task(double N, double * mas, double ** masr){
	
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
	
	/*Нахождение максимальной строки массива*/
	for(int i=1;*(*(masr+i))!=0;i++){
		if(*(*(masr+i))>*(*(masr+i-1))){
			if(*(*(masr+i))>*(*(masr+max))){
				max=i;
			}
		}
	}	
	
	return max;
}


void print(double ** masr,double N,int max){
	/*Вывод максимальной строки массива*/
	printf("\n");
	for(int i=0;*(*(masr+max)+i)!=0;i++){
		printf("%f ", *(*(masr+max)+i));
	}
}
