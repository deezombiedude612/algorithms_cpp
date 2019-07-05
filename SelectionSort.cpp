#include <array>
#include <iomanip>
#include <iostream>
using namespace std;

/* sort an array into ascending order */
template <typename T, size_t size>
void selectionSort(array<T, size> &items) {
	for(size_t i = 0; i < items.size() - 1; i++) {
		size_t indexOfSmallest = i;		// holds index of smallest element

		for(size_t index = i + 1; index < items.size(); index++) 	// loop to find index of smallest element
			if(items[index] < items[indexOfSmallest]) 
				indexOfSmallest = index;
		
		/* swap the elements at positions i and indexOfSmallest */
		T hold = items[i];
		items[i] = items[indexOfSmallest];
		items[indexOfSmallest] = hold;
	}
}

int main(int argc, char **argv) {
	const size_t arraySize = 10;		// size of array
	array<int, arraySize> data = {34, 56, 4, 10, 77, 51, 93, 30, 5, 52};
	
	cout << "Unsorted array:\n";
	for(size_t i = 0; i < arraySize; i++) cout << setw(4) << data[i];	// output original array
	cout << endl;
	
	selectionSort(data);	// sort the array

	cout << "\nSorted array:\n";
	for(size_t i = 0; i < arraySize; i++) cout << setw(4) << data[i];
	
	cout << endl;
	return 0;
}