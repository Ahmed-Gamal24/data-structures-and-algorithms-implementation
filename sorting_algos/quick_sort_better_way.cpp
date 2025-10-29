#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &v, int start, int end){//will return pivot index
    int pivotIndex = end;
    int pivot = v[end];
    int i = start - 1;
    int temp = 0;
    for(int j = start; j < end; ++j){
        if(v[j] < pivot){
            i++;
            //swap v[j] with v[i]          
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    //swap between pivot and v[i+1]
    i++;
    temp = v[pivotIndex];
    v[pivotIndex] = v[i];
    v[i] = temp;

    return i;
}

void quickSort(vector<int> &v, int start, int end){
    //base case
    if(end <= start) return;

    //recursive case
    int pivot = partition(v, start, end);
    quickSort(v, start, pivot-1);
    quickSort(v, pivot+1, end);
}

void displayVector(vector<int> v){
    for(int item : v){
        cout << item << " ";
    }
    cout << endl;
}

int main(){

    vector<int> v = {2, 8, 5, 4, 6, 7};
    quickSort(v, 0, v.size()-1);
    displayVector(v);

    return 0;
}