#include "my_arrays.h"

void printArray(int* array) {
	printf("Index Value\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%5d%6d\n", i, array[i]);
	}
}

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

void swapValues(int* array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void bubbleSort(int* array) {
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swapValues(array, j, j + 1);
			}
		}
	}
}

int median(int* array) {
	bubbleSort(array);
	return array[SIZE / 2];
}

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