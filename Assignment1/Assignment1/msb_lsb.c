#include "msb_lsb.h"
/*
	Requires: an unsigned integer
	Effects: returns the position of the most significant 1
*/
int msb(unsigned int num) {
	int pos = 0;
	while (num) {
		pos++;
		num >>= 1;
	}
	return pos - 1;
}

/*
	Requires: an unsigned integer
	Effects: returns the position of the least significant 1
*/
int lsb(unsigned int num) {
	if (num % 2 == 1)
		return 0;

	int pos = 0;

	while (num%2==0) {
		pos++;
		num >>= 1;
	}
	return pos;
}
/*
	Scans valid input (an int) and outputs the hamming distance

	Tests:
		+ve - valid output
		-ve	- gets 2s complement and returns value
		any input containing char, string, double, float - prints "Invald input" and asks for input
*/
int main_2() {
	while (1) {
		unsigned int a;
		int input = scanf_s("%u", &a);
		while (input != 1 || a == 0) {
			printf("Invalid input. Please, input an unsigned integers\n");;
			scanf_s("%*[^\n]");
			input = scanf_s("%u", &a);
		}
		printf("%d\n", msb(a) - lsb(a));
	}
	return 0;
}
