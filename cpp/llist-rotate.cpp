#include <iostream>

struct Node {
	int val;
	Node* next;
	Node(int n) : val(n), next(nullptr) {}
};

class LinkedList {
private:
	Node *head;
	bool circular = false;
	
public:
	LinkedList() : head(nullptr) {}

	~LinkedList() {
		if (circular == false) {
			Node *current = head;
			while (current != nullptr) {
				Node *nextNode = current->next;
				delete current;
				current = nextNode;
			}
			head = nullptr;
		} else {
			if (!head) return;
			if (head->next == head) {
				delete head;
				return;
			}
			Node *current = head->next;
			while (current != nullptr) {
				if (current == head) {
					delete head;
					break;
				}
				Node *nextNode = current->next;
				delete current;
				current = nextNode;
			}
		}
	}

	void InsertAtBeginning(int val) {
		Node *newNode = new Node(val);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
	}

	void InsertAtEnd(int val) {
		Node *newNode = new Node(val);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		/*
		Node *current = head;
		Node *prev = current;
		while (current != nullptr) {
			prev = current;
			current = current->next;
		}
		prev->next = newNode;
		*/
		Node *current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	void Delete(int val) {
		if (head == nullptr) {
			std::cout << "Nothing to delete, the list is empty.\n";
			return;
		}
		if (head->val == val) {
			Node *temp = head->next;
			delete head;
			head = temp;
			return;
		}
		
		Node *current = head;
		while ((current->next != nullptr) && (current->next->val != val)) {
			current = current->next;
		}
		if (current->next == nullptr) {
			std::cout << "Nothing to delete, the value is not found in the list.\n";
		}
		Node *newNext = current->next->next;
		delete current->next;
		current->next = newNext;
	}
	
	void Print() {
		std::cout << "LinkedList: {";
		Node *current = head;
		while (current) {
			std::cout << current->val << ", ";
			current = current->next;
		}
		std::cout << " };" << std::endl;
	}

	Node *Head() {
		return head;
	}

	void PrintRotated() {
		std::cout << "LinkedList: {";
		if (head == nullptr) {
			std::cout << "};" << std::endl;
			return;
		} else {
			std::cout << head->val << ", ";
		}
		Node *current = head->next;
		while (current) {
			if (current == head) {
				// reached head again
				break;
			}
			std::cout << current->val << ", ";
			current = current->next;
		}
		std::cout << " };" << std::endl;
	}

	void SetCircular() {
		circular = true;
	}
};

void rotate(Node *head, int k) {
	if (head == nullptr) return;
	if (head->next == nullptr) {
		head->next = head;
		return;
	}
	int l = 1;
	Node *current = head->next;
	while ((current->next != nullptr) && (l < (k-1))) {
		l++;
	    current = current->next;
	}
	if (l != (k-1)) {
		std::cout << "Not enough nodes to make list rotate after " << k << " nodes.\n";
		return;
	}
	current->next = head;
	// other nodes are not delete now
}

int main() {
	LinkedList ll;
	ll.InsertAtBeginning(7);
	for (int i = 6; i > 0; --i) {
		ll.InsertAtBeginning(i);
	}
	for (int i = 8; i < 21; ++i) {
		ll.InsertAtEnd(i);
	}
	ll.Print();
	ll.Delete(7);
	std::cout << "After deleting value 7" << std::endl;
	ll.Print();
	ll.Delete(4);
	std::cout << "After deleting value 4" << std::endl;
	ll.Print();
	ll.Delete(13);
	std::cout << "After deleting value 13" << std::endl;
	ll.Print();

	std::cout << "Rotate list after 6 nodes" << std::endl;
	rotate(ll.Head(), 6);
	ll.SetCircular();
	ll.PrintRotated();
	return 0;
}
