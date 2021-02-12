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
 * @function input_task
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
/**
 * @function task1
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *	 @param mas Масив вказівників на числа, 
 * 	        які передаються за допомогою варівтивної функції
 *	 @param masr Масив масивів вказівників з строками,
 *	 	які утворюють безперервні послідовності чисел з не-зменшуваними значеннями.
 * - Заповнення масиву mas за допомогою варівтивної функції
 * - Перевірка на виконання умови
 * - Виписування всих ділянок, які утворюють безперервні послідовності 
 *   чисел з не-зменшуваними значеннями.
 * - Знаходження найбільшої, за сумою всих елементів, ділянки
 * - Вивід на екран результату виконання операцій
 */
int task1(char *t, int l );
/**
 * @function line
 *
 * Послідовність дій:
 * - Виписування всих ділянок, які утворюють безперервні послідовності 
 *   чисел з не-зменшуваними значеннями.
 * - Знаходження найбільшої, за сумою всих елементів, ділянки
 * - Вивід на екран результату виконання операцій
 */
void line ( int l );
/**
 * @function task2
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *	 @param mas Масив вказівників на числа, 
 * 	        які передаються за допомогою варівтивної функції
 *	 @param masr Результуючий масив вказівників 
 * - Заповнення масиву mas за допомогою варівтивної функції
 * - Знаходження всих чисел, що повторюються
 * - Виписування всих чисел, що повторюються.
 * - Вивід на екран результату виконання операцій
 */
void task2();
/**
 * @function task
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *	 @param mas Масив вказівників на числа, 
 * 	        які передаються за допомогою варівтивної функції
 *	 @param masr Результуючий масив вказівників 
 * - Заповнення масиву mas за допомогою варівтивної функції
 * - З- Заповнення масиву mas за допомогою варівтивної функції
 * - Знаходження всих чисел, що повторюються
 * - Виписування всих чисел, що повторюються.
 * - Заповнення масиву mas за допомогою варівтивної функції
 * - Знаходження всих чисел, що повторюються
 * - Виписування всих чисел, що повторюються.
 */
void task(char * str_res, double * res , char str[],int N);

/**
 * @function print
 *
 * Послідовність дій:
 * - Виведення результату роботи @function task
 */
 
void print(char * str_res, double * res ,int N,char str[]);

#endif