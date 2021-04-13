#include "Basic_bird.h"
#include "Migratory_bird.h"
#include "Exotic_bird.h"
#include "Birds.h"

int main(){
    Exotic_bird e;
    Birds birds;
    birds.add_bird(&e, 2, 10, "Ringed", "Birdy", 1, 10, 20, 2, "Have", "Male");
    return 0;
}