#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
using namespace std::chrono;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void array_display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void quickSort(int arr[], int low, int high) {
    stack<int> stk;

    stk.push(low);
    stk.push(high);

    while (!stk.empty()) {
        int h = stk.top();
        stk.pop();
        int l = stk.top();
        stk.pop();

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            stk.push(l);
            stk.push(p - 1);
        }

        if (p + 1 < h) {
            stk.push(p + 1);
            stk.push(h);
        }
    }
}

int main() {
    
    
    int size = 400000;
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