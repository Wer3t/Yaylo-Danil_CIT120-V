#include "Array.h"

int* Array::CreateArray(int n){
    int* arr = new int[n+1];
    return arr;
}

int** Array::ReadFile(string filename){
    ifstream file(filename);
    cout<<"Попытка открыть файл..."<<endl;
    if(file.is_open()){
        cout << "Файл открыт" << endl;
        std::string line;                               //Строчка текста

        //Будем считывать информацию построчно до тех пор,
        //пока не закончится файл
         
        int j = 0;
        getline(file, line);                            //Первый элемент в файле - кол-во строк(массивов)
        size=atoi( line.c_str() );                   //Перевод из string в int
        int** arrays=new int*[size+1];                 //Массив указателей на созданные массивы
        try{
            while (getline(file, line))
        {
            if(j>=size){
                throw "В файле больше строк чем указано"; 
            }
            //Создадим поток для считывания данных из строчки    
            istringstream iss(line);
            std::string token;
            int i = 0;
            int* arr;
            while (getline(iss, token, ' '))
            {
                if (i == 0){
                    arr = CreateArray(atoi(token.c_str()));  //Выделение памяти под массив (первый элемент строки - размер)
                    arr[i]=atoi(token.c_str());
                }
                else
                    arr[i]=atoi(token.c_str()); //заполнение элементов массива
                i++;
            }
            arrays[j]= arr;//присваивание указателя на массив в массив указателей 
            j++;
        }
        }
        catch(const char *ex){
            cout<<ex<<endl;
        }
        return arrays;
    }
    else
        cout<< "Error open file!"<<endl;
}

double* Array::AverageArray(int** arrays){
    double* res_arr = new double[size];
    for(int i=0;i<size;i++){ //нахождение среднего значения всех элементов каждого массива
        double average=0;
        for(int j=1; j<arrays[i][0]+1;j++){
            average+=arrays[i][j]; // суммирование всех элементов
        }
        average/=arrays[i][0]; // деление на кол-во элементов, хранящееся в 0 элементе массива

        assert(average>=0); //Предположим что нужны только положительные ср значения

        res_arr[i]=average;//Присваивание результаты результирующему массиву
    }
    return res_arr;
}

void Array::WriteOut(string filename, double* res_arr){
    ofstream output;
    output.open(filename); //открытие(создание) файла для записи
    for(int i=0; i<size; i++){
        output << res_arr[i]<< " "; //Вывод
    }
   output.close(); 
}

void Array::FreeMemory(int** arr){ //очищение памяти
    int i=0;
    while(arr[i]!=NULL){
        delete[] arr[i];
        i++;
    }
}