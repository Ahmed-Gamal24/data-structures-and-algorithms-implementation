#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> arr)
{
    vector<int> newArr;

    int smallestItem = arr[0];
    int smallestIndex = 0;
    while (arr.size() >= 1)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] < smallestItem)
            {
                smallestItem = arr[i];
                smallestIndex = i;
            }
        }

        newArr.push_back(smallestItem);
        arr.erase(arr.begin() + smallestIndex);
        smallestItem = arr[0];
        smallestIndex = 0;
    }

    return newArr;
}

void displayVector(const vector<int> &arr)
{
    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {4, 8, 2, 0};
    vector<int> sortedArr = selectionSort(arr);
    displayVector(sortedArr);

    return 0;
}