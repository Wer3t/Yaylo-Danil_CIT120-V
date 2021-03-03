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
int main() {
	srand(time(0));
	printf("\n");
	
	D_LinkedList *list=create_list();
	
	int n=count_lines();
	read_file(list, n);
	write_file(list);
	write_out(list);
	
	int to_add = 2;
	if(to_add ==0){
		add_tail(list);
	}else if(to_add==list->size||to_add>list->size){
		add_head(list);
	}else if(to_add>0&&to_add<list->size){
		insert(list, to_add);
	}
	write_out(list);
	
	int to_delete = 3;
	to_delete--;
	deleteNth(list, to_delete);
	write_out(list);
	
	int criterion=0;
	printf("\nВведите критерий, по которому будут отсортированы структуры : \nОкольцованность птицы[1]                Высота дома[5]\nВид птицы[2]                            Количество кормушек в доме[6]\nВозраст птицы[3]                        Наличие гнезда[7]\nПлощадь дома[4]                         Пол птицы[8]\nВведите число: ");
	scanf("%d", &criterion);
	if(criterion>0&&criterion<9){
	sorting(list, criterion);
	}else{
		printf("\nВведено неверное число!\n");
	}
	printf("\n");
	write_file(list);
	
	return 0;
}


