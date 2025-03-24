#include <iostream>

using namespace std;

template <class T>

class Vector{
    private:
        T *_arr;
        int _capacity;
        int _size;

    public:
        Vector(int cap=1){
            _arr = new T[cap];
            _capacity= cap;
            _size = 0;
        }

    private:
        void reverse_capacity(int new_cap){
            T *new_arr = new T[new_cap];
            for(int i=0; i< _size; i++){
                new_arr[i]=_arr[i];
            }
            delete [] _arr;
            _arr = new_arr;
            _capacity = new_cap;
        }

    public:
        void append(const T& elem){
            if (_capacity == _size){
                reverse_capacity(2 * _capacity);
            }
            _arr[_size]=elem;
            _size++;
        }

        int removeLast(){
            int ret = _arr[_size-1];
            _size--;
            if (_size == _capacity/4){
                revise_capacity(_capacity/2);
            }
            return ret;
        }
};