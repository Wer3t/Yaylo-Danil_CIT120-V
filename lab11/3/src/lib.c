/**
 * @file lib.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Yaylo D.
 * @date 13-dec-2020
 * @version 1.0
 */

#include "lib.h"

void task(char str[],int N){
	char *str_res= (char *)calloc(N, sizeof(char));
	double *res= (double *)calloc(N, sizeof(double));
	
	char *ch;
	int kol=0;
	char *symbol;
	
	for(int i=0;*(str+i)!='\0';i++){
		kol=0;
		symbol=*(str+i);
            while(ch=strchr(str, symbol)){
            	kol++;
            	for (int k=ch-str;k<N;k++){ //движение по элементам строки и их перестановка
                	*(str+k)=*(str+k+1);
                } 
            }
        *(str_res + i)=symbol;
        *(res+i)=(double)kol/(double)N;
        
    }
        
	
	print((char*)str_res, (double*) res, N);
	free(res);
	free(str_res);
}

void print(char * str_res, double * res ,int N){
	for(int i=0;*(str_res+i)!='\0';i++){
		printf("%c ", *(str_res+i));
	}
	printf("\n");
	for(int i=0;*(res+i)!=0;i++){
		printf("%f ", *(res+i));
	}
}
