/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Yaylo D.
 * @date 15-feb-2021
 * @version 1.0
 */
 
#include "./src/lib.h"

unsigned short test_insert(){
	char expected_str[]="tetext2xt1";
	
	char str1[]="text1";
	char *s1 = (char*)malloc(sizeof(char));
	s1=&str1;
	
	char str2[]="text2";
	char *s2 = (char*)malloc(sizeof(char));
	s2=&str2;
	
	insert((char *) s1,(char *) s2,3);
	
	if(strcmp(s1, expected_str)==0){
		printf("\nTest: insert() successful\n");
	}else{
		printf("\nTest: insert() failed\n");
	}
}

unsigned short test_reduce(){
	char expected_str[]="text";
	char str[]="tetextxt";
	char *s = (char*)malloc(sizeof(char));
	s=&str;
	reduce((char *) s,3,7);
	
	if(strcmp(s, "text")==0){
		printf("\nTest: reduce() successful\n");
	}else{
		printf("\nTest: reduce() failed\n");
	}
}

unsigned short test_add_struct(struct bird * types,int n){
	
	add_struct((struct bird *)types, n);
	
	if(types[n].species!=NULL){
		printf("\nTest: add_struct() successful\n");
	}else{
		printf("\nTest: add_struct() failed\n");
	}
}

unsigned short test_remove_struct(struct bird * types, int n){
	
	remove_struct((struct bird *)types, n);
	
	if(types[n].ringed==NULL){
		printf("\nTest: remove_struct() successful\n");
	}else{
		printf("\nTest: remove_struct() failed\n");
	}
}

int main(){
	test_insert();
	test_reduce();
	int n=3;
	struct bird *types = (struct bird*)malloc(sizeof(struct bird));
	for(int i=0;i<n;i++){
		types[i].ringed= rand()%2;
		sprintf(types[i].species,"bird %d",i+1);;
		types[i].age= rand()%50;
		types[i].house.square= rand()%100;
		types[i].house.height= rand()%100;
		types[i].house.num_feeders= rand()%10;
		types[i].house.nest= rand()%2;
		types[i].sex= rand()%2;
	}
	test_add_struct((struct bird *)types, n);
	test_remove_struct((struct bird *)types, n);
	return 0;
}


