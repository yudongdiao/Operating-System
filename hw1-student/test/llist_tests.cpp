#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>

#include "../src/llist.h"

using namespace std;

TEST(LinkedListTest, Test1) {
  linkedlist myList;
  myList.insert(4);
  EXPECT_EQ(myList.to_string(), "4, ");
}

TEST(LinkedListTest, Test2) {
  linkedlist myList;
  myList.insert(4);
  myList.insert(5);
  myList.remove(4);
  EXPECT_EQ(myList.to_string(), "5, ");
}

TEST(LinkedListTest, Test3) {
  linkedlist myList;
  myList.insert(0);
  myList.insert(0);
  myList.insert(0);
  EXPECT_EQ(myList.to_string(), "0, 0, 0, ");
}

TEST(LinkedListTest, Test4) {
  linkedlist myList;
  myList.insert(0);
  myList.remove(0);
  EXPECT_EQ(myList.to_string(), "");
}

TEST(LinkedListTest, Test5) {
  linkedlist myList;
  myList.insert(-1);
  EXPECT_EQ(myList.to_string(), "-1, ");
}

TEST(LinkedListTest, Test6) {
  linkedlist myList;
  myList.remove(-1);
  EXPECT_EQ(myList.to_string(), "");
}

TEST(LinkedListTest, Test7) {
  linkedlist myList;
  myList.insert(2);
  myList.insert(1);
  myList.insert(3);
  myList.insert(4);
  myList.remove(3);
  EXPECT_EQ(myList.to_string(), "2, 1, 4, ");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
