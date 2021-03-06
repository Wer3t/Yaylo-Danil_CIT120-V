#ifndef _YAYLO_13_
#define _YAYLO_13_

/**
 * @file lib.h
 * @brief Файл з об'явою прототипів функцій.
 *
 * @author Yaylo D.
 * @date 13-dec-2020
 * @version 1.0
 */
 
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct place {
	int square;
	int height;
	int num_feeders;
	char nest;
};

struct bird{
	char ringed;
	char species[20];
	int age;
	struct place house;
	char sex;
};

/**
 * @function task
 *
 * Послідовність дій:
 * - оголошеня змінних 
 * 	@param str_res  Результуючий масив вказівників на всі символи, які зустрічаються
 * 	@param res  Результуючий масив вказівників на частоту зустрічання символів
 * 	@param kol  Кількість зустрічання символу
 * - param res  Результуючий масив вказівників на частоту зустрічання символів
 * 	@param kol  Кількість зустрічання символу
 * - Цикл для визначення зустрічання символу [і] і занесення результату у результуючі масиви
 * - Цикл для знаходження всих повторів і їх видалення, шляхом зсуву
 * - вивід результату роботи функції @function task за допомогою @function print
 */
 
int insert(char * s1, char *s2, int num);
int reduce(char *s, int start, int end);

void add_struct(struct bird * types, int n);
void remove_struct(struct bird * types, int n);

#endif
