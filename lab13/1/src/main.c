//Визначити, скільки у тексті слів (без використання ітерації по кожному символу у циклу). Видати слова за абеткою

#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#define N 20

void word(char str[N]);


int main() {
	
    char str[N]="";
    printf("Введите строку: ");
    fgets(str,N, stdin);
    printf("Вы ввели: ");
    puts(str);
    word(str);
    return(0);
}


void word(char str[N]){
   char **str_res= (char **)calloc(N, sizeof(char *));
	for(int i=0;i<N;i++){
		str_res[i] = (char*)calloc(N, sizeof(char));
	}
	int slova =0,stop=0;
	char *s;
	char *f;
	char *end=strchr(str, '\0');
		s = strchr(str, ' ');
		if(s==NULL){
			for(int j=0;*(str+j)!='\0';j++){
				*(*(str_res)+j)=*(str+j);
			}
			for(int i=0;i<N;i++){
				for(int p=0;p<N;p++){
				printf("%c", *(*(str_res+i)+p));
				}
				printf("\n");
			}
			return 0;
		}
		
		*(str+(s-str))='_';
		
		if(s-str!=0){
			for(int j=0;j<s-str;j++){
				*(*(str_res+slova)+j)=*(str+j);
			}
			slova++;
		}
		
		f = strchr(str, ' ');
		if(f==NULL){
			int k=0;
			for(int j=s-str+1;j<end-str;j++){
				*(*(str_res+slova)+k)=*(str+j);
				k++;
			}
			for(int i=0;i<N;i++){
				for(int p=0;p<N;p++){
					printf("%c", *(*(str_res+i)+p));
				}
				printf("\n");
			}
			return 0;
		}
	while(stop<1){
		if(f==NULL){
			if(s-str!=end-str){
			int k=0;
			for(int j=s-str+1;j<end-str;j++){
				*(*(str_res+slova)+k)=*(str+j);
				k++;
			}
			break;
			}else{
				break;
			}
		}
		if(f-s==1){
			s=f;
			*(str+(s-str))='_';
			f = strchr(str, ' ');
		} else{
			int k=0;
			for(int j=s-str+1;j<f-str;j++){
				*(*(str_res+slova)+k)=*(str+j);
				k++;
			}
			s=f;
			*(str+(s-str))='_';
			f = strchr(str, ' ');
			slova++;
		}
		
	}	
	for(int i=0;i<N;i++){
		for(int p=0;p<N;p++){
			printf("%c", *(*(str_res+i)+p));
		}
		printf("\n");
	}
    
}
/*void sort(char ** str_res){
	char *mas = (char*)calloc(N, sizeof(char));
	for(int i=0; i<N-1;i++){
		
			if(strcmp(*(*(str_res+i)), *(*(str_res+i+1))) > 0){
				for(int k=0; *(*(str_res+i+1)+k)!=0;k++){
					*(mas+k)=*(*(str_res+i+1)+k);
				}
				for(int k=0; *(*(str_res+i)+k)!=0;k++){
					*(*(str_res+i+1)+k)=*(*(str_res+i)+k);
				}
				for(int k=0; *(mas+k)!=0;k++){
					*(*(str_res+i)+k)=*(mas+k);
				}
			
		}
	}
	
}*/
