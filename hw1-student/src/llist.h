#include <string>

using namespace std;

// defining the struct element for the linked list
struct LLNode {
  int data;
  LLNode *next;
};

class linkedlist {
  // the head and tail pointer to the linked list
  LLNode *list;
  LLNode *tail;

 public:
  linkedlist();
  void insert(int x);
  void remove(int x);
  string to_string();
  void print();
};
