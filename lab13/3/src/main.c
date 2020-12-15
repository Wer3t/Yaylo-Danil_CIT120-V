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
	char str[]="abbcccdddd";
	int N=strlen(str);
	task(str, N);
	return(0);
}


