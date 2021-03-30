#include "lib.h"


int main(){
    cout << endl;
    Birds a;
    a.read_file("input.txt");
    a.print_birds();
    cout << endl;

    a.delete_bird(2);
    a.print_birds();
    cout << endl;

    a.add_bird(1, "ringed", "baby crow", 1, 23, 10, 2, "haven't nest", "male");
    a.print_birds();

    Birds b;
    b.read_file("input.txt");
    b.delete_bird(1);
    b=a;
    b.print_birds();
    Birds c;

    c=b=a;

    cout<<a.birds[0];
    
    cout<<a[2];
    return 0;
}