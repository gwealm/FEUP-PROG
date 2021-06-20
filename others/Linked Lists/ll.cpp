#include <iostream>
#include <string>


template <class T>
class LinkedList {

	/** Node representation */
	struct Node {
		T			data;
		Node* next;
	} *node;

	/** Size of the list */
	size_t		length;

public:
	/** Default constructor */
	LinkedList();

	/** Getters */
	size_t size() const;

	/** Operations */
	void insertBegin(T val);
	void insertEnd(T val);
	bool insertAfter(size_t index, T val);
	bool remove(T val);
	void clear();

	/** Overloads */
	template<class U>
	friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& ll);

	/** Destructor */
	~LinkedList();
};

//----------------------------------------------------------------------//

template<class T>
LinkedList<T>::LinkedList() {
	node = NULL;
	length = 0;
}

//----------------------------------------------------------------------//

template<class T>
size_t LinkedList<T>::size() const {
	return length;
}

//----------------------------------------------------------------------//

template<class T>
void LinkedList<T>::insertBegin(T val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = node;
	node = newNode;
	length++;
}

//----------------------------------------------------------------------//

template<class T>
void LinkedList<T>::insertEnd(T val) {
	if (node == NULL) {					// Empty list
		node = new Node;
		node->data = val;
		node->next = NULL;
	}
	else {
		Node* lastNode = node, * newNode = new Node;
		while (lastNode->next != NULL) lastNode = lastNode->next;
		newNode->data = val;
		newNode->next = NULL;
		lastNode->next = newNode;
	}
	length++;
}

//----------------------------------------------------------------------//

template<class T>
bool LinkedList<T>::insertAfter(size_t index, T val) {

	if (index > size() - 1) { return false; }
	else {
		Node* prevNode = node, * newNode = new Node;
		for (size_t i = 0; i < index; i++) prevNode = prevNode->next;
		newNode->data = val;
		newNode->next = prevNode->next;
		prevNode->next = newNode;
		length++;
		return true;
	}
}

//----------------------------------------------------------------------//

template<class T>
bool LinkedList<T>::remove(T val) {
	Node* auxNode, * newNode;
	auxNode = node;

	if (auxNode->data == val) {				// first node
		node = node->next;
		delete auxNode;
		length--;
		return true;
	}

	newNode = auxNode;						// pointer to head node
	while (auxNode != NULL) {
		if (auxNode->data == val) {
			newNode->next = auxNode->next;
			delete auxNode;
			length--;
			return true;
		}
		newNode = auxNode;
		auxNode = auxNode->next;
	}
	return false;
}

//----------------------------------------------------------------------//

template<class T>
void LinkedList<T>::clear() {
	if (node == NULL) return;		// empty list

	Node* auxNode;

	while (node != NULL) {
		auxNode = node->next;
		delete node;
		node = auxNode;
		length--;					// decrementing list size by 1
	}
}

//----------------------------------------------------------------------//

template<class T>
LinkedList<T>::~LinkedList() {
	clear();
}

//----------------------------------------------------------------------//

template <class T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& ll) {
	out << "[";
	while (ll.node != NULL) {
		if (ll.node->next == NULL) {			// last element
			out << ll.node->data;
		} else { 
			out << ll.node->data << ", ";
		}
	}
	out << "]";
	return out;
}


//----------------------------------------------------------------------//

int main() {
	LinkedList<char> ll;
	ll.insertBegin('a');

	std::cout << ll << std::endl;

	return 0;
}