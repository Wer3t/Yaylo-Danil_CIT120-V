#include "lib.h"
#include "Migration_bird.h"
#include "Exotic_bird.h"

int main(){
    cout << endl;

    cout << "\n----------------------------------Начало работы--------------------------------" << endl;
    Birds a;
    a.read_file("input.txt");
    a.print_birds();
    cout << endl;

    cout << "\n----------------------------------Удаление эллемента--------------------------------" << endl;

    a.delete_bird(2);
    a.print_birds();
    cout << endl;

    cout << "\n----------------------------------Добавление с аргументами--------------------------------" << endl;

    a.add_bird(1, "ringed", "baby crow", 1, 23, 10, 2, "haven't nest", "male");
    a.print_birds();

    cout << "\n---------------------------------Работа с наследниками---------------------------------" << endl;

    Migratory_birds m;
    m.add_migratory_bird(OCTOBER,MARCH, "ringgged");
    m.print_migratory_birds();

     cout << "\n---------------------------------------------------------------------------------------" << endl;

    Exotic_birds e;
    e.add_exotic_bird(3, 65, "NOT ring");
    e.print_exotic_birds();
    return 0;
}