#include <string>
#include "Exotic_bird.h"


Exotic_bird::Exotic_bird():Basic_bird(){
    this->min_temperature=5;
    this->max_temperature=40;
}

void Exotic_bird::SetMinTemperature(short min){
    this->min_temperature=min;
}
void Exotic_bird::SetMaxTemperature(short max){
    this->min_temperature=max;
}
short Exotic_bird::GetMinTemperature(){
    return min_temperature;
}
short Exotic_bird::GetMaxTemperature(){
    return max_temperature;
}

std::string Exotic_bird::GetBird(){
        return GetRinged()+" "+GetSpecies()+" "+ std::to_string(GetAge())+" "+std::to_string(GetHouseSquare())+" "+std::to_string(GetHouseHeight())+" "+std::to_string(GetHouseNumFeeders())+" "+GetHouseNest()+" "+GetSex()+" Минимальная температура: "+std::to_string(GetMinTemperature())+" Максимальная температура: "+std::to_string(GetMaxTemperature());
}

Basic_bird* Exotic_bird::AddBird(int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    Exotic_bird *temp = new Exotic_bird[1];
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

Basic_bird* AddBird(Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){}
