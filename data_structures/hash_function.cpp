#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <cstdint>
#include<sstream>
using namespace std;

class clsHash {
public:

	string Hash32(string str) {
		//constants used in hashing algo
		const uint32_t OffsetBasis = 2166136261;
		const uint32_t FNVPrime = 16777619;
		
		//hashing algo
		uint32_t hash = OffsetBasis;
		for (char c : str) {
			hash ^= c;
			hash *= FNVPrime;
		}

		stringstream s;
		s << hex << hash;
		string result = s.str();
		return result;
	}

	string Hash64(string str) {
		//constants used in hashing algo
		const uint64_t OffsetBasis = 14695981039346656037ull;
		const uint64_t FNVPrime = 1099511628211ull;

		//hashing algo
		uint64_t hash = OffsetBasis;
		for (char c : str) {
			hash ^= c;
			hash *= FNVPrime;
		}

		stringstream s;
		s << hex << hash;
		string result = s.str();
		return result;
	}
};

int main() {
	
	clsHash hash1;
	string result = hash1.Hash64("ahmed");
	cout << result << endl;

	return 0;
}
