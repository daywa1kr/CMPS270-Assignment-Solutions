#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *array;
int length;
int count;
const int n_threads = 4;

void *count1s(void *id) {
  long rank = (long)id;
  long long lower_bound = rank * (length / n_threads);
  long long upper_bound = (rank + 1) * (length / n_threads);
  for (long long i = lower_bound; i < upper_bound; i++) {
    if (array[i] == 1) {
      count++;
    }
  }
  printf("thread %ld, count: %d\n", rank, count);
  return NULL;
}

int main() {
  int correct = 0;
  for (int t = 0; t < 100; t++) {
    count = 0;
    length = 10000;
    array = calloc(length, sizeof(int));

    for (int i = 0; i < length; i++) {
      array[i] = rand() % 6;
    }

    pthread_t threads[n_threads];
    for (long i = 0; i < n_threads; i++) {
      pthread_create(&threads[i], NULL, count1s, (void *)i);
    }
    for (int i = 0; i < n_threads; i++) {
      pthread_join(threads[i], NULL);
    }

    int real = 0;
    for (int i = 0; i < length; i++) {
      if (array[i] == 1)
        real++;
    }
    if (real == count) {
      correct++;
    }

    free(array);
  }
  printf("correct: %d\n", correct);
  return 0;
}