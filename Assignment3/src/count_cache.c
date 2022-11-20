#include "../include/utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief cache per core size on Intel(R) Core(TM) i5-8250U CPU @ 1.60GHz
 */
#define CACHE_SIZE 65536

/**
 * @brief struct that contains:
 *        count: the number of 1s per chunck of the array
 *        dummy: char array of length `CACHE_SIZE-4` to occupy the rest of the
 * cache
 */
typedef struct count_element {
  int count;
  char dummy[CACHE_SIZE - 4];
} count_element;

/**
 * @brief read only array of length `length` that stores ints between 0 and 5
 */
int *array;
/**
 * @brief array of length `n_threads` that stores the count of 1s returned by
 * each thread
 */
count_element *count_array;
/**
 * @brief length of the array
 */
int length = 100000000;
/**
 * @brief total count of 1s in the array
 */
int count;
/**
 * @brief number of threads used to count the number of 1s
 */
const int n_threads = 8;

/**
 * @brief divides the array into `length/n_threads` chunks and iterates over the
 * chunk corresponding to the thread id, incrementing the count. Writes the
 * locally caluclated value to count variable of `count_array` elements
 *
 * @param id thread id
 * @return void* NULL
 */
void *count1s(void *id) {
  long rank = (long)id;
  long long lower_bound = rank * (length / n_threads);
  long long upper_bound = (rank + 1) * (length / n_threads);
  int local_count = 0;
  for (long long i = lower_bound; i < upper_bound; i++) {
    if (array[i] == 1) {
      local_count++;
    }
  }
  count_array[rank].count = local_count;
  return NULL;
}

/**
 * @brief tested on arrays of lengths 100, 10000, 100000, 1000000, 100000000,
 * with thread counts of 1, 2, 4, 8, 16, 32, 64. the experiment was run 100
 * times and the average of execution time was calculated
 */
int main() {
  double total_time = 0;
  for (int t = 0; t < 100; t++) {
    count = 0;
    array = calloc(length, sizeof(int));
    count_array = calloc(n_threads, sizeof(count_element));

    for (int i = 0; i < length; i++) {
      array[i] = rand() % 6;
    }

    pthread_t threads[n_threads];
    double start = get_time();
    for (long i = 0; i < n_threads; i++) {
      pthread_create(&threads[i], NULL, count1s, (void *)i);
    }
    for (int i = 0; i < n_threads; i++) {
      pthread_join(threads[i], NULL);
    }
    double end = get_time();
    total_time += (end - start);

    for (int i = 0; i < n_threads; i++) {
      count += count_array[i].count;
    }

    free(array);
    free(count_array);
  }
  printf("time: %f\navg: %f", total_time, total_time / 100.0);

  return 0;
}