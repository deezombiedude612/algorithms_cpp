#include <iomanip>
#include <iostream>
using namespace std;

const int SIZE = 12;	// constant size defined for bucketSort to work

void bucketSort(int []);
int numberOfDigits(int [], int);
void distributeElements(int [], int [][SIZE], int);
void collectElements(int[], int [][SIZE]);
void zeroBucket(int [][SIZE]);

int main(int argc, char **argv) {
	int array[SIZE] = {19, 13, 5, 27, 1, 26, 31, 16, 2, 9, 11, 21};

	cout << "Array elements in original order: \n";
	for(int i = 0; i < SIZE; i++) cout << setw(3) << array[i];
	cout << endl;

	bucketSort(array);

	cout << "Array elements in sorted order: \n";
	for(int i = 0; i < SIZE; i++) cout << setw(3) << array[i];
	cout << endl;

	return 0;
}

void bucketSort(int a[]) {
	/**
	 * "A bucket sort begins with a one-dimensional array of positive integers 
	 * to be sorted and a two-dimensional array of integers with rows indexed from 
	 * 0 to 9 and columns indexed from 0 to n-1, where n is the number of values to 
	 * be sorted. Each row of the two-dimensional array is referred to as a bucket."
	 * 
	 * - Paul & Harvey Deitel, C++: How to Program 9e
	 */
	int totalDigits, bucket[10][SIZE] = {0};

	totalDigits = numberOfDigits(a, SIZE);

	for(int i = 1; i <= totalDigits; i++) {
		distributeElements(a, bucket, i);
		collectElements(a, bucket);

		if(i != totalDigits) zeroBucket(bucket);	// set all bucket contents to 0
	}
}

int numberOfDigits(int b[], int arraySize) {
	int largest = b[0], digits = 0;

	for(int i = 1; i < arraySize; i++)
		if(b[i] > largest)
			largest = b[i];
		
	while(largest != 0) {
		digits++;
		largest /= 10;
	}

	return digits;	
}

/* distribute elements into buckets based on specified digit */
void distributeElements(int a[], int buckets[][SIZE], int digit) {
	int divisor = 10, bucketNumber, elementNumber;

	for(int i = 1; i < digit; i++) divisor *= 10;	// determine divisor used to get specific digit

	for(int k = 0; k < SIZE; k++) {
		/**
		 * bucketNumber example for hundreds digit:
		 * (1234 % 1000 - 1234 % 100) / 100 --> 2
		 */
		bucketNumber = (a[k] % divisor - a[k] % (divisor / 10)) / (divisor / 10);

		/**
		 * retrieve value in buckets[bucketNumber][0] to determine which
		 * element of the row to store a[i] in
		 */
		elementNumber = ++buckets[bucketNumber][0];
		buckets[bucketNumber][elementNumber] = a[k];
	}
}

/* return elements to original array */
void collectElements(int a[], int buckets[][SIZE]) {
	int subscript = 0;

	for(int i = 0; i < 10; i++)
		for(int j = 1; j <= buckets[i][0]; j++)
			a[subscript++] = buckets[i][j];
}

/* set all buckets to 0 */
void zeroBucket(int buckets[][SIZE]) {
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < SIZE; j++)
			buckets[i][j] = 0;
}