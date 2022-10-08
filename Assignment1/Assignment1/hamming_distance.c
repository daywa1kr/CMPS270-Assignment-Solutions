#include "hamming_distance.h"

/*
	Requires: 2 positive integeres a and b.
	Assumes: The integeres passed to the function are positive or 0.
	Effects: Returns an integer representing the number of bits that differ at each position of the int

	Tests:
		+ve +ve - valid output
		-ve +ve - invalid (-1)
		+ve -ve - invalid (-1)
		-ve -ve - invalid (-1)
		
		any combination containing a char takes its ascii value and returns valid output
		any combination containing a float / double gets rounded and the program returns valid output
*/

int get_hamming_distance(int a, int b) {
	if (a < 0 || b < 0)
		return -1;

	int n = a ^ b;
	int count = 0;

	while (n) {
		if ((n & 1) == 1)
			count++;
		n >>= 1;
	}

	return count;
}

/*
	Scans valid input (only 2 positive int) and outputs the hamming distance

	Tests:
		+ve int +ve int - valid output
		-ve int	+ve	int	- exits program
		-ve int -ve int - exits program
		+ve int -ve int - prints "Invald input" and asks for input
		any input containing char, string, double, float - prints "Invald input" and asks for input
*/
int main_1() {

	while (1) {	
		int a, b;
		int input1 = scanf_s("%d", &a);

		if (input1 == 1 && a < 0)
			break;
		
		int input2 = scanf_s("%d", &b);

		while (input1 != 1 || input2 != 1 || b < 0) {
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