//Reversing using sliding pointer in linkedlist
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

void Print() {
	Node* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* Inverse() {
	Node* p = head;
	Node* q = NULL;
	Node* r = NULL;
	while(p) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	return q;
}

int main() {
	head = NULL;
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Print();
	head=Inverse();
	Print();

}