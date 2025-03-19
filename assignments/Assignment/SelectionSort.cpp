// Assignment Question 1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// GetMin(A,i,j) returns the index of the minimum element in the array A between indices i and j.

int GetMin(int A[], int i, int j){
    int min = i;

    for (int k=i; k <= j; k++){
        if (A[k] < A[min]){
            min = k;
        }
    }
    return min;
}

// SelectionSort(A,i,j)

int SelectionSort(int A[], int i, int j){
    for (int k=i; k<j;k++){
        int min, temp;
        min = GetMin(A,k,j);
        temp = A[k];
        A[k] = A[min];
        A[min]= temp;
    }
    return A[j-i+1];
}


int main(){
    //initial variables
    int maxsize = 5;
    int L[maxsize];

    // input from user
    cout<<"Enter sequence of numbers:\n";
    
    for (int i =0; i< maxsize; i++){
        cin >> L[i];
    }

    // GetMin function
    int index = GetMin(L,0,maxsize-1);

    cout<< "The minimum is:" <<L[index]<< endl;

    // SelectionSort function (input from user)
    L[maxsize]= SelectionSort(L,0,maxsize-1);

    cout<< "Sorted array is:\n";

    for (int i=0; i< maxsize; i++){
        cout << L[i] << "\n";
    }

    // SelectionSort function (input from file)
    ifstream fp("numbers.txt");

    if (!fp.is_open()){
        cerr << "error in opening";
        return 1;
    }

    // The extraction operator (>>) automatically handles whitespace, including newlines.
    int count=0;
    int num;

    while (fp >> num){
        L[count]= num;
        count++;
    }

    L[maxsize]= SelectionSort(L,0,maxsize-1);

    cout<< "Sorted array is:\n";

    for (int i=0; i< maxsize; i++){
        cout << L[i] << "\n";
    }

    //for (int i=0; i< maxsize; i++){}
    return 0;
}