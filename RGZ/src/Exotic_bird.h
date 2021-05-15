#include "Basic_bird.h"   


class Exotic_bird: public Basic_bird{
//Наследник класса Basic_bird, добавляются два поля
    int min_temperature;
    int max_temperature;
public:
    Exotic_bird();
    
    void SetMinTemperature(int min);
    void SetMaxTemperature(int max);
    int GetMinTemperature();
    int GetMaxTemperature();

    std::string GetBird() override final;
    Basic_bird* AddBird(int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex) override final;
    Basic_bird* AddBird(Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex) override final;
    Basic_bird* AddBird(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex) override final;

};