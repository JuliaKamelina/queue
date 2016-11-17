#include <gtest/gtest.h>
#include "queue.h"

TEST(test_queue, can_pop_and_get_front_elements) {
  queue Q;
  for (int i = 0; i < 4; i++)
    Q.push(i);

  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(i, Q.front());
    Q.pop();
  }
}

TEST(test_queue, size_of_empty_queue) {
  queue Q;

  EXPECT_TRUE(Q.isEmpty());
}

TEST(test_queue, size_of_not_empty_queue) {
  queue Q;
  Q.push(2);
  
  EXPECT_FALSE(Q.isEmpty());
}

TEST(test_queue, cant_pop_from_empty_queue) {
  queue Q;

  ASSERT_ANY_THROW(Q.pop());
}

TEST(test_queue, cant_get_front_from_empty_queue) {
  queue Q;

  ASSERT_ANY_THROW(Q.front());
}

TEST(test_queue, cant_get_back_from_empty_queue) {
  queue Q;

  ASSERT_ANY_THROW(Q.back());
}

TEST(test_queue, can_get_back) {
  queue Q;
  for (int i = 0; i < 4; i++) {
    Q.push(i);
    EXPECT_EQ(i, Q.back());
  }
}

TEST(test_queueSum, returns_correct_value) {
  int data[7] = {1, 5, 7, 8, 6, 4, 3};
  int w = 4;
  double* res;
  
  double expData[4] = {5.25, 6.5, 6.25, 5.25};
  
  res = queueSum(data, w, 7);
  
  for (int i = 0; i < 4; i++)
    EXPECT_EQ(res[i], expData[i]);
}



int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}