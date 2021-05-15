#include "Basic_bird.h"

class Birds{
public:
    Birds();
    ~Birds();
    vector<Basic_bird*> birds;

    vector<Basic_bird*> AddBird (Basic_bird *bird, int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);
    vector<Basic_bird*> AddBird(Basic_bird *bird, Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);
    vector<Basic_bird*> AddBird(Basic_bird *bird, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);

    vector<Basic_bird*> DelBird(int position);
    
};

