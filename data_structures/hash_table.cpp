#include <iostream>
using namespace std;
#include"hash_table.h"

int main() {
	
	clsHashtable h3(3);
	h3.Set(1, "one");
	h3.Set(2, "two");
	h3.Set(3, "three"); // triggers resize
	h3.Set(4, "four");
	h3.Display();       // Expect all 4 entries preserved
	cout << "===========\n";
	cout << h3.Get(1) << endl;


	return 0;
}
