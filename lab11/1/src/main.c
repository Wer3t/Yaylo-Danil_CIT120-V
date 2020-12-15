/**
 * @mainpage
 * # Загальне завдання
 * 1. Дано масив з N цілих чисел. **Визначити**, чи є в масиві елементи, що повторюються
 * @author Yaylo D.
 * @date 29-nov-2020
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури та методів
 * оперування ним.
 *
 * @author Yaylo D.
 * @date 29-nov-2020
 * @version 1.0
 */

#include "stdio.h"
#include "stdarg.h"

int task(int N, ...);

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - вивід результату роботи функції @function task
 * @return успішний код повернення з програми (0)
 */
int main() {
    task(11, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4);
    return(0);
}

/**
 * @function task
 *
 * Послідовність дій:
 * - оголошеня змінних 
 *	 @param mas Масив вказівників на числа, 
 * 	        які передаються за допомогою варівтивної функції
 *	 @param masr Результуючий масив вказівників 
 * - Заповнення масиву mas за допомогою варівтивної функції
 * - Знаходження всих чисел, що повторюються
 * - Виписування всих чисел, що повторюються.
 * - Вивід на екран результату виконання операцій
 */
int task(int N, ...){
    va_list args;/**Початок роботи з варіативними аргументами */
    va_start(args, N);
    int *mas = (int*)calloc(N, sizeof(int));
    int kol, a=0;
    int *masr= (int*)calloc(N*N, sizeof(int));
    for(int i=0;i<N*N;i++){
        *(masr+i)=0;
    }
    int *p;
    
    /**Заповнення масиву числами*/
    for (int i =0; i<N; i++){
        int value = va_arg(args, int);
        *(mas+i)=value;
    }

    for(int i=0;i<N-a;i++){
        kol=0;
            for(int j=0; j<N-a;j++){
                if(i==j){
                    j++;
                    kol++;
                }
                if(*(mas+i)==*(mas+j)){
                    kol++;
                    for (int k=j;k<N;k++){ //движение по элементам строки и их перестановка
                               *(mas+k)=*(mas+k+1);
                          } 
                          a++;
                          j--;
                }
            }
        
        p=&kol;
        if(*(masr+i)==0){
            *(masr+i)=*(mas+i);
            *(masr+i+1)=*p;
        } else {
            int k = i;
            while(*(masr+k)!=0){
                k++;
            }
            *(masr+k)=*(mas+i);
            *(masr+k+1)=*p;
        }
    }
    printf("\n");
    for(int i=0;*(masr+i)!=0;i++){
        printf("%d ", *(masr+i));
    }
    va_end(args);
    free(mas);
    free(masr);
}
