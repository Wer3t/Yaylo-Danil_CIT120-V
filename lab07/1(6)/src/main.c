/**
 * @mainpage
 * # Загальне завдання
 * 1. **Центрувати** заданий рядок на площині із заданим заповнювачем
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

int task(char[]);

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - вивід результату роботи функції @function task
 * @return успішний код повернення з програми (0)
 */
int main() {
	task(" Ivanov         ");
	return 0;
}

/**
 * @function task
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *	@param N Розмір масиву
 *	@param zapovnuvach Символ, яким необхідно замінити пусті елементи масиву
 *	@param pusto Кількість пустих елементів масиву
 *	@param s Початок слова, яке необхідно центрувати
 *	@param e Кінець слова, яке необхідно центрувати
 *	@param mas[] Вхідний масив с текстом
 * - Визначення кількості пустих елементів
 *   визначення початку і кінця слова
 * - Запис слова в окремий масив
 * - Заміна половини пустих елемнтів @param zapovnuvach
 * - Запис слова із окремого масиву в початковий
 * - Заміна іншої половини пустих елемнтів @param zapovnuvach
 */
int task(char mas[]){
	const char zapovnuvach = '_';
	#define N 16
	int pusto = 0, s = 0, e = 0, j=0;
	for (int i =0; i<N; i++){
		if (mas[i] == ' '){
			pusto++;
		}
		if (mas[i]!=' '&&mas[i-1]==' '){
			s = i;
		}
		if (mas[i]!=' '&&mas[i+1]==' '){
			e = i;
		}
	}
	pusto/=2;
	int N2 = e-s+1;
	char mas2 [N2];
	for (int i = 0; i<N2; i++){
		mas2[i]=mas[s+i];
	}
	for (int i=0; i<pusto; i++){
		mas[i]=zapovnuvach;
	}
	N2+=pusto;
	for (int i = pusto; i<N2; i++){
		mas [i] = mas2[j];
		j++;
	}
	for (int i = N2; i<N; i++){
		mas[i] = zapovnuvach;
	}
	for (int i = 0; i<N; i++){
		printf("%c", mas[i]);
	}
}
