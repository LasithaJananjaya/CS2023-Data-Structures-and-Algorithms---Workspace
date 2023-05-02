#include <iostream>
using namespace std;

//heapify the tree
void heapify(int array[], int n, int root)
{
    //initialize
    int largest = root;

    int left = 2 * root + 1;

    int right = 2 * root + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap(array[root], array[largest]);

        //sub-tree
        heapify(array, n, largest);
    }
}

//heap sort
void heapSort(int array[], int n)
{

    //build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    //from heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(array[0], array[i]);

        heapify(array, i, 0);
    }
}

void displayArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << "\n";
}

int main()
{
    int length;
    cout << "Please enter array length: ";
    cin >> length;

    int heap_arr[length];
    for (int i = 0; i < length; i++)
    {
        cin >> heap_arr[i];
    }
    
    int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
    cout << "Input" << endl;
    displayArray(heap_arr, n);

    heapSort(heap_arr, n);

    cout << "Output" << endl;
    displayArray(heap_arr, n);
}