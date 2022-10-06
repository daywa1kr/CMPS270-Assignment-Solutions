#include "msb_lsb.h"

int msb(unsigned int num) {
	int pos = 0;
	while (num) {
		pos++;
		num >>= 1;
	}
	return pos - 1;
}

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

int main_2() {
	while (1) {
		unsigned int a;
		int input = scanf_s("%u", &a);
		while (input != 1) {
			printf("Invalid input. Please, input an unsigned integers\n");;
			scanf_s("%*[^\n]");
			input = scanf_s("%u", &a);
		}
		printf("%d\n", msb(a) - lsb(a));
	}
	return 0;
}
