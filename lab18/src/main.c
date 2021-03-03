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
	srand(time(0));
	printf("\n");
	
	char str1[]="text1";
	char *s1 = (char*)malloc(sizeof(char));
	s1=&str1;
	
	char str2[]="text2";
	char *s2 = (char*)malloc(sizeof(char));
	s2=&str2;
	
	insert((char *) s1,(char *) s2,3);
	
	
	char str[]="tetextxt";
	char *s = (char*)malloc(sizeof(char));
	s=&str;
	reduce((char *) s,3,7);
	
	int n=3;
	struct bird *types = (struct bird*)malloc(sizeof(struct bird));
	for(int i=0;i<n;i++){
		types[i].ringed= rand()%2;
		sprintf(types[i].species,"bird %d",i+1);;
		types[i].age= rand()%50;
		types[i].house.square= rand()%100;
		types[i].house.height= rand()%100;
		types[i].house.num_feeders= rand()%10;
		types[i].house.nest= rand()%2;
		types[i].sex= rand()%2;
	}
	int to_do=0;
	printf("\nЧто сделать с массивом структур?\nДобавить структуру[1]          Удалить структуру[0]\n");
	scanf("%d", &to_do);
	printf("\n");
	if(to_do == 1){
		add_struct((struct bird *)types, n);
		for(int i=0;i<n+1;i++){
		printf( "%d, ", types[i].ringed);
		printf( "%s, ", types[i].species);
		printf( "%d, ", types[i].age);
		printf( "%d, ", types[i].house.square);
		printf( "%d, ", types[i].house.height);
		printf("%d, ", types[i].house.num_feeders);
		printf( "%d, ", types[i].house.nest);
		printf( "%d ", types[i].sex);
		printf("\n");
	}
	}else if(to_do == 0){
		remove_struct((struct bird *)types, n);
		printf("\n");
		for(int i=0;i<n-1;i++){
		printf( "%d, ", types[i].ringed);
		printf( "%s, ", types[i].species);
		printf( "%d, ", types[i].age);
		printf( "%d, ", types[i].house.square);
		printf( "%d, ", types[i].house.height);
		printf("%d, ", types[i].house.num_feeders);
		printf( "%d, ", types[i].house.nest);
		printf( "%d ", types[i].sex);
		printf("\n");
	}
	}
	
	//free(s1);
	//free(s2);
	//free(s);
	return 0;
}


