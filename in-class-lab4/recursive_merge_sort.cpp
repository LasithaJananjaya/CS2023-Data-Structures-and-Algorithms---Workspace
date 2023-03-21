#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

void array_display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }
    while (i < n1) {
        array[k++] = L[i++];
    }
    while (j < n2) {
        array[k++] = R[j++];
    }
}

void mergeSort(int array[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

int main() {
    
    srand(time(NULL));
    int size = 10000000;
    int array[size];

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; 
    }

    //int size = sizeof(array) / sizeof(array[0]);
    //array_display(array, size);

    auto start = high_resolution_clock::now();
    mergeSort(array, 0, size - 1);
    auto end = high_resolution_clock::now();

    //array_display(array, size);

    auto elapsed_time_ms = duration_cast<milliseconds>(end - start);
    cout << "Time taken by mergeSort() in milliseconds: " << elapsed_time_ms.count() << endl;

    return 0;
}