#include <iostream>

using namespace std;

template < typename T>
class Stack{
    private:
        T *_stack;
        int _size;
        int _tail;
        int _capacity;

    public:
        Stack(int cap){
            _stack = new T [cap];
            _size=0;
            _tail=-1;
            _capacity=cap;
        }

        ~Stack(){
            delete [] _stack;
        }

        void Push(const T& x){
            if (!is_full()){
                _tail++;
                _stack[_tail]=x;
                _size++;
            }
            else{
                cout << "Stack is full!\n";
            }
        }

        T top() const{
            if (!is_empty()){
                return _stack[_tail];
            }
            else{
                cout<<"Stack is empty!\n";
            }
            
        }

        T pop() const{
            if (!is_empty()){
                T ret = _stack[_tail];
                _tail--;
                _size--;
                return ret;
            }  
            else{
                cout<<"Stack is empty!\n";
            }          
        }

        int size(){
            return _size;
        }

        bool is_full(){
            if (_size==_capacity){
                return true;
            }
            else{
                return false;
            }
        }

        bool is_empty(){
            if (_size==0){
                return true;
            }
            else{
                return false;
            }
        }
};

template < typename T>
class Queue{
    private:
        T *_queue;
        int _size;
        int _head;
        int _capacity;

    public:
        Queue(int cap){
            _queue = new T [cap];
            _size=0;
            _head=0;
            _capacity=cap;
        }

        ~Queue(){
            delete [] _queue;
        }

        void enqueue(const T& x){
            if (!is_full()){
                _queue[_size]=x;
                _size++;
            }
            else{
                cout << "Queue is full!\n";
            }
        }

        T first(){
            if (!is_empty()){
                return _queue[_head];
            }
            else{
                cout<<"Queue is empty!\n";
                return 1;
            }
            
        }

        T dequeue(){
            if (!is_empty()){
                T ret = _queue[_head];
                _head++;
                _size--;
                return ret;
            }  
            else{
                cout<<"Queue is empty!\n";
                return 1;
            }          
        }

        int size(){
            return _size;
        }

        bool is_full(){
            if (_size==_capacity){
                return true;
            }
            else{
                return false;
            }
        }

        bool is_empty(){
            if (_size==0){
                return true;
            }
            else{
                return false;
            }
        }
};

template <class T>
class CircularQueue{
    private:
        T *_arr;
        int _front,_rear, _capacity;

    public:
        CircularQueue(int cap){
            _capacity = cap +1; // 1 extra space to different b/w full and empty
            _arr = new T[_capacity];
            _front= _rear=0;
        }

        bool is_empty(){
            return _front== _rear;
        }

        bool is_full(){
            return (_rear +1) % _capacity == _front;
        }

        void enqueue(const T& val){
            if (is_full()){
                cout <<"Queue is full\n";
                return;
            }
            _arr[_rear]=val;
            _rear=(_rear+1)%_capacity;
        }

        T& dequeue(){
            if (is_empty()){
                throw std::underflow_error("Queue is empty");
            }

            T& ret= _arr[_front];
            _front = (_front +1) %_capacity;

            return ret;
        }
};

int main(){
    /*
    Stack<int> Arr(5);
    Arr.Push(10);
    Arr.Push(20);
    Arr.Push(30);

    cout << "Top element: " << Arr.top() << endl; // Should print 30

    cout << "Stack size: " << Arr.size() << endl; // Should print 3

    while (!Arr.is_empty()) {
        cout << "Popped: " << Arr.pop() << endl;
    }
    */

    Queue<int> Array(5);
    Array.enqueue(11);
    Array.enqueue(21);
    Array.enqueue(31);

    cout << "Top element: " << Array.first() << endl; // Should print 30

    cout << "Queue size: " << Array.size() << endl; // Should print 3

    while (!Array.is_empty()) {
        cout << "Popped: " << Array.dequeue() << endl;
    }
    return 0;
}