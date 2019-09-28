#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* head;

void Insert(int pos, int data) {
	Node* p = head;
	Node* temp = new Node;
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (head == NULL && pos == 0) {
		head = temp;
	}
	else if (pos == 0 && head!=NULL) {
		temp->next = head;
		temp->next->prev = temp;
		head = temp;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			p = p->next;
		}
		temp->next = p->next;
		temp->prev = p;
		if (p->next) {
			p->next->prev = temp;
		}
		p->next = temp;
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
	Insert(0, 1);
	Insert(1, 2);
	Insert(2, 3);
	Insert(3, 4);
	Insert(1, 5);
	Print();

}