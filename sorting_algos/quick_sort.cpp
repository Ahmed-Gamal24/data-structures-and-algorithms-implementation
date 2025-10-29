#include <iostream>
#include <vector>
using namespace std;

int choosePivotIndex(vector<int>& v) {
	int first = 0;
	int mid = v.size() / 2;
	int last = v.size() - 1;

	// find the median of first, mid, last
	if ((v[first] > v[mid]) != (v[first] > v[last])) return first;
	else if ((v[mid] > v[first]) != (v[mid] > v[last])) return mid;
	else return last;
}

vector<int> quickSort(vector<int> v) {
	//base case 
	if (v.size() < 2) return v;

	//recursive case
	int pivotIndex = choosePivotIndex(v);
	int pivot = v[pivotIndex];
	vector<int> smallers;
	vector<int> largers;
	for (int i = 0; i < v.size(); ++i) {
		if (i == pivotIndex) {
			continue;
		}
		if (v[i] <= pivot) {
			smallers.push_back(v[i]);
		}
		else if (v[i] > pivot) {
			largers.push_back(v[i]);
		}
	}

	vector<int> sortedSmallers = quickSort(smallers);
	vector<int> sortedLargers = quickSort(largers);

	sortedSmallers.push_back(pivot);
	sortedSmallers.insert(sortedSmallers.end(), sortedLargers.begin(), sortedLargers.end());

	return sortedSmallers;
}


int main(){

    return;
}