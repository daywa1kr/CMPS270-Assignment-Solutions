#include "more_arrays.h"

/*
	Requires: a 1D array of char*, a positive int for the size of the array
	Effects: concatinates the char*s in the array with ' ' inbetween and returns char* to the result or NULL if input is invalid
	Assumes: a is not null and n is the correct size of the array		
*/
char* concatinate1D(char** a, int n) {
	int total_size = n - 1;
	size_t* lengths = malloc(n * sizeof(size_t));
	char* result, * ptr;

	for (int i = 0; i < n; i++) {
		lengths[i] = strlen(a[i]);
		total_size = lengths[i];
	}

	result = ptr = malloc(total_size * sizeof(char));
	for (int i = 0; i < n; i++) {
		memcpy(ptr, a[i], lengths[i]);
		ptr += lengths[i];
		if (i != n - 1) {
			memcpy(ptr, " ", 1);
			ptr++;
		}
	}
	*ptr = '\0';
	return result;
}

/*
	Requires: char***, a 2d array of char*s, positive ints for number of rows, number of cols
	Effects: concatinates rows and returns a pointer to the new 1d array
*/
char** concat(char*** a, int rows, int cols) {
	char** result = malloc(rows * sizeof(char*) + rows * (cols - 1) * sizeof(char));
	for (int i = 0; i < rows; i++) {
		result[i] = malloc(cols * sizeof(char*) + (cols - 1) * sizeof(char));
		char* temp = concatinate1D(a[i], cols);
		strncpy_s(result[i], cols * sizeof(char*) + (cols - 1) * sizeof(char), temp, strlen(temp));
	}
	return result;
}

int main_5() {
	int h = 2;
	int w = 3;
	char* origin[2][3] = {
		{ "I", "Love", "Coding" },
		{ "This", "Is", "Sparta" },
	};
	char*** a = malloc(sizeof(char***) * h);

	for (int i = 0; i < h; i++) {
		a[i] = malloc(sizeof(char**) * w);
		for (int j = 0; j < w; j++) {
			a[i][j] = origin[i][j];
		}
	}

	char** res = concat(a, h, w);

	for (int i = 0; i < 2; i++)
		printf("%s\n", res[i]);

	free(res);
	free(a);

	return 0;
}