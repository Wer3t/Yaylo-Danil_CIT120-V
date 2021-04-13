#include "Exotic_bird.h"

Exotic_birds_features* Exotic_birds::add_exotic_bir(Exotic_birds_features *exotic_birds, short min, short max, std::string ringed){
    //Создание нового массива на 1 больше предыдущего
    Exotic_birds_features *temp = new Exotic_birds_features[Exotic_birds::size+1];
    //Указатели на элементы старого массива записываются в новый
    for(int i=0;i<Exotic_birds::size;i++){
        temp[i]=exotic_birds[i];
    }
    //Конструктор с аргументами из наследника
    temp[Exotic_birds::size]=Exotic_birds_features(min, max);
     //Запись элемента через прототип функции основного класса
     temp[Exotic_birds::size].SetRinged(ringed);
    Exotic_birds::size++;
    return temp;
}

void Exotic_birds::print_exotic_birds()
{
    int j=0;
    for (int i = 0; i < Exotic_birds::size; i++)
        cout << "Миграционая птица №" << i << endl;
        cout << "Окольцованна ли птица: "<< exotic_birds[j].GetRinged() << " ";
        cout << "Минимальная температура: "<< exotic_birds[j].GetMinTemp()+1 << " ";
        cout << "Максимальная температура: "<< exotic_birds[j].GetMaxTemp()+1 << " "<<endl;
        j++;
}