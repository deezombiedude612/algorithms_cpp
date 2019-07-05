/* Linear search of an array */

#include <iostream>
#include <array>
using namespace std;

/* Compare key to every element of array until location is
 * found or until end of array is reached; return location of
 * element if key is found or -1 if key is not found
 */
template<typename T, size_t size>
int linearSearch(const array<T, size> &items, const T &key) {
	for(size_t i = 0; i < items.size(); i++)
		if(key == items[i]) return i;		// if found, return location of key

	return -1;	// key not found
}

int main(int argc, char **argv) {
	const size_t arraySize = 100;			// size of array
	array<int, arraySize> arrayToSearch;	// create array
	
	for(size_t i = 0; i < arrayToSearch.size(); i++) arrayToSearch[i] = 2 * i;	// create some data

	cout << "Enter integer search key >> ";
	int searchKey;	// value to locate
	cin >> searchKey;

	// attempt to locate searchKey in arrayToSearch
	int element = linearSearch(arrayToSearch, searchKey);

	// display results
	if(element != -1) cout << "Found value in element " << element << endl;
	else cout << "Value not found\n";

	return 0;
}