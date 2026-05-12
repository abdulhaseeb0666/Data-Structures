#include<iostream>
using namespace std;

int main(){
    int arr[5];

    cout<<"Enter 5 numbers: \n";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }

    cout<<"Unsorted nArray: \n";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"\t";
    }

    // Selection Sort Algorithm
    for(int i=0;i<4;i++){
        int min = i;
        for(int j=i+1;j<5;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        if(min!=i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

    cout<<"\nSorted Array: \n";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"\t";
    }
}