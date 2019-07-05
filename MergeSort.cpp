#include <array>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;

/* display array elements from index low through index high */
template<typename T, size_t size>
void displayElements(const array<T, size> &items, size_t low, size_t high);
template <typename T, size_t size>
void mergeSort(array<T, size> &items, size_t low, size_t high);
template<typename T, size_t size>
void merge(array<T, size> &items, size_t left, size_t middle1, size_t middle2, size_t right);

int main(int argc, char **argv) {
	/**
	 * use the default random-number generation engine to produce
	 * uniformly distributed pseudorandom int values from 10 to 99
	 */
	default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
	uniform_int_distribution<unsigned int> randomInt(10, 99);

	const size_t arraySize = 10;		// size of array
	array<int, arraySize> data;			// create array

	/* fill data with random values */
	for(int &item: data) item = randomInt(engine);

	/* display data's values before mergeSort */
	cout << "Unsorted array: " << endl;
	displayElements(data, 0, data.size() - 1);

	mergeSort(data, 0, data.size() - 1);	// sort the array data

	/* display data's values after mergeSort */
	cout << "Sorted array: " << endl;
	displayElements(data, 0, data.size() - 1);

	return 0;
}

/* display array elements from index low through index high */
template<typename T, size_t size>
void displayElements(const array<T, size> &items, size_t low, size_t high) {
	for(size_t i = 0; i < items.size() && i < low; i++) cout << "   ";					// display spaces for alignment
	for(size_t i = low; i < items.size() && i <= high; i++) cout << items[i] << " ";	// display element

	cout << endl;
}

/* split array, sort subarrays and merge subarrays into sorted array */
template <typename T, size_t size>
void mergeSort(array<T, size> &items, size_t low, size_t high) {
	/* test base case; size of array equals 1 */
	if((high - low) >= 1) {	// if not base case
		int middle1 = (low + high) / 2;		// calculate middle of array
		int middle2 = middle1 + 1;			// calculate next element over

		/* output split step */
		cout << "Split:   ";
		displayElements(items, low, high);
		cout << "         ";
		displayElements(items, low, middle1);
		cout << "         ";
		displayElements(items, middle2, high);
		cout << endl;

		/* split array in half; sort each half (recursive calls) */
		mergeSort(items, low, middle1);		// first half of array
		mergeSort(items, middle2, high);	// second half of array

		/* merge two sorted arrays after split calls return */
		merge(items, low, middle1, middle2, high);
	}
}

/* merge two sorted subarrays into one sorted subarray */
template<typename T, size_t size>
void merge(array<T, size> &items, size_t left, size_t middle1, size_t middle2, size_t right) {
	size_t leftIndex = left;		// index into left subarray
	size_t rightIndex = middle2;	// index into right subarray
	size_t combinedIndex = left;	// index into temporary working array
	array<T, size> combined;		// working array

	/* output two subarrays before merging */
	cout << "Merge:   ";
	displayElements(items, left, middle1);
	cout << "         ";
	displayElements(items, middle2, right);
	cout << endl;

	/* merge arrays until reaching end of either */
	while(leftIndex <= middle1 && rightIndex <= right) {
		/* place smaller of two current elements into result and move to next space in array */
		if(items[leftIndex] <= items[rightIndex])
			combined[combinedIndex++] = items[leftIndex++];
		else
			combined[combinedIndex++] = items[rightIndex++];
	}

	if(leftIndex == middle2) {		// if at end of left array
		while(rightIndex <= right)	// copy in rest of right array
			combined[combinedIndex++] = items[rightIndex++];
	} else {						// at the end of right array
		while(leftIndex <= middle1)	// copy in rest of left array
			combined[combinedIndex++] = items[leftIndex++];
	}

	/* copy valuesback into original array */
	for(size_t i = left; i <= right; i++) items[i] = combined[i];

	/* output merged array */
	cout << "         ";
	displayElements(items, left, right);
	cout << endl;
}