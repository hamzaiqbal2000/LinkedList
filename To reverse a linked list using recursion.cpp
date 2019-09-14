#include <iostream>
using namespace std;
//program to reverse a linked list
struct Node {
	int data;
	Node* next;
};
Node* head;
void Reverse(Node* p) {
	if (p->next == NULL) {
		head = p;
		return;
	}
	Reverse(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
}
void Insert(int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) head = temp;
	else {
		Node* temp1 = head;
		while (temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
}

void Print() {
	Node* temp = head;
	while (temp != NULL) {
		cout << " " << temp->data;
		temp = temp->next;
	}
	cout << endl;
}
int main() {
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(8);
	Print();
	Reverse(head);
	Print();
}