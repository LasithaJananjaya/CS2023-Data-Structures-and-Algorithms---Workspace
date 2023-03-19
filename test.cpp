vector<int> rotateLeft(int d, vector<int> arr) {
    int n = arr.size();

    for (int i=0; i<d; i++){
        int temp_var = arr[0];
        int j = 0;

        while (j<n-1){
            arr[j] = arr[j+1];
            j = j+1;
        }
        arr[n-1] = temp_var;
    }

    return arr;
}