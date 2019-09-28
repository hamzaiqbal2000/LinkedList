#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* head;
void Insert(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (head == NULL) head = temp;
	else {
		Node* temp1 = head;
		while (temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->prev = temp1;
	}
}

void delete_doubly(int pos) {
	Node* p = head;
	Node* q = NULL;
	if (pos == 1) {
		head = p->next;
		head->prev = NULL;
		delete p;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		if (p->next != NULL) {
			p->next->prev = q;
		}
		delete p;
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
	Insert(1);
	Insert(2);
	Insert(3); 
	Insert(4);
	Insert(5);
	Print();
	delete_doubly(5);
	Print();
	return 0;
}