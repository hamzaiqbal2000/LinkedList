//Merging two sorted lists
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

Node* Merge(Node* first,Node* second) {
	Node* third = NULL;
	Node* last = NULL;
	if (first->data < second->data) {
		third = last = first;
		first = first->next;
		last->next = NULL;
	}
	else {
		third = last = second;
		second = second->next;
		last->next = NULL;
	}
	while (first != NULL && second != NULL) {
		if (first->data < second->data) {
			last->next = first;
			last = first;
			first = first->next;
			last->next = NULL;
		}
		else {
			last->next = second;
			last = second;
			second = second->next;
			last->next = NULL;
		}
	}
	if (first != NULL) last->next = first;
	else last->next = second;

	return third;
}

int main() {
	Node* first = NULL;
	Node* second = NULL;
	first = Insert(first, 1);
	first = Insert(first, 3);
	first = Insert(first, 5);
	first = Insert(first, 7);
	first = Insert(first, 9);
	second = Insert(second, 2);
	second = Insert(second, 4);
	second = Insert(second, 6);
	second = Insert(second, 8);
	Print(first);
	Print(second);
	first = Merge(first, second);
	Print(first);

}