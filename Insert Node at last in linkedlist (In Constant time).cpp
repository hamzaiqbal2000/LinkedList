//Insert Node at last in linkedlist (In Constant time)
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;
Node* last;

void InsertLast(int data) {
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

int main() {
	head = NULL;
	InsertLast(2);
	InsertLast(5);
	InsertLast(7);
	InsertLast(9);
	Print();
}