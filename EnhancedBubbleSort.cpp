#include <array>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;

template<typename T, size_t size>
void enhancedBubbleSort(array<T, size> &items);

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

	cout << "Unsorted array:\n";
	for(size_t i = 0; i < arraySize; i++) cout << setw(4) << data[i];	// output original array
	cout << endl;
	
	enhancedBubbleSort(data);	// sort the array

	cout << "\nSorted array:\n";
	for(size_t i = 0; i < arraySize; i++) cout << setw(4) << data[i];
	
	cout << endl;

	return 0;
}

template<typename T, size_t size>
void enhancedBubbleSort(array<T, size> &items) {
	int temp;
	bool proceed = true;
	for(size_t i = 0; i < items.size() && proceed; i++) {
		proceed = false;
		for(size_t j = 0; j < items.size() - i - 1; j++) {
			if(items[j] > items[j + 1]) {
				temp = items[j];
				items[j] = items[j + 1];
				items[j + 1] = temp;
				proceed = true;
			}
		}
	}
}