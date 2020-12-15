
#include "stdio.h"
#include "stdarg.h"
#include "string.h"

void task(char str[], int N);


int main() {
	char str[]="Ivanov,Petrov,Ivanov";
	int N=0;
	for(int i=0;*(str+i)!='\0';i++){
		N++;
	}
	task(str, N);
}


void task(char str[], int N){
	int stop=0;
	char *povtor;
	char surname[N];
	char *copy;
	char *s = strchr(str, ',');
	strncpy(surname, str, s-str);
	while(stop<1){
		strcpy(copy, str+(s-str+1));
		char *f=strchr(copy, ',');
		if(povtor=strstr(surname, copy)>0){
			for(int i=s-str+1; i<(f-copy+1)+(s-str);i++){
				*(str+i)=' ';
			}
		}
		s = strchr(str, ',');
		strncpy(surname, str+(f-copy), s-str);
	}
	
	for(int i=0; *(str+i)!='\0';i++){
		printf("%c", *(str+i));
	}
}
