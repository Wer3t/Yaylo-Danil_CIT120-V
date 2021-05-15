#include "List.h"

Birds::Birds(){
    
}

Birds::~Birds(){
    birds.clear();
}


vector<Basic_bird*> Birds::AddBird (Basic_bird *bird, int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){

    //Пушим в вектор указатель который вернёт функция добавления элемента из обьекта класса Exotic_bird

    birds.push_back(bird->AddBird(min_temperature, max_temperature, ringed, species, age, square, height, num_feeders, nest, sex));
}

vector<Basic_bird*> Birds::AddBird(Basic_bird *bird, Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){

    //Пушим в вектор указатель который вернёт функция добавления элемента из обьекта класса Migratory_bird

    birds.push_back(bird->AddBird(month_away, month_arrival, ringed, species, age, square, height, num_feeders, nest, sex));
}

vector<Basic_bird*> Birds::AddBird(Basic_bird *bird, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){

    //Пушим в вектор указатель который вернёт функция добавления элемента из обьекта класса Classic_bird

    birds.push_back(bird->AddBird(ringed, species, age, square, height, num_feeders, nest, sex));
}

vector<Basic_bird*> Birds::DelBird(int position)
{
    auto iter = birds.cbegin(); // указатель на первый элемент
    birds.erase(iter + position); //удаление нужного элемента
}
