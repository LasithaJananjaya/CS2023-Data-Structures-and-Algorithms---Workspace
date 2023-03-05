#include <iostream>
#include <vector>

void insertionSort1(int n, vector<int> arr) {

    int temp = arr[n-1];
    int escape = 0;

    if (n==1){
        for (int j = 0; j < n; j++) {
                std::cout << arr[j] << " ";
            }
        std::cout << std::endl;
    }

    else{
        for (int i = n - 2; i > -1; i--){

            if (temp < arr[i]){
                
                arr[i+1] = arr[i];
                
                if (i==0)
                {
                    arr[i] = temp;
                }
                
            }
             

            else{
                arr[i+1] = temp;
                escape = 1;
            }

            for (int j = 0; j < n; j++) {
                    std::cout << arr[j] << " ";
                }
            std::cout << std::endl;

            if (escape == 1){
                i = 0;
            }
        }
    }

}

int main(){
    int n; //length of the array
    // int arr[n]; //array

    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Print the elements of the array to STDOUT
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

}