#include "Basic_bird.h"


class Birds{
public:
    ~Birds();
    vector<Basic_bird*> birds;

    void ReadFile (Basic_bird *exotic_bird, Basic_bird *migratory_bird,string filename);

    void AddBird (Basic_bird *bird, int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);
    void AddBird(Basic_bird *bird, Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex);

    void DelBird(int position);

    void PrintBirds();
    
    double PercentMaleToFemale();
    double AverageAge();

    void SortByAge();
    
    void ConcVec(vector<Basic_bird*> v2);
};

bool IfMonth(string str);
Month WhichMonth(string str);




 
