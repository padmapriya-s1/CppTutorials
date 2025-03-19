#include <iostream>
using namespace std;

int main(){
    int maxsize=100;
    char name[maxsize];
    cout << "Hello! Who are you?\n";
    cin.getline(name,maxsize);
    cout << "Hello"<< name << "!\n";

    int age;
    
    cout << "What is your age?\n";
    cin >> age;

    if (age >= 18){
        cout << "You can vote\n";

    }

    else{
        cout << "You cannot vote\n";
    }

}
