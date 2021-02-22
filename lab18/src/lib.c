/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Yaylo D.
 * @date 15-feb-2021
 * @version 1.0
 */
 
#include "lib.h"

int insert(char * s1, char *s2, int num){
	num--;
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int a = sizeof(char);
	char *result_str = (char*)malloc(sizeof(char));
	*(result_str) = memmove(result_str+1, s1, a * num);
	*(result_str) = memmove(result_str+1+num*a, s2, l2 * a);
	*(result_str) = memmove(result_str+1+(num+l2)*a , s1 + num*a, (l1-num)*a);
	printf("%s\n",result_str+1);
	*(s1)=memmove(s1, result_str, (l1+l2)*a+1);
	*(s1+l1+l2+1)=NULL;
	free(result_str);
	//return *s1;
}

int reduce(char *s, int start, int end){
	start--;
	end--;
	int l= strlen(s);
	int a = sizeof(char);
	char *result_str = (char*)malloc(sizeof(char));
	*(result_str) = memmove(result_str+1, s, a * start);
	*(result_str) = memmove(result_str+1+start*a, s + end*a, a * (l-end));
	printf("%s\n",result_str+1);
	free(result_str);
}
