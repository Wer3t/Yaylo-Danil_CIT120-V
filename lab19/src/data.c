/**a
 * @file lib.c
 * @brief Файл з реалізацією функцій.
 *
 * @author Yaylo D.
 * @date 15-feb-2021
 * @version 1.0
 */
 
#include "list.h"
#include "data.h"


int count_lines(){
	/*Подсчёт количества строк в файле, что бы понимать сколько структур будет*/
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


void read_file(D_LinkedList *list, int n){
	
	FILE *file;
	file = fopen("input.txt", "r");
	for(int i=0;i<n;i++){
		bird *tmp=(bird *)malloc(sizeof(bird));
		if(tmp == NULL){
			exit(1);
		}
		fscanf(file, "%d",&tmp->ringed);
		fscanf(file, "%s",&tmp->species);
		fscanf(file, "%d",&tmp->age);
		fscanf(file, "%d",&tmp->house.square);
		fscanf(file, "%d",&tmp->house.height);
		fscanf(file, "%d",&tmp->house.num_feeders);
		fscanf(file, "%d",&tmp->house.nest);
		fscanf(file, "%d",&tmp->sex);
		
		tmp->next= list->head;
		tmp->prev=NULL;
		if(list->head){
			list->head->prev = tmp;
		}
		list->head = tmp;
		if(list->tail ==NULL){
			list->tail = tmp;
		}
		list->size++;
	}
	
	fclose(file);
	
}


void write_file(D_LinkedList *list){
	bird *tmp = list->tail;
	FILE *file;
	file = fopen("output.txt", "w");
	while(tmp){
		if(tmp->ringed==2){
			fprintf(file, "ringed, ");
		}else if(tmp->ringed==1){
			fprintf(file, "non ringed, ");
		}
		fprintf(file, "%s, ", tmp->species);
		fprintf(file, "%d, ", tmp->age);
		fprintf(file, "%d, ", tmp->house.square);
		fprintf(file, "%d, ", tmp->house.height);
		fprintf(file, "%d, ", tmp->house.num_feeders);
		if(tmp->house.nest==2){
			fprintf(file, "have nest, ");
		}else if(tmp->house.nest==1){
			fprintf(file, "haven't nest, ");
		}
		if(tmp->sex==2){
			fprintf(file, "male");
		}else if(tmp->sex==1){
			fprintf(file, "female");
		}
		fprintf(file, "\n");
		tmp = tmp->prev;
	}
	fclose(file);
}

void write_out(D_LinkedList *list){
	printf("\n");
	bird *tmp = list->tail;
	while(tmp){
		if(tmp->ringed==2){
			printf("ringed, ");
		}else if(tmp->ringed==1){
			printf("non ringed, ");
		}
		printf("%s, ", tmp->species);
		printf("%d, ", tmp->age);
		printf("%d, ", tmp->house.square);
		printf("%d, ", tmp->house.height);
		printf("%d, ", tmp->house.num_feeders);
		if(tmp->house.nest==2){
			printf("have nest, ");
		}else if(tmp->house.nest==1){
			printf("haven't nest, ");
		}
		if(tmp->sex==2){
			printf("male");
		}else if(tmp->sex==1){
			printf("female");
		}
		printf("\n");
		tmp = tmp->prev;
	}
}

bird* getNth(D_LinkedList *list, size_t index){
	bird *tmp = list->tail;
	size_t i = 0;
	
	while(tmp && i<index){
		tmp = tmp->prev;
		i++;
	}
	return tmp;
}

void insert(D_LinkedList *list, int to_add){
	bird *ins=(bird *)malloc(sizeof(bird));
	bird *elm=getNth(list, to_add);
	if(elm == NULL){
		exit(1);
	}
	
	ins->ringed= rand()%3+1;
	sprintf(ins->species,"bird %d",list->size+1);;
	ins->age= rand()%50;
	ins->house.square= rand()%100;
	ins->house.height= rand()%100;
	ins->house.num_feeders= rand()%10;
	ins->house.nest= rand()%3+1;
	ins->sex= rand()%3+1;
	
	ins->prev = elm;
	ins->next=elm->next;
	if(elm->next){
		elm->next->prev = ins;
	}
	elm->next=ins;
	
	if(!elm->prev){
		list->head=elm;
	}
	if(!elm->next){
		list->tail = elm;
	}
	
	list->size++;
}

void add_head(D_LinkedList *list){
	bird *tmp=(bird *)malloc(sizeof(bird));
	if(tmp == NULL){
		exit(1);
	}
	tmp->ringed= rand()%3+1;
	sprintf(tmp->species,"bird %d",list->size+1);;
	tmp->age= rand()%50;
	tmp->house.square= rand()%100;
	tmp->house.height= rand()%100;
	tmp->house.num_feeders= rand()%10;
	tmp->house.nest= rand()%3+1;
	tmp->sex= rand()%3+1;
		
	tmp->next= list->head;
	tmp->prev=NULL;
	if(list->head){
		list->head->prev = tmp;
	}
	list->head = tmp;
	if(list->tail ==NULL){
		list->tail = tmp;
	}
	list->size++;
}

void add_tail(D_LinkedList *list){
	bird *tmp=(bird *)malloc(sizeof(bird));
	if(tmp == NULL){
		exit(1);
	}
	tmp->ringed= rand()%3+1;
	sprintf(tmp->species,"bird %d",list->size+1);;
	tmp->age= rand()%50;
	tmp->house.square= rand()%100;
	tmp->house.height= rand()%100;
	tmp->house.num_feeders= rand()%10;
	tmp->house.nest= rand()%3+1;
	tmp->sex= rand()%3+1;
		
	tmp->next= NULL;
	tmp->prev=list->tail;
	if(list->tail){
		list->tail->next = tmp;
	}
	list->tail = tmp;
	if(list->head ==NULL){
		list->head = tmp;
	}
	list->size++;
}

void deleteNth(D_LinkedList *list, int to_delete){
	bird *elm=NULL;
	void *tmp=NULL;
	elm=getNth(list, to_delete);
	if(elm==NULL){
		exit(1);
	}
	if(elm->prev){
		elm->prev->next = elm->next;
	}
	if(elm->next){
		elm->next->prev = elm->prev;
	}
	
	if(!elm->prev){
		list->head = elm->next;
	}
	if(!elm->next){
		list->tail= elm->prev;
	}
	free(elm);
	list->size--;
}

void sorting(D_LinkedList *list, int criterion){
	switch(criterion){
		case 1:
			sort_yn(list, criterion);
			break;
		case 2:
			sort_abc(list, criterion);
			break;
		case 3:
			sort_increase(list, criterion);
			break;
		case 4:
			sort_increase(list, criterion);
			break;
		case 5:
			sort_increase(list, criterion);
			break;
		case 6:
			sort_increase(list, criterion);
			break;
		case 7:
			sort_yn(list, criterion);
			break;
		case 8:
			sort_yn(list, criterion);
			break;
	}
}

void sort_abc(D_LinkedList *list, int criterion){
	bird *tmp = list->tail;
	int n=0;
	int k=list->size;
	for(int i=0;i<k;i++){
		list->tail = tmp;
		n=0;
		for(int j=0;j<k-i;j++){
			if(strcmp(list->tail->species,list->tail->prev->species)>0){
				if(n==0){
					tmp=list->tail->prev;
					bird *temp=list->tail;
					list->tail=list->tail->prev;
					list->tail->prev=temp;
					//list->tail->next==NULL;
					n++;
				}else{
				bird *temp=list->tail;
				list->tail=list->tail->prev;
				list->tail->prev=temp;
				n++;
				}
			}
		}
	}
	list->tail = tmp;
}

void sort_yn(D_LinkedList *list, int criterion){
	bird *tmp = list->tail;
	bird *tmp_result = list->tail;
	if(criterion==1){
		for(int i=0;i<list->size;i++){
			if(tmp->ringed==2){
				tmp_result=tmp;
				tmp_result=tmp_result->prev;
			}
			tmp=tmp->prev;
		}
		tmp = list->tail;
		for(int i=0;i<list->size;i++){
			if(tmp->ringed==1){
				tmp_result=tmp;
				tmp_result=tmp_result->prev;
			}
			tmp=tmp->prev;
		}
		for(int i=0;i<list->size;i++){
			list->head=tmp_result;
			list->head=list->head->next;
			tmp_result=tmp_result->next;
		}
	} else if(criterion==7){
		for(int i=0;i<list->size;i++){
		if(tmp->house.nest==2){
			tmp_result=tmp;
			tmp_result=tmp_result->prev;
		}
		tmp=tmp->prev;
		}
		tmp = list->tail;
		for(int i=0;i<list->size;i++){
			if(tmp->house.nest==1){
				tmp_result=tmp;
				tmp_result=tmp_result->prev;
			}
			tmp=tmp->prev;
		}
		/*for(int i=0;i<list->size;i++){
			list->head=tmp_result;
			list->head=list->head->next;
			tmp_result=tmp_result->next;
		}*/
	} else if(criterion==8){
		for(int i=0;i<list->size;i++){
		if(tmp->sex==2){
			tmp_result=tmp;
			tmp_result=tmp_result->prev;
		}
		tmp=tmp->prev;
		}
		tmp = list->tail;
		for(int i=0;i<list->size;i++){
			if(tmp->sex==1){
				tmp_result=tmp;
				tmp_result=tmp_result->prev;
			}
			tmp=tmp->prev;
		}
		/*for(int i=0;i<list->size;i++){
			list->head=tmp_result;
			list->head=list->head->next;
			tmp_result=tmp_result->next;
		}*/
	}
	
}

void sort_increase(D_LinkedList *list, int criterion){
	bird *tmp = list->tail;
	if(criterion==3){
		for(int i=0;i<list->size;i++){
			tmp = list->tail;
			for(int j=0;j<list->size-i;j++){
				if(tmp->age>tmp->next->age){
				bird *temp;
				temp=tmp;
				tmp=tmp->prev;
				tmp->prev=temp;
				}
				tmp=tmp->prev;
				tmp->prev=tmp->prev->prev;
			}
		}
	} else if(criterion==4){
		for(int i=0;i<list->size;i++){
			tmp = list->tail;
			for(int j=0;j<list->size-i;j++){
				if(tmp->house.square>tmp->next->house.square){
					bird *temp;
					temp=tmp;
					tmp=tmp->prev;
					tmp->prev=temp;
				}
				tmp=tmp->prev;
				tmp->prev=tmp->prev->prev;
			}
		}
	} else if(criterion==5){
		for(int i=0;i<list->size;i++){
			tmp = list->tail;
			for(int j=0;j<list->size-i;j++){
				if(tmp->house.height>tmp->next->house.height){
					bird *temp;
					temp=tmp;
					tmp=tmp->prev;
					tmp->prev=temp;
				}
				tmp=tmp->prev;
				tmp->prev=tmp->prev->prev;
			}
		}
	} else if(criterion==6){
		for(int i=0;i<list->size;i++){
			tmp = list->tail;
			for(int j=0;j<list->size-i;j++){
				if(tmp->house.num_feeders>tmp->next->house.num_feeders){
					bird *temp;
					temp=tmp;
					tmp=tmp->prev;
					tmp->prev=temp;
				}
				tmp=tmp->prev;
				tmp->prev=tmp->prev->prev;
			}
		}
	}
	
	/*for(int i=0;i<list->size;i++){
		list->head=tmp;
		list->head=list->head->next;
		tmp=tmp->next;
	}*/
}
