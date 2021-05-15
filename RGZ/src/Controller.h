#include "Basic_bird.h"
#include "List.h"

class Controller{
   
public:
    Birds *list;
    Controller(Birds list);

    void ReadFile (Basic_bird *exotic_bird, Basic_bird *migratory_bird, Basic_bird *classic_bird, string filename);
    void PrintBirds();
    void WriteFile(string filename);
    void SortBy(int a);

    double PercentMaleToFemale();
    double AverageAge();
    int FindLongWinter();

    Month WhichMonth(string str);
};

bool IfMonth(string str);
