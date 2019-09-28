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

//Iterative function for finding Maximum
int MaxI(Node* head) {
	int MAX = -32768;
	while (head != NULL) {
		if (head->data > MAX) {
			MAX = head->data;
		}
		head = head->next;
	}
	return MAX;
}

//Recursive function for finding Maximun
int MaxR(Node* head) {
	int x=0;
	if (head == NULL)
		return -32768;
	else {
		x = MaxR(head->next);
		if (x > head->data) {
			return x;
		}
		else
			return head->data;
	}
}

int main() {
	Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	int MAXI = MaxI(head);//Iterative solution
	int MAXR = MaxR(head);//Recursive solution
	cout << MAXI << endl;
	cout << MAXR << endl;

}