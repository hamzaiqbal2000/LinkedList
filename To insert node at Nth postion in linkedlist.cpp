#include <iostream>
//linked list :: program to insert node at Nth postion
struct Node {
	int data;
	Node* next;
};
Node* head;
void Insert(int data, int n) {
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for (int i = 0; i < n - 2; i++) {
		temp2 = temp2->next;//for getting at n-1 positon
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void Print() {//traversing
	Node* temp = head;
	while (temp != NULL) {
		std::cout <<" "<< temp->data;
		temp = temp->next;
	}
	std::cout << "\n";
}
int main() {
	head = NULL;
	Insert(2, 1);
	Insert(3,2);
	Insert(4,1);
	Insert(5, 2);
	Insert(10, 1);
	Print();
}