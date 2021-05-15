#include "Menu.h"

void Menu::start(){
    Migratory_bird migratory_bird;
    Exotic_bird exotic_bird;
    Classic_bird classic_bird;
    Birds list; 
    Controller controller = Controller(list);
    cout<<"      Меню для работы с программой"<<endl;
    while(1){
        cout <<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"            Введите цифру для:\n\n[1] Считать данные из файла \n[2] Добавить объект в массив\n[3] Удалить объект\n[4] Вывести массив в файл\n[5] Вывести массив в консоль\n[6] Отсортировать массив\n[7] Выполнить методы по работе с коллекцией\n\n[0] Конец работы\n"<<endl;
        unsigned short to_do;
        cin>>to_do;

        string filename={0};
        int a,b;
        Month month_away, month_arrival;
        string ringed, species, nest, sex, month_awayy, month_arrivall;
        int age, square, height, num_feeders, min_temperature=0, max_temperature=0;
        switch (to_do)
        {
        case 1:
            cout<<"Введите имя файла: ";
            cin>>filename;
            cout<<endl;
            controller.ReadFile(&exotic_bird, &migratory_bird, &classic_bird, filename);
            break;
        case 2:
            cout<<"\n            Введите цифру для:\n[1]Добавить объект класса Classic_bird\n[2]Добавить объект класса Migratory_bird\n[3]Добавить объект класса Exotic_bird"<<endl;
            cin>>a;
            cout<<"\n            Введите цифру для:\n[1]Выполнить ввод данных самостоятельно\n[2]Заполнить объект рандомом"<<endl;
            cin>>b;
            if(b==1){
                cout<<"\n Введите елемент для поля Ringed: "; cin>>ringed;
                cout<<"\n Введите елемент для поля Species: "; cin>>species;
                cout<<"\n Введите елемент для поля Age: "; cin>>age;
                cout<<"\n Введите елемент для поля House_square: "; cin>>square;
                cout<<"\n Введите елемент для поля House_height: "; cin>>height;
                cout<<"\n Введите елемент для поля House_num_feeders: "; cin>>num_feeders;
                cout<<"\n Введите елемент для поля House_nest: "; cin>>nest;
                cout<<"\n Введите елемент для поля Sex: "; cin>>sex;
                if(a==2){
                    cout<<"\n Введите елемент для поля Month_away: "; cin>>month_awayy;
                    month_away=controller.WhichMonth(month_awayy);
                    cout<<"\n Введите елемент для поля Month_arrival: "; cin>>month_arrivall;
                    month_arrival=controller.WhichMonth(month_arrivall);
                }else if(a==3){
                    cout<<"\n Введите елемент для поля Min_temperature: "; cin>>min_temperature;
                    cout<<"\n Введите елемент для поля Max_temperature: "; cin>>max_temperature;
                }
            }else if(b==2){
                ringed = "[RANDOM RINGED]";
                species = "[RANDOM SPECIES]";
                age = rand()%20;
                square = rand()%100;
                height = rand()%100;
                num_feeders = rand()%10;
                nest = "[RANDOM NEST]";
                sex = "[RANDOM SEX]";
                if(a==2){
                    month_away = OCTOBER;
                    month_arrival = MARCH;
                    controller.list->AddBird(&migratory_bird, month_away, month_arrival,ringed, species, age, square, height, num_feeders, nest, sex);
                }else if(a==3){
                    min_temperature= rand()%10;
                    max_temperature= rand()%30+20;
                    controller.list->AddBird(&exotic_bird, min_temperature, max_temperature ,ringed, species, age, square, height, num_feeders, nest, sex);
                }
                if(a==1)
                    controller.list->AddBird(&classic_bird, ringed, species, age, square, height, num_feeders, nest, sex);
            }
            break;
        case 3:
            cout<<"Введите индекс обьекта для удаления [0.."<<controller.list->birds.size()-1<<"]: "; cin>>a;
            controller.list->DelBird(a);
            break;
        case 4:
            cout<<"Введите имя файла: ";
            cin>>filename;
            cout<<endl;
            controller.WriteFile(filename);
            break;
        case 5:
            controller.PrintBirds();
            break;
        case 6:
            cout<<"\n            Введите цифру для сортировки относительно поля:\n[1]Ringed\n[2]Species\n[3]Age\n[4]HouseSquare\n[5]HouseHeight\n[6]HouseNUmFeeders\n[7]HouseNest\n[8]Sex"<<endl;
            cin>>a;
            controller.SortBy(a);
            cout<<"Коллекция была отсортирована"<<endl;
            break;
        case 7:
            cout<<"\n            Введите цифру для:\n[1]Найти процентное отношение мужских особей к женским\n[2]Найти средний возраст всех неокольцованных птиц\n[3]Найти птицу с наидольшей зимовкой"<<endl;
            cin>>a;
            switch (a)
            {
            case 1:
                    cout<<"Процентное отношение мужских особей к женским: "<<controller.PercentMaleToFemale()<<endl;
                break;
            case 2:
                    cout<<"Средний возраст всех неокольцованных птиц: "<<controller.AverageAge()<<endl;
                break;
            case 3:
                cout<<"Птица с наидольшей зимовкой: ";
                cout<<controller.list->birds[controller.FindLongWinter()]->GetBird();
                break;
            
            default:
                break;
            }
            break;
        
        case 0:
            return;
               
        default:
            break;
        }
    }

}