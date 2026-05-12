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

    int i = 0;
    int key = 0;

    for(int i=1 ; i<5 ; i++){
        key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;    
        }

        arr[j+1] = key;
    }

    cout<<"\nSorted Array: \n";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"\t";
    }
}