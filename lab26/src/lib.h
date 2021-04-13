#include "stdio.h"
#include <string>
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int count_lines();


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
    Bird_features();
    Bird_features(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);
    Bird_features(const Bird_features &other);

    void SetRinged(std::string ringed);
    void SetSpecies(std::string species);
    void SetAge(int age);
    void SetHouseSquare(int square);
    void SetHouseHeight(int height);
    void SetHouseNumFeeders(int num_feeders);
    void SetHouseNest(std::string nest);
    void SetSex(std::string sex);


    std::string GetRinged();
    std::string GetSpecies();
    int GetAge();
    int GetHouseSquare();
    int GetHouseHeight();
    int GetHouseNumFeeders();
    std::string GetHouseNest();
    std::string GetSex();
};

//Класс хранящий в себе динамический массив(вектор) базовых классов
class Birds
{
    int n;
    int size;
public:
    
    Bird_features *birds; 
    Birds();
    Birds(const Birds &other);

    //Деструктор очищает выделенную память под вектор
    ~Birds();
    
    void read_file(std::string filename);

    void add_bird( int position, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);

    Bird_features* add_bir(Bird_features *birds, int position, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);

    void delete_bird(int position);

    Bird_features* delete_bir(int position);

    void get_bird(int position);

    void print_birds();
};

