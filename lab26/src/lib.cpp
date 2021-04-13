#include "lib.h"

int count_lines()
{
	/*Подсчёт количества строк в файле, что бы понимать сколько структур будет*/
	int lines_count = 0;
	FILE *file;
	file = fopen("input.txt", "r");
	while (!feof(file))
	{
		if (fgetc(file) == '\n')
		{
			lines_count++;
		}
	}
    lines_count++;
	fclose(file);
	return lines_count;
}

    void Bird_features::SetRinged(std::string ringed){
        this->ringed=ringed;
    }
    void Bird_features::SetSpecies(std::string species){
        this->species=species;
    }
    void Bird_features::SetAge(int age){
        this->age=age;
    }
    void Bird_features::SetHouseSquare(int square){
        this->house.square=square;
    }
    void Bird_features::SetHouseHeight(int height){
        this->house.height=height;
    }
    void Bird_features::SetHouseNumFeeders(int num_feeders){
        this->house.num_feeders=num_feeders;
    }
    void Bird_features::SetHouseNest(std::string nest){
        this->house.nest=nest;
    }
    void Bird_features::SetSex(std::string sex){
        this->sex=sex;
    }
//Конструктор по умолчанию создает пустой класс
Bird_features::Bird_features()
    {
        cout << "\nВызвался конструктор по умолчанию Birds_features" << endl;
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
    Bird_features::Bird_features(std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex)
    {
        cout << "\nВызвался конструктор с аргументами Birds_features" << endl;
        this->ringed = ringed;
        this->species = species;
        this->age = age;
        this->house.square = square;
        this->house.height = height;
        this->house.num_feeders = num_feeders;
        this->house.nest = nest;
        this->sex = sex;
    }
    
    Bird_features::Bird_features(const Bird_features &other){
        this->ringed = other.ringed;
        this->species = other.species;
        this->age = other.age;
        this->house.square = other.house.square;
        this->house.height = other.house.height;
        this->house.num_feeders = other.house.num_feeders;
        this->house.nest = other.house.nest;
        this->sex = other.sex;

        cout << "\nВызвался конструктор копирования Birds_features" << endl;
    }

    std::string Bird_features::GetRinged(){
        return this->ringed;
    }
    std::string Bird_features::GetSpecies(){
        return this->species;
    }
    int Bird_features::GetAge(){
        return this->age;
    }
    int Bird_features::GetHouseSquare(){
        return this->house.square;
    }
    int Bird_features::GetHouseHeight(){
        return this->house.height;
    }
    int Bird_features::GetHouseNumFeeders(){
        return this->house.num_feeders;
    }
    std::string Bird_features::GetHouseNest(){
        return this->house.nest;
    }
    std::string Bird_features::GetSex(){
        return this->sex;
    }

Birds::Birds(){
        int n = count_lines();
        birds = new Bird_features[n];
}

Birds::Birds(const Birds &other){
        this->birds = other.birds;
        for(int i=0;i<Birds::size;i++){
            this->birds[i]=other.birds[i];
        }
        cout << "\nВызвался конструктор копирования Birds" << endl;
}

Birds::~Birds()
{
    cout << "\nВызвался деструктор Birds" << endl;
    delete[] birds;
}

void Birds::read_file(std::string filename)
{
    Birds::size=0;
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
            cout << "Файл открыт" << endl;
            Birds::size++;
        }
    }
    else
    {
        cout << "Не удалось открыть файл." << endl;
    }
}

Bird_features* Birds::add_bir(Bird_features *birds, int position, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex)
{
    //Если указанная позиция больше чем размер вектора, то добавление произойдёт в конец
    if (position >= Birds::size)
    {
        position = Birds::size;
    }
    Bird_features *temp = new Bird_features[Birds::size+1];
    for(int i=0;i<position;i++){
        temp[i]=birds[i];
    }
    temp[position]=Bird_features(ringed, species, age, square, height, num_feeders, nest, sex);
    if(position < Birds::size){
        int u=Birds::size-position;
        for(int i=1;i<u+1;i++){
            temp[i+position]=birds[i+position-1];
        }
    }
    Birds::size++;
    return temp;
}

void Birds::add_bird( int position, std::string ringed, std::string species, int age, int square, int height, int num_feeders, std::string nest, std::string sex){
        birds=add_bir(birds, position, ringed, species, age, square, height, num_feeders, nest, sex);
}

Bird_features* Birds::delete_bir(int position)
{
    Bird_features *temp = new Bird_features[Birds::size-1];
    for(int i=0;i<position;i++){
        temp[i]=birds[i];
    }
    for(int i=position;i<Birds::size-1;i++){
        temp[i+position]=birds[i+position+1];
    }

    Birds::size--;
    return temp;
}
void Birds::delete_bird(int position){
        birds=delete_bir(position);
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
    for (int i = 0; i < Birds::size; i++)
        get_bird(i);
}

