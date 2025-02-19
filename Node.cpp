#include "Node.h"

Node::Node() {
	value = ' ';
	frequency = 0;
	left = nullptr;
	right = nullptr;
}


Node::Node(char v, int f) {
	value = v;
	frequency = f;
	left = nullptr;
	right = nullptr;
}

Node::Node(int f, Node* l, Node* r) {
	value = '\0';
	frequency = f;
	left = l;
	right = r;
}

Node::Node(char v,int f, Node* l, Node* r) {
	value = v;
	frequency = f;
	left = l;
	right = r;
}

char Node::getValue() {
	return value;
}

void Node::setValue(char v) {
	value = v;
}

int Node::getFrequency() {
	return frequency;
}

void Node::setFrenquency(int f) {
	frequency = f;
}

Node* Node::getChild(char child) {
	switch (child) {
	case 'l':
		return left;
		break;
	case 'r':
		return right;
		break;
	default:
		std::cout << "Erreur de saisie de l enfant, rentrez un nouvel enfant\n";
		std::cin >> child;
		getChild(child);
	}
}

void Node::setChild(char child, Node *ref) {
	switch (child) {
	case 'l':
		left = ref;
		break;
	case 'r':
		right = ref;
		break;
	default:
		std::cout << "Erreur de saisie de l enfant, rentrez un nouvel enfant\n";
		std::cin >> child;
		setChild(child, ref);
	}
}