//Remove Duplicate from sorted linkedlist
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;
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

void Remove_Duplicate() {
	Node* q = head;
	Node* p = q->next;
	while (p) {
		if (p->data == q->data) {
			q->next = p->next;
			delete p;
			p = head;
			q = NULL;
		}
		q = p;
		p = p->next;
	}
}
void Print() {
	Node* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	head = NULL;
	Insert(3);
	Insert(3);
	Insert(5);
	Insert(8);
	Insert(8);
	Print();
	Remove_Duplicate();
	Print();
}