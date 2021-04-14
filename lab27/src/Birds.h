#include "Basic_bird.h"

class Birds{
    int size;
    Basic_bird **birds;
public:
    Birds();
    Birds(const Birds &other);
    ~Birds();

    void add_bird(Basic_bird *bird, Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);
    void add_bird(Basic_bird *bird, int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);

    Basic_bird** add_memory(Basic_bird** birds, Basic_bird *bird, int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);
    Basic_bird** add_memory(Basic_bird** birds, Basic_bird *bird, Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);

    void print_birds(Basic_bird *bird);
};