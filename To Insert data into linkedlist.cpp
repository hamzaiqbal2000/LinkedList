
#include <iostream>

struct Node {
	int data;
	Node *next;
};

Node *Head;//Global variable can be accessed everywhere

void Insert(int x) {//Inserting the input data from user into the linked list
	Node *temp = new Node();//allocating heap memory for data
	temp->data = x;//putting data into linked list data variable
	temp->next = Head;//assinging the address in head pointer node to next pointer variable
	Head = temp;//then assigning the address of temp in head pointer
}

void Print() {//teversing
	Node *temp = Head;
	std::cout << "List is: ";
	while (temp != NULL) {
		std::cout <<" "<< temp->data;
		temp = temp->next;
	}
	std::cout << "\n";
}
int main() {
	Head = NULL;
	std::cout << "How many Numbers?";
	int n, i, x;
	std::cin >> n;
	for (i = 0; i < n; i++) {
		std::cout << "Enter the Number";
		std::cin >> x;
		Insert(x);
		Print();
	}

}