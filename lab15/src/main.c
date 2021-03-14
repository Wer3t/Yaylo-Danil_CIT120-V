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
int main()
{
	printf("\n");
	srand(time(0));
	int n = count_lines();
	struct bird types[n];

	read_file(types, n);
	write_file(types, n);
	write_out(types, n);

	int criterion = 0;
	printf("\nВведите критерий, по которому будут отсортированы структуры : \nОкольцованность птицы[1]                Высота дома[5]\nВид птицы[2]                            Количество кормушек в доме[6]\nВозраст птицы[3]                        Наличие гнезда[7]\nПлощадь дома[4]                         Пол птицы[8]\nВведите число: ");
	scanf("%d", &criterion);
	if (criterion > 0 && criterion < 9)
	{
		sorting(types, criterion, n);
	}
	else
	{
		printf("\nВведено неверное число!\n");
	}
	printf("\n");
	read_file(types, n);

	percent_male_to_female(types, n);

	generation();
	printf("\n");

	struct bird *p;
	for (int i = 0; i < n; i++)
	{
		check(p = types[i].ringed);
		check(p = types[i].species);
		check(p = types[i].age);
		check(p = types[i].house.square);
		check(p = types[i].house.height);
		check(p = types[i].house.num_feeders);
		check(p = types[i].house.nest);
		check(p = types[i].sex);
	}

	read_file_bin(types, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d, ", types[i].ringed);
		printf("%s, ", types[i].species);
		printf("%d, ", types[i].age);
		printf("%d, ", types[i].house.square);
		printf("%d, ", types[i].house.height);
		printf("%d, ", types[i].house.num_feeders);
		printf("%d, ", types[i].house.nest);
		printf("%d ", types[i].sex);
		printf("\n");
	}
	write_file_bin(types, n);

	printf("\nВведите индекс структуры, в которой нужно будет найти поле(от 0 до %d): ", n - 1);
	int num;
	scanf("%d", &num);
	write_struct_number(num);

	return 0;
}
