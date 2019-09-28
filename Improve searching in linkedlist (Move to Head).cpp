//Improve searching in a linkedlist
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;
Node* Insert(int data) {
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

void Print() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

struct Node* Search(struct Node* p, int key)
{
	struct Node* q= NULL;
	while (p != NULL)
	{
		if (key == p->data)
		{
			q->next = p->next;
			p->next = head;
			head = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

int main() {
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(5);
	Insert(6);
	
	int key = 5;
	Print();
	head=Search(head, key);
	Print();


}