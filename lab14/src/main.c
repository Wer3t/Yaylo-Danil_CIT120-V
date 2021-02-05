/**
 * @mainpage
 * # Загальне завдання
 * 1. **Вирахувати** для тексту частотну таблицю: для кожного символу визначити 
 * його частоту появи у тексті (число таких символів у тексті ділене на загальне число символів у тексті)
 * @author Yaylo D.
 * @date 13-dec-2020
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Yaylo D.
 * @date 13-dec-2020
 * @version 1.0
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - вивід результату роботи функції @function task
 * @return успішний код повернення з програми (0)
 */
int main() {
	char str[100];
	input_func(str);
		
	int N=strlen(str);
	char *str_res= (char *)calloc(N, sizeof(char));
    double *res= (double *)calloc(N, sizeof(double));
    
	task((char*)str_res, (double*) res, str, N);
	print((char*)str_res, (double*) res, N, str);

    free(res);
    free(str_res);
    printf("Введите '.' для вывода структуры проекта: ");	
    task1("", 0);
    task2();
	return(0);
}


