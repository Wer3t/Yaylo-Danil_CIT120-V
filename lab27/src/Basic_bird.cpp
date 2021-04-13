#include "Basic_bird.h"

Basic_bird::Basic_bird(){
    cout << "\nВызвался конструктор по умолчанию Basic_birds" << endl;
        this->ringed = "default";
        this->species = " ";
        this->age = 0;
        this->house.square = 0;
        this->house.height = 0;
        this->house.num_feeders = 0;
        this->house.nest = " ";
        this->sex = " ";
}
Basic_bird::Basic_bird(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
    cout << "\nВызвался конструктор с аргументами Basic_bird" << endl;
        this->ringed = ringed;
        this->species = species;
        this->age = age;
        this->house.square = square;
        this->house.height = height;
        this->house.num_feeders = num_feeders;
        this->house.nest = nest;
        this->sex = sex;
}
Basic_bird::Basic_bird(const Basic_bird &other){
        this->ringed = other.ringed;
        this->species = other.species;
        this->age = other.age;
        this->house.square = other.house.square;
        this->house.height = other.house.height;
        this->house.num_feeders = other.house.num_feeders;
        this->house.nest = other.house.nest;
        this->sex = other.sex;

    cout << "\nВызвался конструктор копирования Basic_bird" << endl;
}

void Basic_bird::SetRinged(std::string ringed){
    this->ringed=ringed;
}
void Basic_bird::SetSpecies(std::string species){
    this->species=species;
}
void Basic_bird::SetAge(int age){
    this->age=age;
}
void Basic_bird::SetHouseSquare(int square){
    this->house.square=square;
}
void Basic_bird::SetHouseHeight(int height){
    this->house.height=height;
}
void Basic_bird::SetHouseNumFeeders(int num_feeders){
    this->house.num_feeders=num_feeders;
}
void Basic_bird::SetHouseNest(std::string nest){
    this->house.nest=nest;
}
void Basic_bird::SetSex(std::string sex){
    this->sex=sex;
}


std::string Basic_bird::GetRinged(){
    return ringed;
}
std::string Basic_bird::GetSpecies(){
    return species;
}
int Basic_bird::GetAge(){
    return age;
}
int Basic_bird::GetHouseSquare(){
    return house.square;
}
int Basic_bird::GetHouseHeight(){
    return house.height;
}
int Basic_bird::GetHouseNumFeeders(){
    return house.num_feeders;
}
std::string Basic_bird::GetHouseNest(){
    return house.nest;
}
std::string Basic_bird::GetSex(){
    return sex;
}