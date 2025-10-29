#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <cstdint>
#include<sstream>
using namespace std;

class clsKeyValuePair {
private:
	int _key;
	string _value;
	bool _isUsed;

public:
	clsKeyValuePair() {
		_isUsed = false;
	}
	clsKeyValuePair(int key, string value) {
		_key = key;
		_value = value;
		_isUsed = true;
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

	bool IsUsed() {
		return _isUsed;
	}

	void MarkEmpty() {
		_isUsed = false;
	}
};

class clsHashtable {

private:
	int _size;
	int _pairsCount;
	clsKeyValuePair* arr;

	int Hash32(int key) {
		//constants used in hashing algo
		const uint32_t OffsetBasis = 2166136261;
		const uint32_t FNVPrime = 16777619;

		//hashing algo
		uint32_t hash = OffsetBasis;
		string str = to_string(key);
		for (char c : str) {
			hash ^= c;
			hash *= FNVPrime;
		}

		int hashedKay = hash % _size;
		return hashedKay;

	}

	bool isPrime(int n) {
		if (n <= 1) return false;
		if (n == 2) return true;
		if (n % 2 == 0) return false;
		for (int i = 3; i * i <= n; i += 2) {
			if (n % i == 0) return false;
		}
		return true;
	}

	int nextPrime(int n) {
		if (isPrime(n)) n++;

		while (!isPrime(n)) {
			n++;
		}
		return n;
	}

	void resize() {
		//save the old size
		int oldSize = _size;
		clsKeyValuePair* oldArr = arr;
		//determine the new size of the new array
		//remember the power of prime numbers (less collisions)
		_size = nextPrime(_size * 2);//double then find the next prime
		//create the new array
		arr = new clsKeyValuePair[_size];
		_pairsCount = 0;
		//copy the pairs from the old array to the new array
		for (int i = 0; i < oldSize; ++i) {
			if (oldArr[i].IsUsed()) {
				Set(oldArr[i].GetKey(), oldArr[i].GetValue());
			}
		}
		//delete the old array
		delete[] oldArr;

	}

	bool isFull() {
    float loadFactor = static_cast<float>(_pairsCount) / _size;
	return loadFactor > 0.7;
	}
	
	bool isEmpty() {
		return _pairsCount == 0;
	}

	bool isIndexEmpty(int index) {
		return !arr[index].IsUsed();
	}

public:
	clsHashtable(int size) {
		_size = size;
		_pairsCount = 0;
		arr = new clsKeyValuePair[size];
	}

	void Set(int key, string value) {
		int hashedKey = Hash32(key);//hashedKey is an index 
		clsKeyValuePair newPair(key, value);
		
		if (arr[hashedKey].GetKey() == key) {//key exists and just updating the value
			arr[hashedKey].SetValue(value);
		}
		else if(isIndexEmpty(hashedKey)) {//no collission
			arr[hashedKey] = newPair;
			_pairsCount++;
		}
		else {//collision happened
			if (!isFull()) {//collision happened and there is an empty place (go to linear probing)
				//implementation of linear probing
				int newHash = 0;
				for (int i = 1; i <= _size - 1; ++i) {
					newHash = (hashedKey + i) % _size;
					if (isIndexEmpty(newHash)) break;
				}
				arr[newHash] = newPair;
				_pairsCount++;
			}
			else {//collision happened and there is no empty place (go to resize) and hash again 
				resize();
				Set(key, value);
			}
		}

		
	}

	string Get(int key) {
		//map the key to hashedIndex
		int hashedKey = Hash32(key);
		/*compare the key you search for  with the key of hashedIndex
		 if the keys is equal --> return the value
		 if not --> make linear probing to find the key*/
		bool isFound = false;
		int pairKay = arr[hashedKey].GetKey();
		if (key == pairKay) {
			return arr[hashedKey].GetValue();
		}
		else {
			int newHash = 0;
			for (int i = 1; i <= _size - 1; ++i) {
				newHash = (hashedKey + i) % _size;
				if (key == arr[newHash].GetKey()) {
					isFound = true;
					break;
				}
			}		
			if (isFound) {
				return arr[newHash].GetValue();
			}
			else {
				return "Not Found!";
			}
		}
		
	}

	void Display() {
		
		for (int i = 0; i < _size; ++i) {
			if (!isIndexEmpty(i)) {
				cout << arr[i].GetKey() << " : " << arr[i].GetValue() << endl;
			}		
		}
	}

	void Remove(int key) {
		//map the key to hashedIndex
		int hashedKey = Hash32(key);
		/*compare the key you search for  with the key of hashedIndex
		 if the keys is equal --> remove
		 if not --> make linear probing to find the needed key*/
		int pairKey = arr[hashedKey].GetKey();
		if (key == pairKey) {
			//remove arr[hashedKey]
			arr[hashedKey].MarkEmpty();
		}
		else {
			int newHash = 0;
			for (int i = 1; i < _size - 1; ++i) {
				newHash = (hashedKey + i) % _size;
				if (key == arr[newHash].GetKey()) break;
			}
			//remove arr[newHash]
			arr[newHash].MarkEmpty();
		}
		_pairsCount--;
	}

	int Size() {
		return _pairsCount;
	}


	~clsHashtable() {
		delete[] arr;
	}
};
	

