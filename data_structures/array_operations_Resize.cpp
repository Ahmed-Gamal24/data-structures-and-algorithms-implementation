#include<iostream>
using namespace std;


int Resize(int *&arr,int &oldSize ,int newSize){
    //validations
    if(newSize <= 0 || oldSize == 0 || newSize <= oldSize) return -1;
    //resize
    int* newArr = new int[newSize];
    for(int i = 0; i < oldSize; ++i){
        newArr[i] = arr[i];
    }
    for(int j = oldSize; j < newSize; ++j){
        newArr[j] = 0;
    }
    arr = newArr;
    oldSize = newSize;
    return 1;
} 


int main(){

    int size = 3;
    int* arr = new int[size] {1, 2, 3};
    Resize(arr, size, 5);

    for(int i = 0; i < size; ++i){
        cout << arr[i] << "  ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}