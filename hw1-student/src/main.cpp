#include <iostream>

#include "llist.h"

using namespace std;

int main(){
  linkedlist myList;

  cout << "sample tests for code:" << endl;
  myList.insert(2);
  myList.insert(1);
  myList.insert(3);
  myList.insert(4);
  myList.print();

  myList.remove(3);
  myList.remove(6);
  myList.print();

  cout << myList.to_string() << endl;

  return 0;
}
