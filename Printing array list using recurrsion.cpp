#include <iostream>
using namespace std;
//Printing array list using recurrsion
struct Node {
	int data;
	Node* next;
};

void Print(Node* p) {
	if (p == NULL) return;//base condition
	cout << " " << p->data;//print first value in the code
	Print(p->next);//recursive call
}
Node* Insert(Node* head, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	}
	else {
		Node* temp1 = head;
		while (temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	return head;
}

int main() {
	Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	Print(head);
}