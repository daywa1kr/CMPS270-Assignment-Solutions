#include "my_arrays.h"
/*
	Requires: an integer array
	Effects: prints the array out
	Assumes: size of array is 10
*/
void printArray(int* array) {
	printf("Index Value\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%5d%6d\n", i, array[i]);
	}
}

/*
	Requires: an integer array
	Effects: prints a histogram representing the frequency of each element
	Assumes: size of array is 10
*/
void arrayHistogram(int* array) {
	printf("Value Frequency Histogram\n");
	int count = 0;

	for (int i = 1; i <= 3; i++) {
		count = 0;
		for (int j = 0; j < SIZE; j++) {
			if (array[j] == i)
				count++;
		}
		printf("%5d%10d", i, count);
		for (int i = 0; i < SIZE - count; i++) {
			printf(" ");
		}
		for (int i = 0; i < count; i++) {
			printf("*");
		}
		printf("\n");
	}
}

/*
	Requires: an integer array, 2 integers between 0 and 9 representing 2 indeces
	Effects: swaps values at i and j
	Assumes: size of array is 10
*/
void swapValues(int* array, int i, int j) {
	if (i > 9 || i < 0)
		return;
	
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/*
	Requires: an int array
	Effects: sorts it with bubble sort
	Assumes: size of array is 10
*/
void bubbleSort(int* array) {
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swapValues(array, j, j + 1);
			}
		}
	}
}

/*
	Requires: an int array
	Effects: returns the median
	Assumes: size of array is 10
*/
int median(int* array) {
	bubbleSort(array);
	return array[SIZE / 2];
}

/*
	Requires: an int array
	Effects: returns the mode
	Assumes: size of array is 10
*/
int mode(int* array) {
	int max = -1;
	int count = 0;
	int mode;

	for (int i = 0; i < SIZE; i++) {
		count = 0;
		for (int j = 0; j < SIZE; j++) {
			if (array[i] == array[j]) {
				count++;
			}
		}
		if (count > max) {
			max = count;
			mode = array[i];
		}
	}
	return mode;
}

/*
	Requires: an int array
	Effects: if array is sorted retruns 1 else returns 0
	Assumes: size of array is 10
*/
int isSorted(int* array) {
	for (int i = 0; i < SIZE-1; i++) {
		if (array[i] > array[i + 1])
			return 0;
	}
	return 1;
}

int main_3() {
	int a[SIZE] = { 1, 1, 1, 1, 1, 2, 2, 2, 3, 3 };
	printArray(a);
	arrayHistogram(a);
	swapValues(a, 0, 9);
	printArray(a);
	printf("isSorted a: %d\n", isSorted(a));

	int b[SIZE] = { 3, 2, 1, 2, 1, 3, 1, 2, 1, 1 };
	bubbleSort(b);
	printArray(b);
	printf("median: %d\n", median(a));
	printf("mode: %d\n", mode(a));
	printf("isSorted b: %d\n", isSorted(b));

	return 0;
}