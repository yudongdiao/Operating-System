#include <iostream>

#include "llist.h"

using namespace std;

linkedlist::linkedlist() {
  // the first element is a dummy head
  LLNode *head = (LLNode *)malloc(sizeof(LLNode));
  head->data = 0;
  head->next = NULL;
  list = head;
  tail = head;
}

void linkedlist::insert(int x) {
  //TODO: write code to insert element x to the end of the linkedlist
	// LLNode* tHead = list;
	LLNode *temp = new LLNode();
	temp->data = x;
	tail->next = temp;
	tail = temp;
}

void linkedlist::remove(int x) {
  // TODO : write code to remove element x from the list. Also print
  // printf("%d is NOT in the list\n",x); if x is not in the list
	LLNode *p = list->next;
	LLNode *prev = list;

	while(p != NULL){
		if( p->data == x){
			prev->next = p->next;
			delete p;
			return;
		}
		else{
			p = p->next;
			prev = prev->next;
		}
	}
	printf("%d is NOT in the list\n",x);
}

void linkedlist::print() {
  LLNode *p = list->next;

  while(p != NULL){
    cout << p->data << ", ";
    p = p->next;
  }

  cout << endl;
}

string linkedlist::to_string() {
  string s = "";
  LLNode *p = list->next;

  while(p != NULL){
    s = s + ::to_string(p->data) + ", ";
    p = p->next;
  }

  return s;
}
