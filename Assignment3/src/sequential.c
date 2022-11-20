#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief read only array of length `length` that stores ints between 0 and 5
 */
int *array;
/**
 * @brief length of the array
 */
const int length = 100000000;
/**
 * @brief total count of 1s in the array
 */
int count;

/**
 * @brief runs a for loop over the array and increments `count` everytime a 1 is
 * found
 *
 * @return int : the number of 1s found in the array
 *
 * @test arrays of size 100, 10000, 100000, 1000000, 100000000
 */
int count1s() {
  int i;
  count = 0;
  for (i = 0; i < length; i++) {
    if (array[i] == 1) {
      count++;
    }
  }
  return count;
}

/**
 * @brief main function tested on arrays of lengths arrays of size 100, 10000,
 * 100000, 1000000, 100000000, generated with different seeds
 */
int main() {
  int seed = time(NULL);
  double total_time = 0;
  for (int i = 0; i < 100; i++) {
    srand(seed++);
    array = calloc(length, sizeof(int));

    for (int i = 0; i < length; i++) {
      array[i] = rand() % 6;
    }

    double start = get_time();
    int c = count1s();
    double end = get_time();
    total_time += (end - start);

    free(array);
  }

  printf("time: %f\n", total_time);
  printf("avg: %f", total_time / 100.0);
  return 0;
}
