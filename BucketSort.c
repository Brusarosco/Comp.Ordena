#include <stdlib.h>
#include <math.h>

void bucket_sort(int *array, int length, int max_value) {
  // Cria um array de buckets
  int *buckets = malloc(sizeof(int) * (max_value + 1));
  for (int i = 0; i <= max_value; i++) {
    buckets[i] = 0;
  }

  // Conta o número de elementos em cada bucket
  for (int i = 0; i < length; i++) {
    buckets[array[i]]++;
  }

  // Ordena os elementos em cada bucket
  for (int i = 0; i <= max_value; i++) {
    // Se houver elementos no bucket
    if (buckets[i] > 0) {
      // Ordena os elementos no bucket
      int *bucket = buckets + i;
      insertion_sort(bucket, buckets[i]);
    }
  }

  // Copia os elementos ordenados do bucket para o vetor original
  int index = 0;
  for (int i = 0; i <= max_value; i++) {
    for (int j = 0; j < buckets[i]; j++) {
      array[index++] = i;
    }
  }

  free(buckets);
}

void insertion_sort(int *array, int length) {
  for (int i = 1; i < length; i++) {
    int value = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > value) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = value;
  }
}
