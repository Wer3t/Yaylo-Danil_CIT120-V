#define DEBUG printf("\nТекущая дата: %s, текущее время: %s, функция: %s\n", __DATE__, __TIME__, __FUNCTION__);

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
#include "time.h"

struct place {
	int square;
	int height;
	int num_feeders;
	char nest;
};

typedef struct s_bird{
	char ringed;
	char species[20];
	int age;
	struct place house;
	char sex;
	struct s_bird *next;
	struct s_bird *prev;
} bird;

typedef struct DLinkedList{
	size_t size;
	bird *head;
	bird *tail;
} D_LinkedList;

/**
 * @function create_list()
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
D_LinkedList* create_list();
/**
 * @function deleteDbLinkedList()
 *
 * Послідовність дій:
 * - оголошеня змінних 
 * 	@param str_res  Результуючий масив вказівників на всі символи, які зустрічаються
 * 	@param res  Результуючий масив вказівників на частоту зустрічання символів
 * - вивід результату роботи функції @function task за допомогою @function print
 */
void deleteDbLinkedList(D_LinkedList *list);
#endif
