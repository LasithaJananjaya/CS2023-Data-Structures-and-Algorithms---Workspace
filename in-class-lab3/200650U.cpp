#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int max_length = 20000;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void optimisedBubbleSort(int arr[], int n) {
    bool swapped = true;
    for (int i = 0; i < n - 1 && swapped; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    for (int i = 0; i < 5; i++) {
        int n = rand() % (max_length - 500 + 1) + 500; // generate random array length in [500, 20000]
        int arr[n];
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 100; // generate random integers in [0, 99]
        }

        // perform sorting using the four algorithms
        insertionSort(arr, n);
        bubbleSort(arr, n);
        optimisedBubbleSort(arr, n);
        selectionSort(arr, n);
    }
    return 0;
}
