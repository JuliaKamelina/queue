#include "queue.h"
int main() {
  int w = 3;
  int size = 7;
  int data[7] = {1, 5, 7, 8, 6, 4, 3};

  double* res = queueSum(data, w, size);
  for (int i = 0; i < size - w + 1; i++)
    printf("%lf ", res[i]);
}