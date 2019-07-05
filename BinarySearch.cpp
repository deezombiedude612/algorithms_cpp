/* Binary search of an array */

#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;

/* display array elements from index low through index high */
template<typename T, size_t size>
void displayElements(const array<T, size> &items, size_t low, size_t high) {
	for(size_t i = 0; i < items.size() && i < low; i++) cout << "   ";					// display spces for alignment
	for(size_t i = low; i < items.size() && i <= high; i++) cout << items[i] << " ";	// display element

	cout << endl;
}

/* perform a binary search on the data */
template<typename T, size_t size>
int binarySearch(const array<T, size> &items, const T &key) {
	int low = 0;						// low index of elements to search
	int high = items.size() - 1;		// high index of elements to search
	int middle = (low + high + 1) / 2;	// middle element
	int location = -1;					// key's index; -1 if not found

	do {	// loop to search for element
		displayElements(items, low, high);	// display remaining elements of array to be searched

		for(int i = 0; i < middle; i++) cout << "   ";	// output spaces for alignment
		cout << " * " << endl;							// indicate current middle

		if(key == items[middle]) location = middle;		// if the element is found at the middle
		else if(key < items[middle]) high = middle - 1;	// eliminate the higher half
		else low = middle + 1;							// eliminate the lower half

		middle = (low + high + 1) / 2;		// recalculate the middle
	} while((low <= high) && (location == -1));

	return location;	// return location of key
}

/* get search key from user */
int getSearchKey() {
	int searchKey;		// value to locate
	while(true) {
		cout << "\nPlease enter an integer value (-1 to quit) >> ";
		cin >> searchKey;	// read an int from user

		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input detected! Try again.\n";
		} else break;
	}
	
	cout << endl;
	return searchKey;
}

int main(int argc, char **argv) {
	/**
	 * use the default random-number generation engine to produce
	 * uniformly distributed pseudorandom int values from 10 to 99
	 */
	default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
	uniform_int_distribution<unsigned int> randomInt(10, 99);

	const size_t arraySize = 15;			// size of array
	array<int, arraySize> arrayToSearch;	// create array

	// fill arrayToSearch with random values
	for(int &item: arrayToSearch) item = randomInt(engine);

	sort(arrayToSearch.begin(), arrayToSearch.end());	// sort the array
	
	displayElements(arrayToSearch, 0, arrayToSearch.size() - 1);	// display arrayToSearch's values

	int searchKey = getSearchKey();		// get input from user

	// repeatedly input an integer; -1 terminates the program
	while(searchKey != -1) {
		int position = binarySearch(arrayToSearch, searchKey);		// use binary search to try to find integer

		if(position == -1) 			// return value of -1 indicates integer was not found
			cout << "The integer " << searchKey << " was not found.\n";	
		else 
			cout << "The integer " << searchKey << " was found in position " << position << ".\n";

		searchKey = getSearchKey();
	}

	return 0;
}