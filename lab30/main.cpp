#include "Birds.h"
#include "Basic_bird.h"
#include "Exotic_bird.h"
#include "Migratory_bird.h"
#include <map>

int main()
{
    cout << "\n\n";
    Exotic_bird e;
    Migratory_bird m;

    Birds b;
    b.ReadFile(&e, &m, "input.txt");
    b.SortByAge();

    //Второй массив данных
    Birds b2;
    b2.AddBird(&m, APRIL, OCTOBER, "Non ringed", "Big bird", 5, 100, 250, 10, "Have", "Male");
    b2.AddBird(&e, 2, 10, "Ringed", "Bird", 1, 10, 20, 2, "Haven't", "Female");

    b.ConcVec(b2.birds);

    b.DelBird(2);

    b.PrintBirds();

    cout << "\nПроцент мужских особей к женским: " << b.PercentMaleToFemale() << endl;
    cout << "\nСредний возраст всех особей: " << b.AverageAge() << endl;

    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

    map<string, vector<string>> map1;
    map<string, vector<string>> map2;

    vector<string> uk {"Харків","Київ"};
    vector<string> ru {"Москва","Бєлгород"};
    vector<string> bl{"Мінськ","Бобруйськ",};

    map1.emplace("Україна", uk);
    map1.emplace("Росія", ru);
    map1.emplace("Білорусь", bl);

    vector<string> uk1{"Харків","Запоріжжя"};
    vector<string> ru1 {"Санкт-Петербург"};
    vector<string> pl{"Варшава"};

    map2.emplace("Польща", pl);
    map2.emplace("Росія", ru1);
    map2.emplace("Україна", uk1);

    for (map<string, vector<string>>::iterator it = map2.begin(); it != map2.end(); it++)   //парсинг по map2
    {
        bool is =true; //Флаг на встречание одинаковых ключей
        for (map<string, vector<string>>::iterator it1 = map1.begin(); it1 != map1.end(); it1++)     //парсинг по map1
        {
            if (it->first == it1->first)      //Если встретились одинаковые ключи
            {
                is=false;
                for(int i=0;i<it->second.size();i++){   //Парсинг вектора map2
                     bool empty=true;  //Флаг на встречание повтора городов
                     for(int j=0;j<it1->second.size();j++){    //Парсинг вектора map1
                        if(it->second[i]==it1->second[j])
                            empty=false;  //Если есть повтор городов
                     }
                     if(empty)  //Если нет повтора, то город добавляется в map1
                        it1->second.push_back(it->second[i]);
                 }
            }
        }
        if(is)  //Если нет повтора ключей, то полностью дублируется в map1
            map1.emplace(it->first, it->second);
    }


    for (map<string, vector<string>>::iterator it = map1.begin(); it != map1.end(); it++)
    {
        std::cout << it->first << ": ";
        for(int i=0;i<it->second.size();i++)
            cout<<it->second[i]<<", ";
        cout<<endl;
    }

    uk.clear();
    uk1.clear();
    ru.clear();
    ru1.clear();
    pl.clear();
    bl.clear();
    return 0;
}