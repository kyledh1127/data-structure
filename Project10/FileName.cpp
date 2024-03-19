#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* next;
};


class singlelinkedlist {
private:
	node* head;
	node* tail;
	int listSize;
public:
	singlelinkedlist() {
		head = NULL;
		tail = NULL;
		listSize = 0;
	}
	bool empty() {
		if (listSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void append(int data) {
		node* newNode = new node;
		newNode->data = data;
		newNode->next = NULL;
		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		listSize++;
		print();
	}
	void insertion(int i, int data) {
		if (i<0 || i>listSize) {
			return;
		}
		else if (i == listSize) {
			append(data);
		}
		else if (i == 0) {
			node* newNode = new node;
			newNode->data = data;
			newNode->next = head;
			head = newNode;
			listSize++;
		}
		else {
			node* newNode = new node;
			newNode->data = data;
			node* curNode = head;
			for (int k = 1; k < i; k++) {
				curNode = curNode->next;
			}
			newNode->next = curNode->next;
			curNode->next = newNode;
			listSize++;
		}
	}
	void delection(int i) {
		if (empty() || i > listSize || i == listSize) {
			cout << -1 << endl;
			return;
		}
		else {
			node* curNode = head;
			if (i == 0) {
				if (listSize == 1) {
					head = tail = NULL;
				}
				else {
					head = head->next;
				}
			}
			else {
				node* preNode = head;
				for (int k = 0; k < i; k++) {
					preNode = curNode;
					curNode = curNode->next;
				}
				preNode->next = curNode->next;
				if (curNode == tail) {
					tail = preNode;
				}
			}
			cout << curNode->data << endl;
			delete curNode;
			listSize--;
		}
	}
	void print() {
		if (empty()) {
			cout << "empty";
		}
		node* curNode = head;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
	void afterMin(int i) {
		if (i < 0 || i >= listSize || empty()) {
			cout << "error" << endl;
			return;
		}
		else {
			node* curNode = head;
			for (int k = 0; k < i; k++) {
				curNode = curNode->next;
			}
			int min = curNode->data;
			curNode = curNode->next;
			while (curNode != NULL) {
				if (min > curNode->data) {
					min = curNode->data;
				}
				curNode = curNode->next;

			}
			cout << min << endl;
		}
	}

	void sum() {
		int sum = 0;
		node* curNode = head;
		if (empty()) {
			cout << 0 << endl;
		}
		else {
			while (curNode != NULL) {
				sum += curNode->data;
				curNode = curNode->next;
			}
			cout << sum << endl;
		}
	}


};



int main() {
	/*cin.tie(0);
	ios::sync_with_stdio(0);*/
	singlelinkedlist ll;
	int num;
	cin >> num;
	for (int k = 0; k < num; k++) {
		string s;
		cin >> s;
		if (s == "Print") {
			ll.print();
		}
		else if (s == "Append") {
			int d;
			cin >> d;
			ll.append(d);
		}
		else if (s == "insertion") {
			int i, d;
			cin >> i >> d;
			ll.insertion(i, d);
		}
		else if (s == "Delete") {
			int i;
			cin >> i;
			ll.delection(i);
		}
		else if (s == "Sum") {
			ll.sum();
		}
		else if (s == "AfterMin") {
			int i;
			cin >> i;
			ll.afterMin(i);
		}
	}
	return 0;
}
