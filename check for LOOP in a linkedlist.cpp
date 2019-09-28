//check for LOOP in a linkedlist
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* Insert(Node* head, int data) {
	Node* temp = new Node;
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
	return head;
}

void Print(Node* temp) {
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int isLOOP(Node* head) {
	Node* p = head;
	Node* q = head;
	do {
		p = p->next;
		q = q->next;
		if (q != NULL) q = q->next;

	} while (p&& q);
	if (p == q) return true;
	else return false;
}

int main() {
	Node* head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	int a = isLOOP(head);
	cout << a;
}