#include "stdio.h"
#include <string>
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int count_lines(std::string filename);

class Bird_features
{
    //Описание базового класса
    struct place
    {
        int square;
        int height;
        int num_feeders;
        std::string nest;
    };
    std::string ringed;
    std::string species;
    int age;
    struct place house;
    std::string sex;

public:
    int input;
    //Конструктор по умолчанию создает пустой класс
    Bird_features()
    {
        cout << "\nВызвался конструктор по умолчанию" << endl;
        this->ringed = "default";
        this->species = "";
        this->age = 0;
        this->house.square = 0;
        this->house.height = 0;
        this->house.num_feeders = 0;
        this->house.nest = "";
        this->sex = "";
    }

    //Конструктор с аргументами создает класс и заполняет входными данными
    Bird_features(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex)
    {
        cout << "\nВызвался конструктор с аргументами " << endl;
        this->ringed = ringed;
        this->species = species;
        this->age = age;
        this->house.square = square;
        this->house.height = height;
        this->house.num_feeders = num_feeders;
        this->house.nest = nest;
        this->sex = sex;
    }
    
    Bird_features(const Bird_features &other){
        this->ringed = other.ringed;
        this->species = other.species;
        this->age = other.age;
        this->house.square = other.house.square;
        this->house.height = other.house.height;
        this->house.num_feeders = other.house.num_feeders;
        this->house.nest = other.house.nest;
        this->sex = other.sex;

        cout << "\nВызвался конструктор копирования" << endl;
    }

    Bird_features & operator = (const Bird_features &other){
        cout << "\nВызвался оператор = " << endl;

        this->ringed = other.ringed;
        this->species = other.species;
        this->age = other.age;
        this->house.square = other.house.square;
        this->house.height = other.house.height;
        this->house.num_feeders = other.house.num_feeders;
        this->house.nest = other.house.nest;
        this->sex = other.sex;

        return *this;
    }

    bool operator == ( const Bird_features &other){
        return this->ringed == other.ringed && this->species == other.species && this->age == other.age && this->house.square == other.house.square && this->house.height == other.house.height && this->house.num_feeders == other.house.num_feeders && this->house.nest == other.house.nest && this->sex == other.sex;
    }

    

    void SetRinged(std::string ringed){
        this->ringed=ringed;
    }
    void SetSpecies(std::string species){
        this->species=species;
    }
    void SetAge(int age){
        this->age=age;
    }
    void SetHouseSquare(int square){
        this->house.square=square;
    }
    void SetHouseHeight(int height){
        this->house.height=height;
    }
    void SetHouseNumFeeders(int num_feeders){
        this->house.num_feeders=num_feeders;
    }
    void SetHouseNest(std::string nest){
        this->house.nest=nest;
    }
    void SetSex(std::string sex){
        this->sex=sex;
    }


    std::string GetRinged(){
        return this->ringed;
    }
    std::string GetSpecies(){
        return this->species;
    }
    int GetAge(){
        return this->age;
    }
    int GetHouseSquare(){
        return this->house.square;
    }
    int GetHouseHeight(){
        return this->house.height;
    }
    int GetHouseNumFeeders(){
        return this->house.num_feeders;
    }
    std::string GetHouseNest(){
        return this->house.nest;
    }
    std::string GetSex(){
        return this->sex;
    }
};

//Класс хранящий в себе динамический массив(вектор) базовых классов
class Birds
{
public:
    //Создание вектора типа Базовый класс
    std::vector <Bird_features> birds;
    Birds(){
    }
    Birds(const Birds &other){
        this->birds = other.birds;
        for(int i=0;i<birds.size();i++){
            this->birds[i]=other.birds[i];
        }
        cout << "\nВызвался конструктор копирования" << endl;
    }

    //Деструктор очищает выделенную память под вектор
    ~Birds()
    {
        cout << "\nВызвался деструктор" << endl;
        birds.clear();
    }
    
    Bird_features& operator[](int index){
        return birds[index];
    }
    
    void read_file(std::string filename)
    {
        ifstream file(filename);

        if (file.is_open()) //Если открытие файла прошло успешно
        {
            cout << "Файл открыт" << endl;
            std::string line; //Строчка текста

            //Будем считывать информацию построчно до тех пор,
            //пока не закончится файл
            int j=0;
            while (getline(file, line))
            {
                birds.emplace_back(Bird_features());
                //Создадим поток для считывания данных из строчки
                istringstream iss(line);
                std::string token;
                int i = 0;
                while (getline(iss, token, '|'))
                {
                    if (i == 0)
                        birds[j].SetRinged(token);
                    if (i == 1)
                        birds[j].SetSpecies(token);
                    if (i == 2)
                        birds[j].SetAge(atoi(token.c_str()));//перевод string в int
                    if (i == 3)
                        birds[j].SetHouseSquare(atoi(token.c_str()));//перевод string в int
                    if (i == 4)
                        birds[j].SetHouseHeight(atoi(token.c_str()));//перевод string в int
                    if (i == 5)
                        birds[j].SetHouseNumFeeders(atoi(token.c_str()));//перевод string в int
                    if (i == 6)
                        birds[j].SetHouseNest(token);
                    if (i == 7)
                        birds[j].SetSex(token);

                    i++;
                }
                j++;
            }
        }
        else
        {
            cout << "Не удалось открыть файл." << endl;
        }
    }

    void add_bird(int position, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex)
    {
        //Если указанная позиция больше чем размер вектора, то добавление произойдёт в конец
        if(position>=birds.size()){
            position=birds.size();
        }
        //итератор для указания позиции в векторе
        auto iter = birds.cbegin();
        birds.emplace(iter+position, Bird_features(ringed,species,  age, square, height, num_feeders, nest,sex));
    }

    void delete_bird(int position){
        auto iter = birds.cbegin(); // указатель на первый элемент
        birds.erase(iter + position);
    }

    //Вывод элемента вектора с помощью публичных гетеров
    void get_bird(int position){
        cout << "Птица №"<<position<<endl;
        cout <<birds[position].GetRinged()<<" ";
        cout <<birds[position].GetSpecies()<<" ";
        cout <<birds[position].GetAge()<<" ";
        cout <<birds[position].GetHouseSquare()<<" ";
        cout <<birds[position].GetHouseHeight()<<" ";
        cout <<birds[position].GetHouseNumFeeders()<<" ";
        cout <<birds[position].GetHouseNest()<<" ";
        cout <<birds[position].GetSex()<<endl;
    }

    void print_birds(){
        int size_birds=birds.size();
        
        for(int i=0;i<size_birds;i++){
            get_bird(i);
        }
    }
};


std::ostream& operator<< (std::ostream &out, Bird_features &other)
    {
        out << "Bird(" << other.GetRinged() << ", " << other.GetSpecies() << ", " << other.GetAge() << ", " << other.GetHouseSquare() << ", " << other.GetHouseHeight() << ", " << other.GetHouseNumFeeders() << ", " << other.GetHouseNest() << ", " << other.GetSex() <<")"<<endl;
        return out;
    }

std::istream& operator>> (std::istream &in, Bird_features &other)
    {
        in >> other.input;
    return in;
    }