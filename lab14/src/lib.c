/**
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Yaylo D.
 * @date 13-dec-2020
 * @version 1.0
 */
 
#include "lib.h"

char input_func(char * str){
	printf("Введите имя файла: ");
	char file_name[20];
	char correct_name[]="input.txt";
	scanf("%s",file_name);
	if(strcmp(correct_name, file_name)!=0){
		printf("\nНеверное имя файла\n");
		exit(0);
	}

	FILE *input;
	input= fopen("input.txt","r");
	fscanf(input,"%s",str);
	fclose(input);
}

void task(char * str_res, double * res , char str[],int N){
    char *ch;
    int kol=0;
    char *symbol;
    
    for(int i=0;*(str+i)!='\0';i++){
        kol=0;
        symbol=*(str+i);
            while(ch=strchr(str, symbol)){
                kol++;
                for (int k=ch-str;k<N;k++){ 
                    *(str+k)=*(str+k+1);
                } 
            }
        *(str_res + i)=symbol;
        *(res+i)=(double)kol/(double)N;
    }
   
    
}

void print(char * str_res, double * res ,int N,char str[]){
    FILE *output;
    output= fopen("output.txt", "w");
    fprintf(output,"%s\n",str_res);

    for(int i=0;*(res+i)!=0;i++){
        fprintf(output,"%lf ",*(res+i));
    }
   
    fclose(output);
}


int task1(char *t, int l ){

	int end;
    char text[100];

    if ( l == 0 ){
    	scanf("%s", text );
    	t = text;
    }

    struct stat statbuf;

    DIR *d = opendir( t );

    struct dirent *dp;

    int dfd, ffd;

    if ((d = fdopendir((dfd = open( t, O_RDONLY)))) == NULL) {
        fprintf(stderr, "Cannot open %s directory\n", t);
        return 1;
    }

    line(l);
    printf("%s\n", t );

    while ((dp = readdir(d)) != NULL){
        if (dp->d_name[0] == '.')
            continue;


        if ((ffd = openat(dfd, dp->d_name, O_RDONLY)) == -1) {
            perror(dp->d_name);
            continue;
        }

        if (fstat(ffd, &statbuf) == 0 && (statbuf.st_mode & S_IFDIR)) {          
            end = strlen(t);

            strcat ( t, "/" );
            strcat ( t, dp->d_name );

            task1( t, l + 1 );

    		t[end] = 0;
        }
        else{
        	line(l + 1);
        	printf("%s\n", dp->d_name );
        }

        close(ffd);
    }

    closedir(d);



    return 0;

}

void line ( int l ){
	for ( int i = 0; i < l; i++){
		printf(i == l - 1 ? "├── " : "│   ");
	}
}

void task2(){
	struct stat statbuf;
	FILE *stream;
	if((stream= fopen("output.txt","r")) == NULL){
		fprintf(stderr,"\nНе могу открыть файл\n");
		return 0;
	}
	
	fflush(stream);
	fstat(fileno(stream),&statbuf);
	
	printf("\nРазмер в байтах: %ld\n", statbuf.st_size);
	
	fclose(stream);
}
