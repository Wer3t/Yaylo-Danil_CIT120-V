#include "Migration_bird.h"

Migratory_birds_features* Migratory_birds::add_migratory_bir(Migratory_birds_features *migratory_birds, Month month_away, Month month_arrival, std::string ringed){
    //Создание нового массива на 1 больше предыдущего
    Migratory_birds_features *temp = new Migratory_birds_features[Migratory_birds::size+1];
    //Указатели на элементы старого массива записываются в новый
    for(int i=0;i<Migratory_birds::size;i++){
        temp[i]=migratory_birds[i];
    }
    //Конструктор с аргументами из наследника
    temp[Migratory_birds::size]=Migratory_birds_features(month_away, month_arrival);
     //Запись элемента через прототип функции основного класса
     temp[Migratory_birds::size].SetRinged(ringed);
    Migratory_birds::size++;
    return temp;
}

void Migratory_birds::print_migratory_birds()
{
    int j=0;
    for (int i = 0; i < Migratory_birds::size; i++)
        cout << "Миграционая птица №" << i << endl;
        cout << "Окольцованна ли птица: "<< migratory_birds[j].GetRinged() << " ";
        cout << "Месяц отлёта: "<< migratory_birds[j].GetMonthAway()+1 << " ";
        cout << "Месяц прилёта: "<< migratory_birds[j].GetMonthArrival()+1 << " "<<endl;
        j++;
}

