#include "Basic_bird.h"
#include "Migratory_bird.h"
#include "Exotic_bird.h"
#include "Birds.h"

int main(){
    Exotic_bird e;
    Migratory_bird m;
    Birds birds;
    birds.add_bird(&e, 2, 10, "Ringed", "Birdy", 1, 10, 20, 2, "Have", "Male");
    birds.add_bird(&m, APRIL, OCTOBER, "Non ringed", "Big bird", 5, 100, 250, 10, "Have", "Male");
    birds.add_bird(&e, 2, 10, "Ringed", "Bird", 1, 10, 20, 2, "Haven't", "Female");
    birds.add_bird(&m, MARCH, SEPTEMBER, "Rid", "Bidy", 1, 10, 20, 2, "Have", "Male");
    birds.print_birds(&e);
    return 0;
}