#include "lib.h"

class Exotic_birds_features : public Bird_features{
    short min_temperature;
    short max_temperature;
    
public:
    Exotic_birds_features(){
        this->min_temperature=5;
        this->max_temperature=40;
    }
    Exotic_birds_features(short min, short max){
        this->min_temperature=min;
        this->max_temperature=max;
    }
    void SetMinTemp(short min_temperature){
        this->min_temperature=min_temperature;
    }
    void SetMaxTemp(short max_temperature){
        this->max_temperature=max_temperature;
    }
    short GetMinTemp(){
        return min_temperature;
    }
    short GetMaxTemp(){
        return max_temperature;
    }
};

class Exotic_birds{
    //дополнительная функция которая возвращает ссылку на новый массив
    Exotic_birds_features* add_exotic_bir(Exotic_birds_features *exotic_birds, short min, short max, std::string ringed);
    //количество эллементов в массиве
    int size;
public:
    //создание массива
    Exotic_birds_features *exotic_birds = new Exotic_birds_features[0];

    Exotic_birds(){
        size=0;
    }
    Exotic_birds(const Exotic_birds &other){
        this->exotic_birds = other.exotic_birds;
        for(int i=0;i<Exotic_birds::size;i++){
            this->exotic_birds[i]=other.exotic_birds[i];
        }
        cout << "\nВызвался конструктор копирования Exotic_birds" << endl;
    }

    //Деструктор очищает выделенную память
    ~Exotic_birds()
    {
        cout << "\nВызвался деструктор Exotic_birds" << endl;
        delete[] exotic_birds;
    }

    void add_exotic_bird(short min, short max, std::string ringed){
        exotic_birds=add_exotic_bir(exotic_birds, min, max, ringed);
    }
    
    void print_exotic_birds();
};