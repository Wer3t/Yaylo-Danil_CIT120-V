#include "/home/danil/dev/Yaylo-Danil_CIT120-V/lab20/src/list.h"
#include "data.h"

unsigned short test_finder(){
    clock_t start = clock();
    DEBUG;
    D_LinkedList *list = create_list();
	int n = count_lines();
	read_file(list, n);
    int criterion=1;
    char obj[]={0};
    int crit=1;
    int result = finder(list, criterion, obj,crit);
    if(result == 0){
        printf("\nТест №1 функции по поиску обьекта в списке Успешен");
    }else{
        printf("\nТест №1 функции по поиску обьекта в списке Провален");
    }

    criterion=2;
    obj[10]="crow";
    result = finder(list, criterion, obj,crit);
    if(result == 2){
        printf("\nТест №2 функции по поиску обьекта в списке Успешен");
    }else{
        printf("\nТест №2 функции по поиску обьекта в списке Провален");
    }
    clock_t end = clock();
	double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\nВремя потраченное на выполнение теста test_finder: %lf\n", time_spent);
    deleteDbLinkedList(list);
}

int main(){
    clock_t start = clock();
    test_finder();
    clock_t end = clock();
	double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\nВремя потраченное на выполнение всех тестов: %lf\n", time_spent);
    return 0;
}