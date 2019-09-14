#include <iostream>
//program to delete a node at nth position
struct Node {
	int data;
	Node* next;
};

Node* head;
void Insert(int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) { // empty list
		head = temp;
		return;
	}

	Node* temp2 = new Node();
	temp2 = head;
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}

	temp2->next = temp;
}

void Print() {
	Node* temp = head;
	while (temp != NULL) {
		std::cout << " " << temp->data;
		temp = temp->next;
	}
	std::cout << "\n";
}

void Delete(int n) {
	struct Node* temp1 = head;
	if (n == 1) {
		head = temp1->next;//head now points to second node
		delete temp1;
		return;
	}
	int i;
	for (i = 0; i < n - 2; i++) {
		temp1 = temp1->next;//temp points to n-1 node
	}
	struct Node* temp2 = temp1->next;//nth node
	temp1->next = temp2->next;
	delete temp2;
}

int main() {
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	Print();//2 4 6 5
	int n;
	std::cout << "Enter a positon Number";
	std::cin >> n;
	Delete(n);
	Print();
}
