#include<iostream>
using namespace std;

// Merge function (simple version)
void merge(int arr[], int left, int mid, int right){
    
    int temp[10];  // temporary array (enough for small inputs)
    
    int i = left;      // left part start
    int j = mid + 1;   // right part start
    int k = left;      // temp index

    // compare and merge
    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // copy remaining left part
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    // copy remaining right part
    while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }

    // copy back to original array
    for(int i = left; i <= right; i++){
        arr[i] = temp[i];
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right){

    if(left < right){
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);       // left half
        mergeSort(arr, mid + 1, right);  // right half

        merge(arr, left, mid, right);    // merge
    }
}

int main(){

    int arr[5];

    cout << "Enter 5 numbers:\n";
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }

    cout << "Unsorted Array:\n";
    for(int i = 0; i < 5; i++){
        cout << arr[i] << "\t";
    }

    mergeSort(arr, 0, 4);

    cout << "\nSorted Array:\n";
    for(int i = 0; i < 5; i++){
        cout << arr[i] << "\t";
    }

    return 0;
}