/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Yaylo D.
 * @date 15-feb-2021
 * @version 1.0
 */
 
#include "lib.h"

int count_lines(){
	int lines_count=0;
	FILE *file;
	file = fopen("input.txt", "r");
	while(! feof(file)){
		if(fgetc(file)=='\n'){
			lines_count++;
		}
	}
	fclose(file);
	return lines_count;
}

void read_file(struct bird types[], int n){
	FILE *file;
	file = fopen("input.txt", "r");
	for(int i=0;i<n;i++){
		fscanf(file, "%d",&types[i].ringed);
		fscanf(file, "%s",&types[i].species);
		fscanf(file, "%d",&types[i].age);
		fscanf(file, "%d",&types[i].house.square);
		fscanf(file, "%d",&types[i].house.height);
		fscanf(file, "%d",&types[i].house.num_feeders);
		fscanf(file, "%d",&types[i].house.nest);
		fscanf(file, "%d",&types[i].sex);
	}
	fclose(file);
}

void write_file(struct bird types[], int n){
	FILE *file;
	file = fopen("output.txt", "w");
	for(int i=0;i<n;i++){
		if(types[i].ringed==2){
			fprintf(file, "ringed, ");
		}else if(types[i].ringed==1){
			fprintf(file, "non ringed, ");
		}
		fprintf(file, "%s, ", types[i].species);
		fprintf(file, "%d, ", types[i].age);
		fprintf(file, "%d, ", types[i].house.square);
		fprintf(file, "%d, ", types[i].house.height);
		fprintf(file, "%d, ", types[i].house.num_feeders);
		if(types[i].house.nest==2){
			fprintf(file, "have nest, ");
		}else if(types[i].house.nest==1){
			fprintf(file, "haven't nest, ");
		}
		if(types[i].sex==2){
			fprintf(file, "male");
		}else if(types[i].sex==1){
			fprintf(file, "female");
		}
		fprintf(file, "\n");
	}
	fclose(file);
}
	
void write_out(struct bird types[], int n){
	for(int i=0;i<n;i++){
		if(types[i].ringed==2){
			printf("ringed, ");
		}else if(types[i].ringed==1){
			printf("non ringed, ");
		}
		printf("%s, ", types[i].species);
		printf("%d, ", types[i].age);
		printf("%d, ", types[i].house.square);
		printf("%d, ", types[i].house.height);
		printf("%d, ", types[i].house.num_feeders);
		if(types[i].house.nest==2){
			printf("have nest, ");
		}else if(types[i].house.nest==1){
			printf("haven't nest, ");
		}
		if(types[i].sex==2){
			printf("male");
		}else if(types[i].sex==1){
			printf("female");
		}
		printf("\n");
	}
}

void sorting(struct bird types[], int criterion, int n){
	switch(criterion){
		case 1:
			sort_yn(types, n, criterion);
			break;
		case 2:
			sort_abc(types, n, criterion);
			break;
		case 3:
			sort_increase(types, n, criterion);
			break;
		case 4:
			sort_increase(types, n, criterion);
			break;
		case 5:
			sort_increase(types, n, criterion);
			break;
		case 6:
			sort_increase(types, n, criterion);
			break;
		case 7:
			sort_yn(types, n, criterion);
			break;
		case 8:
			sort_yn(types, n, criterion);
			break;
	}
}

void sort_abc(struct bird types[], int n, int criterion){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(j+1==n){
				break;
			}else{
				char temp1[20]={0};
				char temp2[20]={0};
				sprintf(temp1,types[j].species);
				sprintf(temp2,types[j+1].species);
				if(strcmp(temp1,temp2)>0){
					sprintf(types[j].species,temp2);
					sprintf(types[j+1].species,temp1);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("\n%s", types[i].species);
	}
}

void sort_yn(struct bird types[], int n, int criterion){
	struct bird sort[n];
	int y =0;
	int no =1;
	if(criterion==1){
		for(int i=0;i<n;i++){
			if(types[i].ringed==2){
				sprintf(sort[y].species,types[i].species);
				y++;
			}else{
				sprintf(sort[n-no].species,types[i].species);
				no++;
			}
		}
	} else if(criterion==7){
		for(int i=0;i<n;i++){
			if(types[i].house.nest==2){
				sprintf(sort[y].species,types[i].species);
				y++;
			}else{
				sprintf(sort[n-no].species,types[i].species);
				no++;
			}
		}
	} else if(criterion==8){
		for(int i=0;i<n;i++){
			if(types[i].sex==2){
				sprintf(sort[y].species,types[i].species);
				y++;
			}else{
				sprintf(sort[n-no].species,types[i].species);
				no++;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		printf("\n%s", sort[i].species);
	}
}

void sort_increase(struct bird types[], int n, int criterion){
	if(criterion==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i;j++){
				if(types[j].age>types[j+1].age){
				int temp=types[j+1].age;
				int temp1=types[j].age;
				types[j].age=temp;
				types[j+1].age=temp1;
				char temp2[20]={0};
				sprintf(temp2,types[j].species);
				sprintf(types[j].species,types[j+1].species);
				sprintf(types[j+1].species,temp2);
				}
			}
		}
	} else if(criterion==4){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i;j++){
				if(types[j].house.square>types[j+1].house.square){
				int temp=types[j+1].house.square;
				int temp1=types[j].house.square;
				types[j].house.square=temp;
				types[j+1].house.square=temp1;
				char temp2[20]={0};
				sprintf(temp2,types[j].species);
				sprintf(types[j].species,types[j+1].species);
				sprintf(types[j+1].species,temp2);
				}
			}
		}
	} else if(criterion==5){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i;j++){
				if(types[j].house.height>types[j+1].house.height){
				int temp=types[j+1].house.height;
				int temp1=types[j].house.height;
				types[j].house.height=temp;
				types[j+1].house.height=temp1;
				char temp2[20]={0};
				sprintf(temp2,types[j].species);
				sprintf(types[j].species,types[j+1].species);
				sprintf(types[j+1].species,temp2);
				}
			}
		}
	} else if(criterion==6){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i;j++){
				if(types[j].house.num_feeders>types[j+1].house.num_feeders){
				int temp=types[j+1].house.num_feeders;
				int temp1=types[j].house.num_feeders;
				types[j].house.num_feeders=temp;
				types[j+1].house.num_feeders=temp1;
				char temp2[20]={0};
				sprintf(temp2,types[j].species);
				sprintf(types[j].species,types[j+1].species);
				sprintf(types[j+1].species,temp2);
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		printf("\n%s", types[i].species);
	}
}

double percent_male_to_female(struct bird types[], int n){
	double male=0, female=0;
	for(int i=0;i<n;i++){
		if(types[i].sex==1){
			male++;
		}else{
			female++;
		}
	}
	double percent_male= male/(male+female);
	double percent_female= female/(male+female);
	printf("\nПроцент мужских особей: %.2lf",percent_male);
	printf("\nПроцент женских особей: %.2lf\n\n",percent_female);
	return male;
}

int randm(){
	int ch=rand()%230+23;
	return ch;
}
int rand_2_1(){
	int ch=rand()%2+1;
	return ch;
}
void generation(){
	int n=rand()%10;
	struct bird types_r[n];
	for(int i=0; i<n; i++){
		types_r[i].ringed=rand_2_1();
		sprintf(types_r[i].species,"bird number%d", i);
		types_r[i].age=randm();
		types_r[i].house.square=randm();
		types_r[i].house.height=randm();
		types_r[i].house.num_feeders=randm();
		types_r[i].house.nest=rand_2_1();
		types_r[i].sex=rand_2_1();
	}
	write_out(types_r, n);
}

void check(p){
	if (p==NULL){
		printf("\nЭлемент структуры отсутствует");
	}
}

void read_file_bin(struct bird types[], int n){
	FILE *file;
	file = fopen("input.txt", "rb");
	for(int i=0;i<n;i++){
		fread(&types[i].ringed, 0,1,file);
		fseek(file,2,1);
		fread(&types[i].species, sizeof(char),0,file);
		fseek(file,2,1);
		fread(&types[i].age, 0,1,file);
		fseek(file,2,1);
		fread(&types[i].house.square, 0,1,file);
		fseek(file,2,1);
		fread(&types[i].house.height, 0,1,file);
		fseek(file,2,1);
		fread(&types[i].house.num_feeders, 0,1,file);
		fseek(file,2,1);
		fread(&types[i].house.nest, 0,1,file);
		fseek(file,2,1);
		fread(&types[i].sex, 0,1,file);
		fseek(file,2,1);
	}
	fclose(file);
}

void write_file_bin(struct bird types[], int n){
	FILE *file;
	file = fopen("output.dat", "wb");
	fwrite(types,sizeof(struct bird),n,file);	
	fclose(file);
}

void write_struct_number(int num){
	FILE *file;
	file = fopen("output.dat", "rb");
	struct bird result;
	fseek(file, num*sizeof(struct bird),SEEK_SET);
	fread(&result, sizeof(struct bird), 1, file);
	fclose(file);
	printf("\n\n");
	
	
	if(result.ringed==2){
		printf("ringed, ");
	}else if(result.ringed==1){
		printf("non ringed, ");
	}
	printf("%s, ", result.species);
	printf("%d, ", result.age);
	printf("%d, ", result.house.square);
	printf("%d, ", result.house.height);
	printf("%d, ", result.house.num_feeders);
	if(result.house.nest==2){
		printf("have nest, ");
	}else if(result.house.nest==1){
		printf("haven't nest, ");
	}
	if(result.sex==2){
		printf("male");
	}else if(result.sex==1){
		printf("female");
	}
}
