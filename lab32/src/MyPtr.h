#include "Basic_bird.h"

template<typename T>
class MyPtr{
    T *ptr;
    int cnt;
public:
    MyPtr(T *ptr){
        this->ptr = ptr;
        cnt = 1;
        cout << "\nВызвался конструктор" << endl;
    }
    MyPtr(const MyPtr &other){
        this->ptr=other.ptr;
        this->cnt=other.cnt+1;
        cout << "\nВызвался конструктор копирования" << endl;
    }
    ~MyPtr(){
        if (cnt == 1) { 
            delete *ptr; 
            cout << "\nВызвался деструктор" << endl;
        }
        cnt--;
    }
    T& operator*(){
        return *ptr;
    }
    T& operator->(){
        return ptr;
    }
};