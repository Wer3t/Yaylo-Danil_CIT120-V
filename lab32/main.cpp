#include "Birds.h"
#include "Basic_bird.h"
#include "Exotic_bird.h"
#include "Migratory_bird.h"
#include "MyPtr.h"

int main()
{
    cout << "\n\n";
    Birds b, b1, b2;

    vector<unique_ptr<Birds>> v_Birds;
    v_Birds.push_back(make_unique<Birds>(b1));
    v_Birds.push_back(make_unique<Birds>(b1));
    v_Birds.push_back(make_unique<Birds>(b2));

    for(vector<unique_ptr<Birds>>::iterator it = v_Birds.begin(); it != v_Birds.end(); it++){
        Exotic_bird e;
        Migratory_bird m;
        it->get()->ReadFile(&e, &m, "input.txt");
        it->get()->AddBird(&m, APRIL, OCTOBER, "Non ringed", "Big bird", 5, 100, 250, 10, "Have", "Male");
        it->get()->AddBird(&e, 2, 10, "Ringed", "Bird", 1, 10, 20, 2, "Haven't", "Female");
        it->get()->SortByAge();
        it->get()->DelBird(rand()% it->get()->birds.size());
        it->get()->PrintBirds();
        cout << "\nПроцент мужских особей к женским: " << it->get()->PercentMaleToFemale() << endl;
        cout << "\nСредний возраст всех особей: " << it->get()->AverageAge() << endl;
    }

    for(vector<unique_ptr<Birds>>::iterator it = v_Birds.begin()+1; it != v_Birds.end(); it++){
        v_Birds.begin()->get()->ConcVec((it)->get()->birds);
    }
    cout << "\n\n--------------------------------------------Вывод конкатенированных векторов--------------------------------------------\n" << endl;

    v_Birds.begin()->get()->PrintBirds();/*

    
    int *a=new int(5);
    MyPtr<int*> ptr(&a);
    MyPtr<int*> ptr2(ptr);*/
}