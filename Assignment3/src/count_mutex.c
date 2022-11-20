#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *array;
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
  pthread_mutex_lock(&mutex);
  count += local_count;
  printf("thread %ld, count: %d\n", rank, count);
  pthread_mutex_unlock(&mutex);
  return NULL;
}

int main() {
  int correct = 0;
  for (int t = 0; t < 100; t++) {
    if (pthread_mutex_init(&mutex, NULL) != 0) {
      perror("mutex_lock");
      exit(1);
    }
    count = 0;
    length = 1000000;
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

  return 0;
}