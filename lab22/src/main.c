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

#include "list.h"
#include "data.h"

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
int main()
{
	srand(time(0));
	printf("\n");
	regex_t regex;
	int reti;
	reti = regcomp(&regex, "^[A-ZА-Я]((\\w|\\d|[А-Яа-я])+(\\s?[.,?:;!]?))", REG_EXTENDED);
	if (reti) {
   		fprintf(stderr, "Could not compile regex\n");
    	exit(1);
	}

	D_LinkedList *list = create_list();

	int n=count_lines()/2+1;
	read_list(list, regex, reti, n);

	reti = regcomp(&regex, ".+\\s.+", REG_EXTENDED);
	if (reti) {
   		fprintf(stderr, "Could not compile regex\n");
    	exit(1);
	}

	write_out(list, regex, reti);

	deleteDbLinkedList(list);
	regfree(&regex);
	return 0;
}
