#include <iostream>
#include <memory>
#include <cstdio>
#include <cstdlib>

struct Node {
	int data;
	Node *next;
};

class LinkedList {
private:
	Node * head;
    int length;
public:
	LinkedList() {
		head = nullptr;
	}
	void print() {
		auto iterator = head;
		while (iterator != NULL) {
			std::cout << iterator->data << " ";
			iterator = iterator->next;
		}
		std::cout << std::endl;
		delete iterator;
	}
	void insert(int m_data) {
		Node *new_node = new Node;
		new_node->data = m_data;
		new_node->next = NULL;
		if (head != NULL) {
			new_node->next = head;
		}
		head = new_node;
		length++;
	}

	void insert(int m_data, int position) {
		if (position < 1 || position >length) {
			std::cerr << "OUT OF RANGE \n";
			return;
		}
		else if (position == 1) {
			insert(m_data);
		}
		else {
			Node *new_node = new Node;
			new_node->data = m_data;
			auto iterator = head;
			for (int i = 0; i < position - 2; i++) {
				iterator = iterator->next;
			}
			new_node->next = iterator->next;
			iterator->next = new_node;
			length++;
		}
	}
	void remove() {
		if (head == NULL) {
			std::cout << "NOTHING TO POP" << std::endl;
			return;
		}
		else {
			Node *to_delete_node = head;
			head = to_delete_node->next;
			delete to_delete_node;
			length--;
		}
	}
	void remove(int position) {
		if (position < 1 || position >length) {
			std::cerr << "OUT OF RANGE \n";
			return;
		}
		else if (position == 1) {
			remove();
		}
		else {
			auto iterator = head;
			for (int i = 0; i < position - 2; i++) {
				iterator = iterator->next;
			}
			Node *new_node = iterator->next;
			iterator->next = new_node->next;
			delete new_node;
			length--;
		}
	}

	void destroy() {
		auto iterator = head;
		while (iterator != NULL) {
			iterator = iterator->next; 
			remove();
		}
		delete iterator;
		head = NULL;
	}

	int size() {
		return length;
	}
};

int main(int argc, char **argv) {
	LinkedList *list = new LinkedList;
	list->insert(4);
	list->insert(5);
	std::cout << list->size() << std::endl;
	list->insert(6);
	list->insert(7);
	std::cout << list->size() << std::endl;
	list->print();

	list->remove();
	list->insert(9);
	std::cout << list->size() << std::endl;
	list->print();
	list->insert(8,2);
	list->insert(3, 881);
	std::cout << list->size() << std::endl;
	list->insert(55, 1);
	list->print();
	list->remove(3);
	list->print();
	list->remove(1);
	list->print();
	list->destroy();
	list->print();
	std::cout << list->size() << std::endl;
	list->insert(9);
	list->print();
	std::cout << list->size() << std::endl;
	std::cin.get();


}