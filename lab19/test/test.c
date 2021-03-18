#include "list.h"
#include "data.h"

unsigned short test_finder(){
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
}

int main(){
    test_finder();
    return 0;
}