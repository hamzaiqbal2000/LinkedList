//Inserting in a sorted linkedlist

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;//global variable
Node* last;
void Insert(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) head = last = temp;
	else {
		last->next = temp;
		last = temp;
	}

}

void Print() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void SortedInsert(int data) {
	Node* p = head;
	Node* q = NULL;
	Node* ptr = new Node();
	ptr->data = data;
	ptr->next = NULL;
	if (head == NULL) {
		head = ptr;
	}
	//for traversing
	while (p && p->data<data) {
		q = p;
		p = p->next;
	}
	if (p == head) {
		ptr->next = head;
		head = ptr;

	}
	else {
		ptr->next = q->next;
		q->next = ptr;
	}

}
int main() {
	head = NULL;
	Insert(3);
	Insert(7);
	Insert(9);
	Insert(15);
	Insert(20);
	Print();
	SortedInsert(2);
	Print();

}