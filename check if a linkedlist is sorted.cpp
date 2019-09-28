#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;
Node* last;

void Insert(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) head =last= temp;
	else {
		last->next = temp;
		last = temp;
	}
}

bool sorted() {
	Node* ptr = head;
	int num =- 32768;
	while (ptr != NULL) {
		if (ptr->data > num) {
			num = ptr->data;
			ptr = ptr->next;
		}
		else
			return false;
	}
	return true;
}

int main() {
	head = NULL;
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	
	cout << sorted();

}