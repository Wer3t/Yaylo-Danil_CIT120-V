#include "lib.h"

void Birds::read_file(std::string filename)
{
    ifstream file(filename);

    if (file.is_open()) //Если открытие файла прошло успешно
    {
        cout << "Файл открыт" << endl;
        std::string line; //Строчка текста

        //Будем считывать информацию построчно до тех пор,
        //пока не закончится файл
        int j = 0;
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
                    birds[j].SetAge(atoi(token.c_str())); //перевод string в int
                if (i == 3)
                    birds[j].SetHouseSquare(atoi(token.c_str())); //перевод string в int
                if (i == 4)
                    birds[j].SetHouseHeight(atoi(token.c_str())); //перевод string в int
                if (i == 5)
                    birds[j].SetHouseNumFeeders(atoi(token.c_str())); //перевод string в int
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

void Birds::add_bird(int position, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex)
{
    //Если указанная позиция больше чем размер вектора, то добавление произойдёт в конец
    if (position >= birds.size())
    {
        position = birds.size();
    }
    //итератор для указания позиции в векторе
    auto iter = birds.cbegin();
    birds.emplace(iter + position, Bird_features(ringed, species, age, square, height, num_feeders, nest, sex));
}

void Birds::delete_bird(int position)
{
    auto iter = birds.cbegin(); // указатель на первый элемент
    birds.erase(iter + position);
}

//Вывод элемента вектора с помощью публичных гетеров
void Birds::get_bird(int position)
{
    cout << "Птица №" << position << endl;
    cout << birds[position].GetRinged() << " ";
    cout << birds[position].GetSpecies() << " ";
    cout << birds[position].GetAge() << " ";
    cout << birds[position].GetHouseSquare() << " ";
    cout << birds[position].GetHouseHeight() << " ";
    cout << birds[position].GetHouseNumFeeders() << " ";
    cout << birds[position].GetHouseNest() << " ";
    cout << birds[position].GetSex() << endl;
}

void Birds::print_birds()
{
    int size_birds = birds.size();

    for (int i = 0; i < size_birds; i++)
    {
        get_bird(i);
    }
}