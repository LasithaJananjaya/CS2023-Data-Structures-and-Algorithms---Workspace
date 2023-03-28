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

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        quickSort(arr, left, j);
        quickSort(arr, i, right);
    }
}

int main() {
    
    
    int size = 1000000;
    int array[size];
    
    int count = 0;
    int no_of_tests = 10;
    int time_array[no_of_tests];
    while (count < no_of_tests){
    
    srand(time(NULL));
    
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; 
    }

    //int size = sizeof(array) / sizeof(array[0]);
    //array_display(array, size);

    auto start = high_resolution_clock::now();
    quickSort(array, 0, size - 1);
    auto end = high_resolution_clock::now();

    //array_display(array, size);

    auto elapsed_time_ms = duration_cast<milliseconds>(end - start);
    cout << "Time taken by quickSort() in milliseconds: " << elapsed_time_ms.count() << endl;
    time_array[count] = elapsed_time_ms.count();
    count++;
    
    }
    
    array_display(time_array, no_of_tests);
    
    int avg;
    for(int i = 0; i < no_of_tests; i++){
        avg += time_array[i];
    }
    avg = avg/no_of_tests;
    
    cout << "Average time taken by quickSort() in milliseconds: " << avg << endl;

    return 0;
}