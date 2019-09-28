//Concatenating two linkedlists
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* h;
Node* l;



Node* Insert(Node* head, int data) {
	Node* temp = new Node;
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

void Print(Node* temp) {
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Concat(Node* head1,Node* head2) {
	Node* p = head1;
	while (head1->next != NULL) {
		head1 = head1->next;
	}
	head1->next = head2;
	head2 = NULL;

}

int main() {
	Node* first = NULL;
	Node* second = NULL;
	first = Insert(first, 1);
	first = Insert(first, 2);
	first = Insert(first, 3);
	second = Insert(second, 4);
	second = Insert(second, 5);
	second = Insert(second, 6);
	Print(first);
	Concat(first, second);
	Print(first);
}