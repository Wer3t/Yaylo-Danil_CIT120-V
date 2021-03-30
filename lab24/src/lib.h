#include "stdio.h"
#include <string>
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int count_lines(std::string filename);

class Bird_features
{
    //Описание базового класса
    struct place
    {
        int square;
        int height;
        int num_feeders;
        std::string nest;
    };
    std::string ringed;
    std::string species;
    int age;
    struct place house;
    std::string sex;

public:
    //Конструктор по умолчанию создает пустой класс
    Bird_features()
    {
        cout << "\nВызвался конструктор по умолчанию" << endl;
        this->ringed = "default";
        this->species = "";
        this->age = 0;
        this->house.square = 0;
        this->house.height = 0;
        this->house.num_feeders = 0;
        this->house.nest = "";
        this->sex = "";
    }

    //Конструктор с аргументами создает класс и заполняет входными данными
    Bird_features(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex)
    {
        cout << "\nВызвался конструктор с аргументами " << endl;
        this->ringed = ringed;
        this->species = species;
        this->age = age;
        this->house.square = square;
        this->house.height = height;
        this->house.num_feeders = num_feeders;
        this->house.nest = nest;
        this->sex = sex;
    }
    

    void SetRinged(std::string ringed){
        this->ringed=ringed;
    }
    void SetSpecies(std::string species){
        this->species=species;
    }
    void SetAge(int age){
        this->age=age;
    }
    void SetHouseSquare(int square){
        this->house.square=square;
    }
    void SetHouseHeight(int height){
        this->house.height=height;
    }
    void SetHouseNumFeeders(int num_feeders){
        this->house.num_feeders=num_feeders;
    }
    void SetHouseNest(std::string nest){
        this->house.nest=nest;
    }
    void SetSex(std::string sex){
        this->sex=sex;
    }


    std::string GetRinged(){
        return this->ringed;
    }
    std::string GetSpecies(){
        return this->species;
    }
    int GetAge(){
        return this->age;
    }
    int GetHouseSquare(){
        return this->house.square;
    }
    int GetHouseHeight(){
        return this->house.height;
    }
    int GetHouseNumFeeders(){
        return this->house.num_feeders;
    }
    std::string GetHouseNest(){
        return this->house.nest;
    }
    std::string GetSex(){
        return this->sex;
    }
};

//Класс хранящий в себе динамический массив(вектор) базовых классов
class Birds
{
public:
    //Создание вектора типа Базовый класс
    std::vector <Bird_features> birds;

    Birds(){ //Конструктор по умолчанию
    }

    Birds(const Birds &other){ //Конструктор копирования
        this->birds = other.birds;
        for(int i=0;i<birds.size();i++){
            this->birds[i]=other.birds[i];
        }
        cout << "\nВызвался конструктор копирования" << endl;
    }

    //Деструктор очищает выделенную память под вектор
    ~Birds()
    {
        cout << "\nВызвался деструктор" << endl;
        birds.clear();
    }
    
    void read_file(std::string filename);

    void add_bird(int position, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);
    void delete_bird(int position);
    void get_bird(int position);

    void print_birds();
};
