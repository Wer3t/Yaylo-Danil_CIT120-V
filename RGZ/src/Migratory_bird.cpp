#include <string>
#include "Migratory_bird.h"


Migratory_bird::Migratory_bird():Basic_bird(){
    this->month_away=SEPTEMBER;
    this->month_arrival=APRIL;
}


void Migratory_bird::SetMonthAway(Month mn){
        month_away=mn;
}
void Migratory_bird::SetMonthArrival(Month mn){
    month_arrival=mn;
}
Month Migratory_bird::GetMonthAway(){
    return month_away;
}
Month Migratory_bird::GetMonthArrival(){
    return month_arrival;
}

std::string Migratory_bird::GetBird(){
    return GetRinged()+"|"+GetSpecies()+"|"+ std::to_string(GetAge())+"|"+std::to_string(GetHouseSquare())+"|"+std::to_string(GetHouseHeight())+"|"+std::to_string(GetHouseNumFeeders())+"|"+GetHouseNest()+"|"+GetSex()+"|"+MonthToStr(GetMonthAway())+"|"+MonthToStr(GetMonthArrival());
}

Basic_bird* Migratory_bird::AddBird(Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    //Заполнение выделеннной памяти и возврат указателя на эту память
    Migratory_bird *temp = new Migratory_bird[1];
    temp->SetRinged (ringed);
    temp->SetSpecies (species);
    temp->SetAge(age);
    temp->SetHouseSquare(square);
    temp->SetHouseHeight(height);
    temp->SetHouseNumFeeders (num_feeders);
    temp->SetHouseNest (nest);
    temp->SetSex (sex);
    temp->SetMonthAway(month_away);
    temp->SetMonthArrival(month_arrival);
    return temp;
}

Basic_bird* Migratory_bird::AddBird(int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    return 0;
}

Basic_bird* Migratory_bird::AddBird(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    return 0;
}

string Migratory_bird::MonthToStr(Month month){
    string str;
    if(month==JANUARY)
        str="JANUARY";
    if(month==FEBRUARY)
        str="FEBRUARY";
    if(month==MARCH)
        str="MARCH";
    if(month==APRIL)
        str="APRIL";
    if( month==MAY)
       str="MAY";
    if( month==JUNE)
       str="JUNE";
    if(month==JULY)
        str=="JULY";
    if(month==AUGUST)
        str="AUGUST";
    if(month==SEPTEMBER)
        str="SEPTEMBER";
    if(month==OCTOBER)
        str="OCTOBER";
    if(month==NOVEMBER)
        str="NOVEMBER";
    if(month==DECEMBER)
        str="DECEMBER";
    return str;
}