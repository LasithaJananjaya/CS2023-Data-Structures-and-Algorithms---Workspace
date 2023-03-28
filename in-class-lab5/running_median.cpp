#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quick_sort(vector<int>& array, int left, int right);
int partition(vector<int>& array, int left, int right, int pivotIndex);
void print_array(vector<int>& array, int size);
double find_median(vector<int>& array);

int main()
{
    vector<int> array;
    int n;

    cout << "Please enter the size of the array: ";
    cin >> n;

    cout << "Please enter the array elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        array.push_back(x);

        quick_sort(array, 0, i); // sort the array so far
        cout << "Sorted array so far: ";
        print_array(array, i+1); // print the sorted array so far

        double median = find_median(array); // find the running median
        cout << "Running median: " << median << endl;
    }

    return 0;
}

void quick_sort(vector<int>& array, int left, int right)
{
    if (left < right) {
        int pivotIndex = left + (right - left) / 2;
        int pivotNewIndex = partition(array, left, right, pivotIndex);
        quick_sort(array, left, pivotNewIndex - 1);
        quick_sort(array, pivotNewIndex + 1, right);
    }
}

int partition(vector<int>& array, int left, int right, int pivotIndex)
{
    int pivotValue = array[pivotIndex];
    swap(array[pivotIndex], array[right]); // Move pivot to end
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (array[i] < pivotValue) {
            swap(array[i], array[storeIndex]);
            storeIndex++;
        }
    }
    swap(array[storeIndex], array[right]); // Move pivot to its final place
    return storeIndex;
}

void print_array(vector<int>& array, int size)
{
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

double find_median(vector<int>& array)
{
    int n = array.size();
    if (n % 2 == 0) {
        return (double)(array[n / 2 - 1] + array[n / 2]) / 2.0;
    }
    else {
        return (double)array[n / 2];
    }
}