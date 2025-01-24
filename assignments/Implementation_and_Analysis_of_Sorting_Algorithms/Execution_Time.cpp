#include <iostream>
#include <chrono>
#include <random>
#include <fstream> // Include fstream for file writing

using namespace std;

// Function to print the array (optional)
template <typename T>
void PrintArray(T a[], int size) {
    for (int k = 0; k < size; k++) {
        cout << a[k] << "\n";
    }
}

// Algorithm to get the minimum element in an array
int getMin(int a[], int i, int j) {
    int min = i;
    for (int k = i + 1; k <= j; k++) {
        if (a[k] < a[min]) {
            min = k;
        }
    }
    return min;
}

// Selection Sort
int SelectionSort(int a[], int size) {
    for (int k = 0; k <= size - 1; k++) {
        int min_ind = getMin(a, k, size - 1);
        swap(a[k], a[min_ind]);
    }
    return 0;
}

// Insertion Sort
int InsertionSort(int a[], int size) {
    for (int j = 1; j <= size - 1; j++) {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 and a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
    return 0;
}

// Merge function
int Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + j + 1];
    }
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {
        if ((j >= n2) || (i < n1 && L[i] <= R[j])) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    return 0;
}

// Merge Sort
int MergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
    return 0;
}

// Main function
int main() {
    // Creating the list to be sorted
    float S[100];
    float I[100];
    float M[100];

    for (int n = 1; n <= 100; n++) {
        int x[n];
        // Initialize array with random values
        for (int i = 0; i < n; i++) {
            x[i] = rand() % 1000;  // Increase range for larger numbers
        }
        int temp[n];

        // Repeat the sorting algorithms 100 times to get better timing
        double totalSelectionTime = 0;
        double totalInsertionTime = 0;
        double totalMergeTime = 0;

        for (int repeat = 0; repeat < 100; repeat++) {
            // Copy the array to temp for each sorting algorithm
            for (int i = 0; i < n; i++) {
                temp[i] = x[i];
            }

            // Selection Sort
            auto start1 = chrono::high_resolution_clock::now(); // Start timing
            SelectionSort(temp, n);
            auto end1 = chrono::high_resolution_clock::now(); // End timing
            chrono::duration<double> elapsed1 = end1 - start1;
            totalSelectionTime += elapsed1.count(); // Accumulate time

            // Reset array to original order
            for (int i = 0; i < n; i++) {
                temp[i] = x[i];
            }

            // Insertion Sort
            auto start2 = chrono::high_resolution_clock::now(); // Start timing
            InsertionSort(temp, n);
            auto end2 = chrono::high_resolution_clock::now(); // End timing
            chrono::duration<double> elapsed2 = end2 - start2;
            totalInsertionTime += elapsed2.count(); // Accumulate time

            // Reset array to original order
            for (int i = 0; i < n; i++) {
                temp[i] = x[i];
            }

            // Merge Sort
            auto start3 = chrono::high_resolution_clock::now(); // Start timing
            MergeSort(temp, 0, n - 1);
            auto end3 = chrono::high_resolution_clock::now(); // End timing
            chrono::duration<double> elapsed3 = end3 - start3;
            totalMergeTime += elapsed3.count(); // Accumulate time
        }

        // Store the average time for each algorithm
        S[n - 1] = totalSelectionTime / 100;
        I[n - 1] = totalInsertionTime / 100;
        M[n - 1] = totalMergeTime / 100;
    }

    // Create and open a CSV file for writing
    ofstream file("sorting_times.csv");

    // Check if the file is open and write the data
    if (file.is_open()) {
        // Write the header for the CSV file
        file << "Array_Size,Selection_Sort_Time,Insertion_Sort_Time,Merge_Sort_Time\n";

        // Write the data for each algorithm
        for (int n = 1; n <= 100; n++) {
            file << n << "," << S[n - 1] << "," << I[n - 1] << "," << M[n - 1] << "\n";
        }

        // Close the file after writing
        file.close();
        cout << "Data successfully saved to 'sorting_times.csv'\n";
    } else {
        cout << "Failed to open the file.\n";
    }

    return 0;
}
