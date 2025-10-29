#include<iostream>
using namespace std;


void insertionSort(int arr[], int size){
    int key;
    for(int i = 1; i < size; i++){
        key = arr[i];
        int j;
        for(j = i - 1; j >= 0; --j){
            if(arr[j] > key){
                arr[j+1] = arr[j];
                arr[j] = key;
            }else{
                arr[j+1] = key;
            }
        }
        
    }
}

void display(int arr[], int size){
    for(int i = 0; i< size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int arr[4] = {5, 4, 1, 3};
    display(arr, 4);
    insertionSort(arr, 4);
    display(arr, 4);

    return 0;
}