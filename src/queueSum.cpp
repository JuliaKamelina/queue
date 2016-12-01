#include "queue.h"

void queueSum(int* data, int w, int size, double *res) {
  queue q;
  double sum = 0;
  for (int i = 0; i < w; i++) {
    q.push(data[i]);
    sum += data[i];
  }
  res[0] = sum / w;
  for (int i = w; i < size; i++) {
    sum = sum - q.front() + data[i];
    res[i - w + 1] = sum / w;
    q.pop();
    q.push(data[i]);
  }
}
