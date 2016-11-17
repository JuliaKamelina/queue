#include <cmath>
#include <stdlib.h>
#include "queue.h"

double * queueSum(int* data, int w, int size) {
  queue q;
  double sum = 0;
  double *res;
  res = (double *)malloc(sizeof(double) * (size - w + 1));
  for (int i = 0; i < w; i++) {
    q.push(data[i]);
    sum += data[i];
  }
  res[0] = sum / w;
  for (int i = w; i < size; i++) {
    sum = sum - q.front() + data[i];
    res[abs(w - i) + 1] = sum / w;
    q.pop();
    q.push(data[i]);
  }
  return res;
}
