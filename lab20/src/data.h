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

#include "list.h"

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

int count_lines(); 
 
void read_file(D_LinkedList *list, int n);
void write_file(D_LinkedList *list);
void write_out(D_LinkedList *list);

bird* getNth(D_LinkedList *list, size_t index);

void insert(D_LinkedList *list, int to_add);
void add_head(D_LinkedList *list);
void add_tail(D_LinkedList *list);

void deleteNth(D_LinkedList *list, int to_delete);

int finder(D_LinkedList *list, int criterion, char obj[]);
void switch_finder(D_LinkedList *list, int criterion);

void sorting(D_LinkedList *list, int criterion);
void sort_abc(D_LinkedList *list, int criterion);
void sort_yn(D_LinkedList *list, int criterion);
void sort_increase(D_LinkedList *list, int criterion);

#endif
