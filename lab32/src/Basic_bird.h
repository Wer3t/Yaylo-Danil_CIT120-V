#ifndef _YAYLO_27_
#define _YAYLO_27_

#include "stdio.h"
#include <string>
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <memory>

using namespace std;

enum Month
{
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

class Basic_bird{
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
    Basic_bird();
    Basic_bird(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);
    Basic_bird(const Basic_bird &other);

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

    virtual Basic_bird* AddBird(Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex)=0;
    virtual Basic_bird* AddBird(int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex)=0;
    virtual std::string GetBird()=0;
};

#endif