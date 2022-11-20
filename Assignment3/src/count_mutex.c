#include "../include/utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief read only array of length `length` that stores ints between 0 and 5
 */
int *array;
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
 * @brief mutex used to lock and unlock critical sections of the code
 */
pthread_mutex_t mutex;

/**
 * @brief divides the array into `length/n_threads` chunks and iterates over the
 * chunk corresponding to the thread id, incrementing the count. Uses a mutex to
 * lock before incrementing the count and unlock after
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
  pthread_mutex_lock(&mutex);
  count += local_count;
  pthread_mutex_unlock(&mutex);
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
    if (pthread_mutex_init(&mutex, NULL) != 0) {
      perror("mutex_lock");
      exit(1);
    }
    count = 0;
    length = 100000000;
    array = calloc(length, sizeof(int));

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

    free(array);
    pthread_mutex_destroy(&mutex);
  }

  printf("time: %f\navg: %f", total_time, total_time / 100.0);
  return 0;
}