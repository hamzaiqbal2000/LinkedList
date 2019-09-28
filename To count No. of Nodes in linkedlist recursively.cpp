//Program to count No. of Nodes in linkedlist recursively
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* Insert(Node* head,int data) {
	Node*temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) 
		head = temp;
	else {
		Node* temp1 = head;
		while (temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	return head;
}
//recursive function to count number of nodes in alinked list
int count(Node* head) {
	if (head == 0)
		return 0;
	else
		return count(head->next) + 1;
}


int main() {
	Node* head = NULL;
	head=Insert(head,2);
	head=Insert(head,4);
	head=Insert(head,6);
	head=Insert(head,8);
	int temp=count(head);
	cout << temp;

}