#include <iostream>
using namespace std;

struct Node {
	Node* prev;
	int data;
	Node* next;
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

void Print() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Print_reverse() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}
int main() {
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(5);
	Insert(7);
	Insert(8);
	Print();
	while (head->next != NULL) {
		head = head->next;
	}
	Print_reverse();

}