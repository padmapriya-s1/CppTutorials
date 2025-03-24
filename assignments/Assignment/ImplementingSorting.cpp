#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//Selection Sort already done in the previous file


//Insertion Sort
int InsertionSort(int A[],int s,int f){
    for (int j=s+1; j<=f; j++){
        int key = A[j];
        int i = j-1;
        while ((i>= 0) && (A[i]> key)){
            A[i+1]=A[i];
            i = i -1;
        }
        A[i+1]=key;
    }
    return A[f-s+1];
}

// Merge
void Merge(int A[], int p, int q, int r){
    int nl= q-p+1, nr= r-q;
    int Left[nl], Right[nr];

    for (int i=0; i<=nl; i++){ Left[i]=A[p+i];}
    for (int i=0; i<=nr; i++){ Right[i]=A[q+1+i];}

    int i=0,j=0,k=p;

    while( (i<nl) && (j<nr)){

    if (Left[i]<Right[j]){
        A[k]=Left[i];
        i++;
    }
    else{
        A[k]=Right[j];
        j++;
    }
    k++;
    }

    while (i<nl){
        A[k]=Left[i];
        i++;
        k++;
    }

    while (j<nr){
        A[k]=Right[j];
        j++;
        k++;
    }

    return;
}

//Merge Sort

void MergeSort(int A[],int p, int r){
    if(p>=r){
        return;
    }

    int q = p + ( r - p)/2;
    MergeSort(A, p, q);
    MergeSort(A,q+1,r);
    Merge(A,p,q,r);
}

//Quick Sort

int Partition(int A[], int p, int r){
    int pivot = A[r];
    int i=p-1;
    for(int j=p; j<=r; j++){
        if (A[j]<pivot){
            i++;
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    A[r]= A[i+1];
    A[i+1]= pivot;
    return i+1;
}

void QuickSort(int A[],int p,int r){
    if (p<r){
        int pivot = Partition(A, p, r);
        QuickSort(A,p,pivot-1);
        QuickSort(A,pivot+1,r);
    } 
}

//Randomized Quick Sort
void RandomizedQuickSort(int A[],int p, int r){
    int k = p + rand() % (r - p + 1); // Random index in range [p, r]
    int temp=A[r];
    A[r]=A[k];
    A[k]=temp;
    if (p<r){
        int pivot = Partition(A, p, r);
        QuickSort(A,p,pivot-1);
        QuickSort(A,pivot+1,r);
    }     
}

int main(){
    int maxsize=5;
    int L[maxsize] ={6,8,3,23,4};

    /*
    //Insertion sort
    L[maxsize] = InsertionSort(L,0,4);

    cout << "The sorted array is:\n";

    for (int i=0; i< maxsize; i++){
        cout<< L[i]<<endl;
    }
    */

    /*
    //Merge
    MergeSort(L,0,maxsize-1);
    cout << "The sorted array is:\n";

    for (int i=0; i< maxsize; i++){
        cout<< L[i]<<endl;
    }
    */

    //Quick Sort
    RandomizedQuickSort(L,0,maxsize-1);
    cout << "The sorted array is:\n";

    for (int i=0; i< maxsize; i++){
        cout<< L[i]<<endl;
    }
    return 0;
}

