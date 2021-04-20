#include "Array.h"

int main(){
    Array a;
    int** arrays;
    double* res_arr;

    arrays = a.ReadFile("inpu.txt");
    res_arr = a.AverageArray(arrays);
    a.WriteOut("output.txt", res_arr);
    
    a.FreeMemory(arrays);
    return 0;
}