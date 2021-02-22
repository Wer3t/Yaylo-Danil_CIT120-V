/**
 * @mainpage
 * # Загальне завдання
 * 1. **Створити** структуру, що відображає "базовий клас" та виконати
 * індивідуальне завдання 
 * @author Yaylo D.
 * @date 15-feb-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Yaylo D.
 * @date 15-feb-2021
 * @version 1.0
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - вивід результату роботи функції @function read_file
 * - вивід результату роботи функції @function write_out
 * - вивід результату роботи функції @function write_out
 * - вивід результату роботи функції @function sorting
 * - вивід результату роботи функції @function percent_male_to_female
 * - вивід результату роботи функції @function task
 * - вивід результату роботи функції @function generation
 * @return успішний код повернення з програми (0)
 */
int main() {
	printf("\n");
	char str[]="text1";
	char *s1 = (char*)malloc(sizeof(char));
	s1=&str;
	char *s2;
	insert((char *) s1,"text2",3);
	printf("%s\n",s1+1);	
	free(s1);
	reduce("tetextxt",3,7);
	return 0;
}


