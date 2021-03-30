#ifndef _YAYLO_13_
#define _YAYLO_13_

#define DEBUG printf("\nТекущая дата: %s, текущее время: %s, функция: %s\n", __DATE__, __TIME__, __FUNCTION__);

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
 * @function count_lines
 *
 * Послідовність дій:
 * 	@param filename  Вказівник на ім'я файлу, який необхідно відкрити 
 * 	@param lines_count  Кількість строк у файлі 
 * - Цикл для визначення зустрічання символу [\n] і занесення результату у зміну
 * - вивід результату роботи функції count_lines назад у функцію з якої викликалася
 */
 
int count_lines(char *filename);

/**
 * @function read_file
 *
 * Послідовність дій:
 *  @param filename  Вказівник на ім'я файлу, який необхідно відкрити 
 * 	@param types Масив структур створених за шаблоном
 * 	@param n  Кількість структур у масиві
 * - Цикл заповнення масиву структур даними з файлу
 */
void read_file(struct bird types[], int n, char *filename);
/**
 * @function write_file
 *
 * Послідовність дій:
 * 	@param filename  Вказівник на ім'я файлу, у який необхідно записати масив структур 
 * 	@param types Масив структур створених за шаблоном
 * 	@param n  Кількість структур у масиві
 * - Цикл запису у файл масиву структур зі зміною деяких цифр на текст
 */
void write_file(struct bird types[], int n, char *filename);
/**
 * @function write_out
 *
 * Послідовність дій:
 * 	@param types Масив структур створених за шаблоном
 * 	@param n  Кількість структур у масиві
 * - Цикл запису у консоль масиву структур зі зміною деяких цифр на текст
 */
void write_out(struct bird types[], int n);

/**
 * @function percent_male_to_female
 *
 * Послідовність дій:
 * - оголошеня змінних 
 * 	@param male  Кількість чоловічих особин у масиві структур
 * 	@param female  Кількість жіночих особин у масиві структур
 * 	@param percent_male  Відсоткове відношення чоловічих особин до загальної кількості
 *  @param percent_female  Відсоткове відношення жіночих особин до загальної кількості
 * - Цикл для визначення зустрічання чоловічих або жіночих особин і занесення результату у результуючі змінні
 */

double percent_male_to_female(struct bird types[], int n);


#endif
