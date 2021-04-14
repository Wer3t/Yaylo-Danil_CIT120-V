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
    for(int i=0;i<size;i++){
        delete[] birds[i];
    }
}

void Birds::add_bird(Basic_bird *bird, Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    birds=add_memory(birds, bird, month_away, month_arrival, ringed, species, age, square, height, num_feeders, nest, sex);
    size++;
}
Basic_bird** Birds::add_memory(Basic_bird** birds, Basic_bird *bird, Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    Basic_bird ** temp= new Basic_bird*[size+1];
    for(int i=0;i<size;i++){
        temp[i]=birds[i];
    }
    temp[size]=bird->AddBird(month_away, month_arrival, ringed, species, age, square, height, num_feeders, nest, sex);
    return temp;
}


void Birds::add_bird(Basic_bird *bird, int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    birds=add_memory(birds, bird, min_temperature, max_temperature, ringed, species, age, square, height, num_feeders, nest, sex);
    size++;
}
Basic_bird** Birds::add_memory(Basic_bird** birds, Basic_bird *bird, int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    Basic_bird ** temp= new Basic_bird*[size+1];
    for(int i=0;i<size;i++){
        temp[i]=birds[i];
    }
    temp[size]=bird->AddBird(min_temperature, max_temperature, ringed, species, age, square, height, num_feeders, nest, sex);
    return temp;
}


void Birds::print_birds(Basic_bird *bird){
    for(int i=0; i<size;i++){
        cout << "Птица №" << i << ":\n"<<birds[i]->GetBird()<<endl;
    }
}