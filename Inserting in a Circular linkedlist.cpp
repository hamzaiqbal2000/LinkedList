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
			while(p->next!=head) {
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

void Print() {
	Node* temp = head;
	do{
		std::cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
	std::cout << endl;
}

int main() {
	head = NULL;
	Insert(0, 1);
	Insert(1, 2);
	Insert(2, 3);
	Insert(3, 4);
	Insert(4, 5);
	Print();

}