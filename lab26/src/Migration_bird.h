#include "lib.h"

enum Month
{
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

class Migratory_birds_features : public Bird_features{
    //Наследник класса Birds, добавляются два поля
    Month month_away;
    Month month_arrival;
public:
    Migratory_birds_features()
    {
        cout << "\nВызвался конструктор по умолчанию Migratory_birds_features" << endl;
        this->month_away=Month::SEPTEMBER;
        this->month_arrival=Month::MARCH;
    }

    //Конструктор с аргументами создает класс и заполняет входными данными
    Migratory_birds_features(Month month_away, Month month_arrival)
    {
        this->month_away=month_away;
        this->month_arrival=month_arrival;
    }

    void SetMonthAway(Month mn){
        month_away=mn;
    }
    void SetMonthArrival(Month mn){
        month_arrival=mn;
    }
    Month GetMonthAway(){
        return month_away;
    }
    Month GetMonthArrival(){
        return month_arrival;
    }
};

class Migratory_birds{
    //дополнительная функция которая возвращает ссылку на новый массив
    Migratory_birds_features* add_migratory_bir(Migratory_birds_features *migratory_birds, Month month_away, Month month_arrival, std::string ringed);
    //количество эллементов в массиве
    int size;
public:
    //создание массива
    Migratory_birds_features *migratory_birds = new Migratory_birds_features[0];

    Migratory_birds(){
        size=0;
    }
    Migratory_birds(const Migratory_birds &other){
        this->migratory_birds = other.migratory_birds;
        for(int i=0;i<Migratory_birds::size;i++){
            this->migratory_birds[i]=other.migratory_birds[i];
        }
        cout << "\nВызвался конструктор копирования Migratory_birds" << endl;
    }

    //Деструктор очищает выделенную память 
    ~Migratory_birds()
    {
        cout << "\nВызвался деструктор Migratory_birds" << endl;
        delete[] migratory_birds;
    }

    void add_migratory_bird(Month month_away, Month month_arrival, std::string ringed){
        migratory_birds=add_migratory_bir(migratory_birds, month_away, month_arrival, ringed);
    }
    void print_migratory_birds();
};

