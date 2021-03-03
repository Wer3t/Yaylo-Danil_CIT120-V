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
	*(s1)=memmove(s1, result_str, (l1+l2)*a);
	*(s1+l1+l2+1)=NULL;
	free(result_str);
}

int reduce(char *s, int start, int end){
	start--;
	end--;
	int l= strlen(s);
	int a = sizeof(char);
	char *result_string = (char*)malloc(sizeof(char));
	*(result_string) = memmove(result_string+1, s, a * start);
	*(result_string) = memmove(result_string+1+start*a, s + end*a, a * (l-end));
	*(s)=memmove(s,result_string,  a*(start+l-end));
	printf("%s\n",result_string+1);
	free(result_string);
}

void add_struct(struct bird * types, int n){
	struct bird *add=(struct bird*)malloc(sizeof(struct bird));
		add->ringed= rand()%2;
		sprintf(add->species,"bird %d",n+1);;
		add->age= rand()%50;
		add->house.square= rand()%100;
		add->house.height= rand()%100;
		add->house.num_feeders= rand()%10;
		add->house.nest= rand()%2;
		add->sex= rand()%2;
	memmove(types+n, add, sizeof(struct bird));
}


void remove_struct(struct bird * types, int n){
	printf("\nВведите номер структуры, которую нужно удалить(0-%d): \n", n-1);
	int to_remove;
	scanf("%d", &to_remove);
	memset(types+to_remove, ' ', sizeof(struct bird));
	for(int i=to_remove;i<n;i++){
		memmove(types+i, types+i+1, sizeof(struct bird));
	}
}
