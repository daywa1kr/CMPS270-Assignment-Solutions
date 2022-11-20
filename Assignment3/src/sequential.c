#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *array;
int length;
int count;

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

int main() {
  int seed = time(NULL);
  for (int i = 0; i < 100; i++) {
    printf("\n");
    srand(seed++);
    length = 20;
    array = calloc(length, sizeof(int));

    for (int i = 0; i < length; i++) {
      array[i] = rand() % 6;
      printf("%d ", array[i]);
    }

    double start = get_time();
    int c = count1s();
    double end = get_time();
    printf("\ncount: %d\ntime: %f", c, end - start);

    free(array);
  }
  return 0;
}
