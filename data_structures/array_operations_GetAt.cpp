#include<iostream>
using namespace std;


int GetAt(int *&arr, int size, int index){
    if(index < 0 || index >= size) return -1;
     
    int* address = arr + index;
    return *address;
}


int main(){
    int size = 3;
    int* arr = new int[size] {1, 25, 33};
    cout << GetAt(arr, size, 2);

    return 0;
}