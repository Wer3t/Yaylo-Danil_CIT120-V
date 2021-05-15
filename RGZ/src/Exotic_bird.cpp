#include <string>
#include "Exotic_bird.h"


Exotic_bird::Exotic_bird():Basic_bird(){
    this->min_temperature=5;
    this->max_temperature=40;
}

void Exotic_bird::SetMinTemperature(int min){
    this->min_temperature=min;
}
void Exotic_bird::SetMaxTemperature(int max){
    this->max_temperature=max;
}
int Exotic_bird::GetMinTemperature(){
    return min_temperature;
}
int Exotic_bird::GetMaxTemperature(){
    return max_temperature;
}

std::string Exotic_bird::GetBird(){
        return GetRinged()+"|"+GetSpecies()+"|"+ std::to_string(GetAge())+"|"+std::to_string(GetHouseSquare())+"|"+std::to_string(GetHouseHeight())+"|"+std::to_string(GetHouseNumFeeders())+"|"+GetHouseNest()+"|"+GetSex()+"|"+std::to_string(GetMinTemperature())+"|"+std::to_string(GetMaxTemperature());
}

Basic_bird* Exotic_bird::AddBird(int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    //Заполнение выделеннной памяти и возврат указателя на эту память
    Exotic_bird *temp = new Exotic_bird[1];
    temp->SetRinged (ringed);
    temp->SetSpecies (species);
    temp->SetAge(age);
    temp->SetHouseSquare(square);
    temp->SetHouseHeight(height);
    temp->SetHouseNumFeeders (num_feeders);
    temp->SetHouseNest (nest);
    temp->SetSex (sex);
    temp->SetMinTemperature(min_temperature);
    temp->SetMaxTemperature(max_temperature);
    return temp;
}

Basic_bird* Exotic_bird::AddBird(Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    return 0;
}

Basic_bird* Exotic_bird::AddBird(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    return 0;
}