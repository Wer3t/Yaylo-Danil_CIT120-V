#include "Birds.h"
#include "Basic_bird.h"
#include "Exotic_bird.h"
#include "Migratory_bird.h"
#include <map>

int main()
{
    cout << "\n\n";
    Birds b, b1, b2;
    vector<Birds> v_Birds{b, b1, b2};
    for(vector<Birds>::iterator it = v_Birds.begin(); it != v_Birds.end(); it++){
        Exotic_bird e;
        Migratory_bird m;

        it->ReadFile(&e, &m, "input.txt");
        it->AddBird(&m, APRIL, OCTOBER, "Non ringed", "Big bird", 5, 100, 250, 10, "Have", "Male");
        it->AddBird(&e, 2, 10, "Ringed", "Bird", 1, 10, 20, 2, "Haven't", "Female");
        it->SortByAge();
        it->DelBird(rand()% it->birds.size());
        it->PrintBirds();
        cout << "\nПроцент мужских особей к женским: " << it->PercentMaleToFemale() << endl;
        cout << "\nСредний возраст всех особей: " << it->AverageAge() << endl;
    }

    for(vector<Birds>::iterator it = v_Birds.begin()+1; it != v_Birds.end(); it++){
        v_Birds.begin()->ConcVec((it)->birds);
    }
    cout << "\n\n--------------------------------------------Вывод конкатенированных векторов--------------------------------------------\n" << endl;

    v_Birds.begin()->PrintBirds();
}