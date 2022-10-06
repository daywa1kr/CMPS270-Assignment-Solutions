#include <stdio.h>
#include <stdbool.h>
#include "hamming_distance.h"

int get_hamming_distance(int a, int b) {
	int n = a ^ b;
	int count = 0;

	while (n) {
		if (n & 1 == 1)
			count++;
		n >>= 1;
	}

	return count;
}

int _main() {

	while (1) {	
		int a, b;
		int input1 = scanf_s("%d", &a);

		if (input1 == 1 && a < 0)
			break;
		
		int input2 = scanf_s("%d", &b);

		while (input1 != 1 || input2 != 1 || a < 0 || b < 0) {
			printf("Invalid input. Please, input 2 positive integers\n");;
			scanf_s("%*[^\n]");
			input1 = scanf_s("%d", &a);

			if (input1 == 1 && a < 0)
				break;

			input2 = scanf_s("%d", &b);
		}

		if (input1 == 1 && a < 0)
			break;
		
		printf("%d\n", get_hamming_distance(a, b));
	}
	return 0;
}