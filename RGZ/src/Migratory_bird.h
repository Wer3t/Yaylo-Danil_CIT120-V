#include "Basic_bird.h"


class Migratory_bird: public Basic_bird{
//Наследник класса Birds, добавляются два поля
    Month month_away;
    Month month_arrival;
public:
    Migratory_bird();
    
    void SetMonthAway(Month mn);
    void SetMonthArrival(Month mn);
    Month GetMonthAway();
    Month GetMonthArrival();

    std::string GetBird() override final;
    Basic_bird* AddBird(int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex) override final;
    Basic_bird* AddBird(Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex) override final;
    Basic_bird* AddBird(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex) override final;

    string MonthToStr(Month month);
};