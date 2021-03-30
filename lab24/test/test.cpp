#include "/home/danil/dev/Yaylo-Danil_CIT120-V/lab23/src/lib.h"

void test_add_bird(){
    Birds test;
    int res=0;
    test.add_bird(0,"ringed", "bird", 10,20,30,2,"have","male");
    if(test.birds[0].GetRinged()!="ringed"){
        cout<< "Тест на проверку добавления птицы в вектор провален"<< endl;
    } else if(test.birds[0].GetSpecies()!="bird"){
        cout<< "Тест на проверку добавления птицы в вектор провален"<< endl;
    } else if(test.birds[0].GetAge()!=10){
        cout<< "Тест на проверку добавления птицы в вектор провален"<< endl;
    } else if(test.birds[0].GetHouseSquare()!=20){
        cout<< "Тест на проверку добавления птицы в вектор провален"<< endl;
    } else if(test.birds[0].GetHouseHeight()!=30){
        cout<< "Тест на проверку добавления птицы в вектор провален"<< endl;
    } else if(test.birds[0].GetHouseNumFeeders()!=2){
        cout<< "Тест на проверку добавления птицы в вектор провален"<< endl;
    } else if(test.birds[0].GetHouseNest()!="have"){
        cout<< "Тест на проверку добавления птицы в вектор провален"<< endl;
    } else if(test.birds[0].GetSex()!="male"){
        cout<< "Тест на проверку добавления птицы в вектор провален"<< endl;
    } else {
        cout<< "Тест на проверку добавления птицы в вектор Успешен"<< endl;
    }
}



int main(){
    test_add_bird();
    return 0;
}