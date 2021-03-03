/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Yaylo D.
 * @date 15-feb-2021
 * @version 1.0
 */
 
#include "list.h"

D_LinkedList* create_list(){
	/*Создаю указатели на начало и конец списка*/
	D_LinkedList *tmp=(D_LinkedList*)malloc(sizeof(D_LinkedList));
	tmp->size=0;
	tmp->head = tmp->tail = NULL;
	
	return tmp;
}


