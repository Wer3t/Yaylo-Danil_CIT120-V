#include "Birds.h"

Birds::~Birds(){
    birds.clear();
}

//Проверка соответсвует ли заданная строка параметрам enum Month
bool IfMonth(string str){
    static const regex r ("[A-Z]+");
    return regex_match(str, r);
}

//Перевод из строки в тип Month
Month WhichMonth(string str){
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

void Birds::ReadFile(Basic_bird *exotic_bird, Basic_bird *migratory_bird,string filename)
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
        Birds::ReadFile(exotic_bird, migratory_bird, filename); //Будет рекурсировать пока пользователь не введет корректное название файла
    }

    file.exceptions(ifstream::goodbit); //Из-за отсутствия этой строки компилятор ругался раньше
    std::string line; //Строчка текста

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

            if (i == 0)
                ringed=token;
            if (i == 1)
                species=token;
            if (i == 2)
                age=atoi(token.c_str());
            if (i == 3)
                square=atoi(token.c_str());
            if (i == 4)
                height=atoi(token.c_str());
            if (i == 5)
                num_feeders=atoi(token.c_str());
            if (i == 6)
                nest=token;
            if (i == 7)
                sex=token;
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
        if(max_temperature==0){              //Если числовой параметр температуры не изменился
            
            //Пушим в вектор указатель который вернёт функция добавления элемента из обьекта класса Migratory_bird
            birds.push_back(migratory_bird->AddBird(month_away, month_arrival, ringed, species, age, square, height, num_feeders, nest, sex));
        
        }else{              //Если числовой параметр температуры изменился
            
            //Пушим в вектор указатель который вернёт функция добавления элемента из обьекта класса Exotic_bird
            birds.push_back(exotic_bird->AddBird(min_temperature, max_temperature, ringed, species, age, square, height, num_feeders, nest, sex));
        
        }
    }
}

void Birds::AddBird (Basic_bird *bird, int min_temperature, int max_temperature, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){

    //Пушим в вектор указатель который вернёт функция добавления элемента из обьекта класса Exotic_bird

    birds.push_back(bird->AddBird(min_temperature, max_temperature, ringed, species, age, square, height, num_feeders, nest, sex));
}

void Birds::AddBird(Basic_bird *bird, Month month_away, Month month_arrival, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){

    //Пушим в вектор указатель который вернёт функция добавления элемента из обьекта класса Migratory_bird

    birds.push_back(bird->AddBird(month_away, month_arrival, ringed, species, age, square, height, num_feeders, nest, sex));
}

void Birds::DelBird(int position)
{
    auto iter = birds.cbegin(); // указатель на первый элемент
    birds.erase(iter + position); //удаление нужного элемента
}

void Birds::PrintBirds(){
    cout <<endl;
    cout <<"-----------------------------------------------Вывод содержимого коллекции-----------------------------------------------\n"<<endl;
    for(int i=0; i<birds.size();i++){
        cout << "Птица №" << i << ":\n"<<birds[i]->GetBird()<<endl;
    }
    cout <<"-------------------------------------------------------------------------------------------------------------------------"<<endl;
}

//Процент мужских особей к женским
double Birds::PercentMaleToFemale(){
    int male=0, female=0;
    for(int i=0;i<birds.size();i++){
        if(birds[i]->GetSex()=="male") //подсчёт мужских особей
            male++;
        else if(birds[i]->GetSex()=="female") //подсчёт женских особей
            female++;
    }
    return male/female;  //возвращаем результат деления
}

//Средний возраст всех особей
double Birds::AverageAge(){
    int age;
    for(int i=0;i<birds.size();i++){
        age+=birds[i]->GetAge();  //Сложение всех возрастов 
    }
    return age/birds.size(); //возвращаем результат деления
}

//конкатенация векторов
void Birds::ConcVec(vector<Basic_bird*> v2){
    birds.insert( birds.end(), v2.begin(), v2.end()); //В конец 1 вектор1 записывается вектор2 с начала до конца
}

struct sort_birds  //функтор сортировки
{
	bool operator() (Basic_bird* i, Basic_bird* j)
	{ return (i->GetAge() < j->GetAge());}
} SortAge;

void Birds::SortByAge(){
    sort (birds.begin(), birds.end(), SortAge);  //сортировка с какого по какой элемент
}
