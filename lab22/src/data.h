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
 
void read_list(D_LinkedList *list, regex_t regex, int reti, int n);

void write_out(D_LinkedList *list, regex_t regex, int reti);

int count_lines();
#endif
