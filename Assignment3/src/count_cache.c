#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CACHE_SIZE 65536

typedef struct count_element{
    int count;
    char dummy[CACHE_SIZE-4];
}count_element;

int *array;
count_element *count_array;
int length;
int count;
const int n_threads = 8;
pthread_mutex_t mutex;

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
  count_array[rank].count=local_count;
  return NULL;
}

int main() {
  int correct = 0;
  for (int t = 0; t < 100; t++) {
    count = 0;
    length = 1000000;
    array = calloc(length, sizeof(int));
    count_array=calloc(n_threads, sizeof(count_element));

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

    for(int i=0; i<n_threads; i++){
        count+=count_array[i].count;
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
    free(count_array);
  }
  printf("correct: %d\n", correct);

  return 0;
}