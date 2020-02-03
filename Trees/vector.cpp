#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	// Push back checks size of array and increases accordingly
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	v[1] = 100;
	v[3] = 1002;
	v[4] = 1234;	
	// SHOULD NEVER ADD/INSERT LIKE THIS | GOES OUT FROM SIZE OF ARRAY

	v.push_back(23);   // Will be added after 30 | ignore v[4] = 1234
	v.push_back(234);

	//ONLY USE v[] for GET/PRINT and UPDATE

	for(int i=0; i<v.size();i++) {
		cout << v[i] << endl;
	}	
	
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() <<endl;

	cout << v.at(2) << endl;
	//cout << v.at(6) <<	endl;	// OUT OF RANGE ERROR
	// SAFER TO USE at than v[]

	v.pop_back();	// REMOVE LAST ELEMENT
}
