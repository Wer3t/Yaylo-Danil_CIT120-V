#include "Classic_bird.h"

Classic_bird::Classic_bird():Basic_bird(){}

std::string Classic_bird::GetBird(){
    return GetRinged()+"|"+GetSpecies()+"|"+ std::to_string(GetAge())+"|"+std::to_string(GetHouseSquare())+"|"+std::to_string(GetHouseHeight())+"|"+std::to_string(GetHouseNumFeeders())+"|"+GetHouseNest()+"|"+GetSex();
}

Basic_bird* Classic_bird::AddBird(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    //Заполнение выделеннной памяти и возврат указателя на эту память
    Classic_bird *temp = new Classic_bird[1];
    temp->SetRinged (ringed);
    temp->SetSpecies (species);
    temp->SetAge(age);
    temp->SetHouseSquare(square);
    temp->SetHouseHeight(height);
    temp->SetHouseNumFeeders (num_feeders);
    temp->SetHouseNest (nest);
    temp->SetSex (sex);
    return temp;
} 

Basic_bird* Classic_bird::AddBird(Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    return 0;
}

Basic_bird* Classic_bird::AddBird(int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    return 0;
}