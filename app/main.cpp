#include "queue.h"
int main() {
  const int w = 3;
  const int size = 7;
  int data[size] = {1, 5, 7, 8, 6, 4, 3};
  double res[size - w + 1];

  queueSum(data, w, size, res);
  for (int i = 0; i < size - w + 1; i++)
    printf("%lf ", res[i]);
}