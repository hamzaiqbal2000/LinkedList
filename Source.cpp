//program to Add 1 to a number represented as linked list

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;
void Insert(int data) {
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
}

void Print() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Reverse() {
	Node* prev;
	Node* current;
	Node* next;

	prev = NULL;
	current = head;
	

	while (current!= NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		
	}	
	head = prev;
}

void check() {
	Node* temp = head;
	while (temp != NULL) {
		if ((temp->data) <= 8) {
			temp->data = temp->data + 1;
			break;
		}
		else if (temp->data == 9) {
			temp->data = 0;
		}
		temp = temp->next;
	}
}

int main(){
	head = NULL;
	Insert(1);
	Insert(8);
	Insert(9);
	Insert(9);
	Print();
	Reverse();
	check();
	Reverse();
	Print();

}

