// Question 3. Implement MyArray data structure

#include <iostream>

using namespace std;

class MyArray{
    private:
        int* _arr;
        int _capacity;
        int _size;

    public:
        MyArray(int capacity){
            _arr = new int[capacity];
            _capacity = capacity;
            _size =0;
        }

        ~MyArray(){
            delete [] _arr;
        }

        int length(){
            return _size;
        }

        int elementAt(int i){
            return _arr[i];
        }

        void replace(int i, int x){
            _arr[i]=x;
        }

        void append(int x){
            _arr[_size]=x;
            _size++;
        }

        int removeLast(int i, int x){
            int temp = _arr[_size-1];
            _size--;
            return temp;
        }

        void insert(int i, int x){
            int j=_size-1;
            while (j>=i){
                _arr[j+1]=_arr[j];
                j--;
            }
            _arr[i]=x;
            _size++;
        }

        void remove(int i){
            int j=i;
            while (j<_size){
                _arr[j]=_arr[j+1];
                j++;
            }
            _size--;
        }
};


int main(){

    MyArray Arr(5);
    Arr.append(1);
    return 0;
}