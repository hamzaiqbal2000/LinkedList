#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;

void Insert(int pos, int data) {
	Node* p, * t;
	int i;
	if (pos == 0) {
		t = new Node;
		t->data = data;
		if (head == NULL) {
			head = t;
			head->next = head;
		}
		else {
			p = head;
			while (p->next != head) {
				p = p->next;
			}
			p->next = t;
			t->next = head;
			head = t;
		}
	}
	else {
		p = head;
		for (i = 0; i < pos - 1; i++) {
			p = p->next;
		}
		t = new Node;
		t->data = data;
		t->next = p->next;
		p->next = t;

	}
}

void delete_circular(int pos) {
	Node* p = head;
	Node * q = NULL;
	if (pos == 1) {
		while (p->next != head) {
			p = p->next;
		}
		p->next = head->next;
		q = head;
		head = p->next;
		q->next = NULL;
		delete q;
	}
	else {
		for (int i = 0; i < pos-1; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		p->next = NULL;
		delete p;
	}
}

void Print() {
	Node* temp = head;
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}

int main() {
	head = NULL;
	Insert(0, 1);//pos1
	Insert(1, 2);//pos2
	Insert(2, 3);//pos3
	Insert(3, 4);//pos4
	Insert(4, 5);//pos5
	Print();
	delete_circular(2);
	Print();
}