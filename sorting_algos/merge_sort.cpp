#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>& v, int start, int mid, int end) {
	int leftLength = mid - start + 1;
	int rightLength = end - mid;

	vector<int> leftArray;
	vector<int> rightArray;

	for (int i = start; i <= mid; ++i) {
		leftArray.push_back(v[i]);
	}
	for (int i = mid + 1; i <= end; ++i) {
		rightArray.push_back(v[i]);
	}

	int i = 0;
	int j = 0;
	int k = start;
	while (i < leftLength && j < rightLength) {
		if (leftArray[i] < rightArray[j]) {
			v[k++] = leftArray[i++];
		}
		else {
			v[k++] = rightArray[j++];
		}
	}

	while (i < leftLength) {
		v[k++] = leftArray[i++];
	}
	while (j < rightLength) {
		v[k++] = rightArray[j++];
	}
}
void mergeSort(vector<int> &v, int start, int end) {
	//base case
	if (end <= start) {
		return;
	}

	//recursive case
	int mid = (end + start) / 2;
	mergeSort(v, start, mid);
	mergeSort(v, mid + 1, end);
	merge(v, start, mid, end);
}


int main(){


    return 0;
}