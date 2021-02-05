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
 
#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * @function task
 *
 * Послідовність дій:
 * - оголошеня змінних 
 * 	@param str_res  Результуючий масив вказівників на всі символи, які зустрічаються
 * 	@param res  Результуючий масив вказівників на частоту зустрічання символів
 * 	@param kol  Кількість зустрічання символу
 * - Цикл для визначення зустрічання символу [і] і занесення результату у результуючі масиви
 * - Цикл для знаходження всих повторів і їх видалення, шляхом зсуву
 * - вивід результату роботи функції @function task за допомогою @function print
 */
char input_func(char * str);

int task1(char *t, int l );
void line ( int l );

void task2();

void task(char * str_res, double * res , char str[],int N);

/**
 * @function print
 *
 * Послідовність дій:
 * - Виведення результату роботи @function task
 */
 
void print(char * str_res, double * res ,int N,char str[]);

#endif
