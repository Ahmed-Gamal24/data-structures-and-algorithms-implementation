#include <iostream>
#include <vector>
using namespace std;


class clsKeyValuePair {
private:
	int _key;
	string _value;

public:
	clsKeyValuePair() {
		
	}
	clsKeyValuePair(int key, string value) {
		_key = key;
		_value = value;
	}

	void SetKey(int key) {
		_key = key;
	}
	int GetKey() {
		return _key;
	}

	void SetValue(string value) {
		_value = value;
	}
	string GetValue() {
		return _value;
	}
};

class clsDictionary {
private:
	int _initialSize;
	int _pairsCount = 0;
	clsKeyValuePair* arr;

	void copy(clsKeyValuePair *receiverArr, int sizeReceiverArr, clsKeyValuePair *senderArr) {
		for (int i = 0; i < sizeReceiverArr; ++i) {
			receiverArr[i] = senderArr[i];
		}
	}

	void resize() {
		//determine the new size of the new array
		int newSize = _initialSize * 2;
		//create the new array
		clsKeyValuePair* newArr = new clsKeyValuePair[newSize];
		//copy the pairs from the old array to the new array
		copy(newArr, _initialSize, arr);
		//update the size of the dictionary
		_initialSize = newSize;
		//delete the old array
		delete[] arr;
		//update the pointer of the dictionary forward to the new array
		arr = newArr;

	}

	bool isFull() {
		return _pairsCount == _initialSize;
	}

	bool isEmpty() {
		return _pairsCount == 0;
	}

	int isKeyExist(int key) {
		for (int i = 0; i < _pairsCount; ++i) {
			if (arr[i].GetKey() == key) {
				return i;
			}
		}
		return -1;
	}


public:
	clsDictionary(int initialSize) {
		_initialSize = initialSize;
		arr = new clsKeyValuePair[_initialSize];
	}

	void Set(int key, string value) {
		if (isKeyExist(key) != -1) {
			arr[isKeyExist(key)].SetValue(value);
		}
		else {
			if (isFull()) {
				resize();
			}
			clsKeyValuePair newPair(key, value);
			arr[_pairsCount] = newPair;
			_pairsCount++;
		}
		
	}

	string Get(int key) {
		int index = isKeyExist(key);
		if (index != -1) {
			return arr[index].GetValue();
		}
		return "The Entered Key is Not Exist!";
	}

	void DisplayDic() {
		for (int i = 0; i < _pairsCount; ++i) {
			cout << arr[i].GetKey() << " : " << arr[i].GetValue() << endl;
		}
	}

	void Remove(int key) {
		int indexOfRemovedItem = isKeyExist(key);
		if (indexOfRemovedItem != -1) {
			//move the last pair in the removed index
			_pairsCount--;
			arr[indexOfRemovedItem] = arr[_pairsCount];
		}
		else {
			cout << "The Key You Want to Remove is Not Exist!" << endl;
		}
	}

	int Size() {
		return _pairsCount;
	}
};


int main() {
	
	clsDictionary dic1(4);

	dic1.Set(1, "ahmed");
	dic1.Set(2, "ali");
	dic1.Set(3, "omar");

	cout << "size = " << dic1.Size() << endl;

	dic1.DisplayDic();

	return 0;
}
