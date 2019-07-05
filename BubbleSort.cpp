#include <array>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;

template<typename T, size_t size>
void bubbleSort(array<T, size> &items);

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
	
	bubbleSort(data);	// sort the array

	cout << "\nSorted array:\n";
	for(size_t i = 0; i < arraySize; i++) cout << setw(4) << data[i];
	
	cout << endl;

	return 0;
}

template<typename T, size_t size>
void bubbleSort(array<T, size> &items) {
	int temp;
	for(size_t i = items.size(); i > 0; i--) {
		for(size_t j = 0; j < i - 1; j++) {
			if(items[j + 1] < items[j]) {
				temp = items[j + 1];
				items[j + 1] = items[j];
				items[j] = temp;
			}
		}
	}
}