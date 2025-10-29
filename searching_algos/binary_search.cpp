#include <iostream>
using namespace std;

int binarySearch(int arr[], int arr_len, int target)
{

    int low = 0;
    int high = arr_len - 1;
    int mid = 0;

    while (low <= high)
    {
        mid = (high + low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

