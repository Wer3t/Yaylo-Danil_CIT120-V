#include "Basic_bird.h"   


class Exotic_bird: public Basic_bird{
//Наследник класса Birds, добавляются два поля
    short min_temperature;
    short max_temperature;
public:
    Exotic_bird();
    
    void SetMinTemperature(short min);
    void SetMaxTemperature(short max);
    short GetMinTemperature();
    short GetMaxTemperature();

    std::string GetBird() override final;
    Basic_bird* AddBird(int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex) override final;
    Basic_bird* AddBird(Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex) override final;
};