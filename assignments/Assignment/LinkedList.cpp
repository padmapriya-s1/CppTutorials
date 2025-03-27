#include <iostream>
using namespace std;

template <typename T>
class LinkedList{
    private:
        class Node{
            public:
                T data;
                Node* next;

                Node(const T& value) : data(value) { next = nullptr;}
        };

        Node* head;
        Node* tail;
        int _length;
    
    public:
        LinkedList(){ head = tail = nullptr;}

        ~LinkedList(){
            Node* temp;
            while (head){
                temp = head;
                head = head -> next;
                delete temp;
            }
        }

        void append(const T& value){
            Node* newNode = new Node(value);
            if (!head){
                head=tail=newNode;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
            _length++
        }

        void prepend(const T& value){
            Node* newNode = new Node(value);
            if (!head){
                head=tail=newNode;
            }
            else{
                newNode -> next = head;
                head = newNode;
            }
            _length++
        }

        void remove(const T& value){
            if(!head) {return;}
            if (head -> data == value){
                temp= head;
                head = head-> next;
                delete head;
                _length--;

                if (head==tail){
                    head -> nullptr;
                    tail -> nullptr;
                }
            }

            Node* temp= head;
            while (temp -> next && temp -> next data != value){
                temp = temp -> next;
            }

            if (temp -> next){
                Node* toDelete = temp -> next;
                temp -> next = temp -> next -> next;
                if (!temp -> next) {tail = temp;}
                delete toDelete;
                _length--;
            }
        }
        
        int length(){
            return _length;
        }

        T& removeLast(){
            Node* temp= head;
            while (temp -> next -> next != tail){
                temp = temp -> next;
            }

            if (temp -> next = tail){
                Node* toDelete = temp -> next;
                temp -> next = nullptr;
                tail = temp;
                delete toDelete;
                _length--;
            }
        }

        T& removeFirst(){
            Node* toDelete = head;
            head = head -> next;
            delete toDelete;
            _length--;
        }

        //Implement remaining functions of sequence ADT

};