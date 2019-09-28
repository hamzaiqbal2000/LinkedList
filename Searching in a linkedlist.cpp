//Linear searching in a linked list using iteration and recursion
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* Insert(Node* head, int data) {
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
	return head;
}
//Iterative solution
Node* SearchI(Node* head, int key) {
	while (head != NULL) {
		if (key == head->data)
			return head;
		head = head->next;
	}
	return NULL;
}
//recursive solution
Node* SearchR(Node* head, int key) {
	if (head == NULL)
		return NULL;
	else {
		if (key == head->data)
			return head;
		else
			return SearchR(head->next, key);
	}
}

void Print(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 5);
	head = Insert(head, 6);
	int key = 6;
	head= SearchI(head, key);
	cout << head->data << endl;
}