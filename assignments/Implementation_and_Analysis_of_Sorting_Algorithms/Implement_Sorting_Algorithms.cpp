#include <iostream>

using namespace std;

/*
Implement Sorting Algorithms
  (a) Selection Sort
  (b) Insertion Sort
  (c) Merge Sort
*/

//Function to print the array
int PrintArray(int a[],int size){
  for (int k=0; k<= size-1; k++){
    cout << a[k]<< "\n";
  }
  return 0;
}

//Algorithm to get the minimum element in an array
int getMin(int a[], int i, int j) {
  int min = i;
  for(int k = i + 1; k <= j; k++) {
    if (a[k] < a[min]) {
      min = k;
    }
  }
  return min;
}

//Selection Sort
int SelectionSort(int a[],int size){
  for (int k =0; k <= size-1; k++){
    int min_ind = getMin(a,k,size-1);
    swap(a[k],a[min_ind]);
  }
  return 0;
}

//Insertion Sort
int InsertionSort(int a[], int size){
  for(int j=1;j<= size-1; j++){
    int key = a[j];
    int i=j-1;
    while(i>=0 and a[i]>key){
      a[i+1]=a[i];
      i=i-1;
    }
    a[i+1]=key;
  }
  return 0;
}

//Merge function
int Merge(int A[],int p,int q,int r){
    int n1 = q - p +1;
    int n2 = r - q;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++){
        L[i] = A[p+i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = A[q+j+1];
    }
    int i=0; int j=0;
    for (int k = p; k <= r; k++){
        if ((j >= n2) || (i < n1 && L[i] <= R[j])){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
    return 0;
}

//Merge sort
int MergeSort(int A[],int p,int r){
    if (p < r){
        int q = (p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
    return 0;
}

//Main function
int main() {
  int x[] = {4, 5, 1, 9, 10, 2, 11, 12};
  int y = getMin(x, 0, 7);
  cout << "Min is at loc " << y << " value " << x[y] << endl;
  //SelectionSort(x,8);
  //InsertionSort(x,8);
  MergeSort(x,0,8);
  cout<< "Sorted array is\n";
  PrintArray(x,8);
  return 0;
}
