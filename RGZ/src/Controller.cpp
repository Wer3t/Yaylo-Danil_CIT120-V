#include "Controller.h"

Controller::Controller(Birds list){
    this->list=&list;
}

//Проверка соответсвует ли заданная строка параметрам enum Month
bool IfMonth(string str){
    static const regex r ("[A-Z]+");
    return regex_match(str, r);
}

//Перевод из строки в тип Month
Month Controller::WhichMonth(string str){
    Month month;
    if(str=="JANUARY")
        month=JANUARY;
    if(str=="FEBRUARY")
        month=FEBRUARY;
    if(str=="MARCH")
        month=MARCH;
    if(str=="APRIL")
        month=APRIL;
    if(str=="MAY")
        month=MAY;
    if(str=="JUNE")
        month=JUNE;
    if(str=="JULY")
        month=JULY;
    if(str=="AUGUST")
        month=AUGUST;
    if(str=="SEPTEMBER")
        month=SEPTEMBER;
    if(str=="OCTOBER")
        month=OCTOBER;
        if(str=="NOVEMBER")
        month=NOVEMBER;
    if(str=="DECEMBER")
        month=DECEMBER;
    return month;
}


void Controller::ReadFile(Basic_bird *exotic_bird, Basic_bird *migratory_bird, Basic_bird *classic_bird, string filename)
{    
    ifstream file;                  //поток для считывания из файла

    file.exceptions(ifstream::badbit | ifstream::failbit);  //Возможность самому обрабатывать ошибки потока
    try //Попытка открыть файл
    {
        cout << "Попытка открыть файл..." << endl;
        file.open(filename);
        cout << "Файл успешно открыт!" << endl;
    }
    catch (const exception &ex) 
    {
        cout << ex.what() << endl;    //Вывод ошибки
        cout << "Введите корректное имя файла: ";
        cin >> filename;
        cout << endl;
        Controller::ReadFile(exotic_bird, migratory_bird, classic_bird, filename); //Будет рекурсировать пока пользователь не введет корректное название файла
    }

    file.exceptions(ifstream::goodbit); //Из-за отсутствия этой строки компилятор ругался раньше
    std::string line; //Строчка текста

    static const regex text ("^[A-Z](\\w+\\s?)+");//Регулярное выражение для текста
    static const regex digits ("\\d+"); //Регулярное выражение для чисел

    //Будем считывать информацию построчно до тех пор,
    //пока не закончится файл
    while (getline(file, line))
    {
        //Буферные переменные в которые будет разбиваться строчка 
        Month month_away, month_arrival;
        string ringed, species, nest, sex;
        int age, square, height, num_feeders, min_temperature=0, max_temperature=0;

        //Создадим поток для считывания данных из строчки
        istringstream iss(line);
        std::string token;
        int i = 0;
        while (getline(iss, token, '|'))//Разбиваем строку на блоки разделённые |
        {
                //В зависимости от номера блока заносим данные в соответсвующую переменную

            if (i == 0){
                if(regex_match(token, text)) //Если соответсвует регулярному выражению
                    ringed=token;
            }  
            if (i == 1){
                if(regex_match(token, text))
                    species=token;
                    }
            if (i == 2){
                if(regex_match(token, digits))
                age=atoi(token.c_str());
            }
            if (i == 3){
                if(regex_match(token, digits))
                square=atoi(token.c_str());}
            if (i == 4){
                if(regex_match(token, digits))
                height=atoi(token.c_str());}
            if (i == 5){
                if(regex_match(token, digits))
                num_feeders=atoi(token.c_str());}
            if (i == 6){
                if(regex_match(token, text))
                nest=token;}
            if (i == 7){
                if(regex_match(token, text))
                sex=token;}
            if (i == 8){
                if(IfMonth(token))   //Если там текст который соответсвует типу Month
                    month_away=WhichMonth(token);
                else   
                    min_temperature=atoi(token.c_str());    //Иначе запись числа : запись корректных данных в таблицу на совести пользователя
            }
            if (i == 9){
                if(IfMonth(token))   //Если там текст который соответсвует типу Month
                    month_arrival=WhichMonth(token);
                else   
                    max_temperature=atoi(token.c_str());     //Иначе запись числа
            }
            i++;
        }

        if(i==6)        //Если было всего 6 елементов строки - базовый класс
            list->birds.emplace_back(classic_bird->AddBird(ringed, species, age, square, height, num_feeders, nest, sex));
        
        else if(max_temperature==0){              //Если числовой параметр температуры не изменился
            //Пушим в вектор указатель который вернёт функция добавления элемента из обьекта класса Migratory_bird
            list->birds.emplace_back(migratory_bird->AddBird(month_away, month_arrival, ringed, species, age, square, height, num_feeders, nest, sex));
        }
        else{              //Если числовой параметр температуры изменился
            
            //Пушим в вектор указатель который вернёт функция добавления элемента из обьекта класса Exotic_bird
            list->birds.emplace_back(exotic_bird->AddBird(min_temperature, max_temperature, ringed, species, age, square, height, num_feeders, nest, sex));
        }
    }
}

void Controller::WriteFile(string filename){
    ofstream output;
    output.open(filename); //открытие(создание) файла для записи
    for(int i=0; i<list->birds.size(); i++){
        output << list->birds[i]->GetBird()<< endl; //Вывод
    }
   output.close(); 
}


void Controller::PrintBirds(){
    cout <<endl;
    cout <<"-----------------------------------------------Вывод содержимого коллекции-----------------------------------------------\n"<<endl;
    for(int i=0; i<list->birds.size();i++){
        cout << "Птица №" << i << ":\n"<<list->birds[i]->GetBird()<<endl;
    }
    cout <<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
}

//Процент мужских особей к женским
double Controller::PercentMaleToFemale(){
    int male=0, female=0;
    for(int i=0;i<list->birds.size();i++){
        if(list->birds[i]->GetSex()=="Male") //подсчёт мужских особей
            male++;
        else if(list->birds[i]->GetSex()=="Female") //подсчёт женских особей
            female++;
    }
    return male/female;  //возвращаем результат деления
}

//Средний возраст всех особей
double Controller::AverageAge(){
    int age;
    for(int i=0;i<list->birds.size();i++){
        age+=list->birds[i]->GetAge();  //Сложение всех возрастов 
    }
    return age/list->birds.size(); //возвращаем результат деления
}

int Controller::FindLongWinter(){
    int winter=0; //Для хранения наидольшей зимовки
    int index=0; //Для хранения индекса птицы с наидольшей зимовкой
    bool mn = false; //Флаг для проверки есть ли у данной птицы поля отвечающие за месяца

    for(int i=0;i<list->birds.size();i++){
        istringstream iss(list->birds[i]->GetBird());
        Month month_away, month_arrival;
        std::string token;
        int j = 0;
        while (getline(iss, token, '|'))//Разбиваем строку на блоки разделённые |
        {
                //В зависимости от номера блока заносим данные в соответсвующую переменную
            if (j == 8){
                if(IfMonth(token))   //Если там текст который соответсвует типу Month
                    month_away=WhichMonth(token);
                mn=true;
            }
            if (j == 9){
                if(IfMonth(token))   //Если там текст который соответсвует типу Month
                    month_arrival=WhichMonth(token);

            }
            i++;
        }
        if(mn){ //Если у птицы есть поля с месяцами
            if(winter==0){ //Если это первая такая птица
                winter =  month_away-month_arrival;
                index=i;
            }

            else if(month_away-month_arrival>winter){ //Если зимовка этой птицы больше чем предыдущей наибольшей
                winter =  month_away-month_arrival;
                index=i;
            }
            mn=false;
        }
        
    }
    return index; //Вывод птицы с наибольшей зимовкой
}

struct sort_Ringed  //функтор сортировки
{
	bool operator() (Basic_bird* i, Basic_bird* j)
	{ return (i->GetRinged() < j->GetRinged());}
} SortRinged;

struct sort_Species  //функтор сортировки
{
	bool operator() (Basic_bird* i, Basic_bird* j)
	{ return (i->GetSpecies() < j->GetSpecies());}
} SortSpecies;

struct sort_Age  //функтор сортировки
{
	bool operator() (Basic_bird* i, Basic_bird* j)
	{ return (i->GetAge() < j->GetAge());}
} SortAge;

struct sort_Square //функтор сортировки
{
	bool operator() (Basic_bird* i, Basic_bird* j)
	{ return (i->GetHouseSquare() < j->GetHouseSquare());}
} SortSquare;

struct sort_Height //функтор сортировки
{
	bool operator() (Basic_bird* i, Basic_bird* j)
	{ return (i->GetHouseHeight() < j->GetHouseHeight());}
} SortHeight;

struct sort_NumFeeders  //функтор сортировки
{
	bool operator() (Basic_bird* i, Basic_bird* j)
	{ return (i->GetHouseNumFeeders() < j->GetHouseNumFeeders());}
} SortNumFeeders;

struct sort_Nest //функтор сортировки
{
	bool operator() (Basic_bird* i, Basic_bird* j)
	{ return (i->GetHouseNest() < j->GetHouseNest());}
} SortNest;

struct sort_Sex  //функтор сортировки
{
	bool operator() (Basic_bird* i, Basic_bird* j)
	{ return (i->GetSex() < j->GetSex());}
} SortSex;



void Controller::SortBy(int a){
    switch (a)
    {
    case 1:
        sort (list->birds.begin(), list->birds.end(), SortRinged);  //сортировка с какого по какой элемент
        break;
    case 2:
        sort (list->birds.begin(), list->birds.end(), SortSpecies);  //сортировка с какого по какой элемент
        break;
    case 3:
        sort (list->birds.begin(), list->birds.end(), SortAge);  //сортировка с какого по какой элемент
        break;
    case 4:
        sort (list->birds.begin(), list->birds.end(), SortSquare);  //сортировка с какого по какой элемент
        break;
    case 5:
        sort (list->birds.begin(), list->birds.end(), SortHeight);  //сортировка с какого по какой элемент
        break;
    case 6:
        sort (list->birds.begin(), list->birds.end(), SortNumFeeders);  //сортировка с какого по какой элемент
        break;
    case 7:
        sort (list->birds.begin(), list->birds.end(), SortNest);  //сортировка с какого по какой элемент
        break;
    case 8:
        sort (list->birds.begin(), list->birds.end(), SortSex);  //сортировка с какого по какой элемент
        break;
    
    default:
        break;
    }
    
    
}
