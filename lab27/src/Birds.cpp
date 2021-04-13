#include "Birds.h"

Birds::Birds(){
    size=0;
    birds = new Basic_bird*[1];
}

Birds::Birds(const Birds &other){
        this->birds = other.birds;
        for(int i=0;i<Birds::size;i++){
            this->birds[i]=other.birds[i];
        }
        cout << "\nВызвался конструктор копирования Birds" << endl;
}

Birds::~Birds()
{
    cout << "\nВызвался деструктор Birds" << endl;
    delete[] birds;
}

/*void Birds::add_bird(Basic_bird *bird, Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    birds[size]=bird->AddBird(month_away, month_arrival, ringed, species, age, square, height, num_feeders, nest, sex);
    size++;
}*/

void Birds::add_bird(Basic_bird *bird, int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    birds[size]=bird->AddBird(min_temperature, max_temperature, ringed, species, age, square, height, num_feeders, nest, sex);
    size++;
}

void Birds::print_birds(Basic_bird *bird){
    for(int i=0; i<size;i++){
        cout << "Птица №" << i << ":\n"<<bird->GetBird()<<endl;
    }
}