#pragma once
#include <iostream>

class Node
{
private:
	char value;
	int frequency;
	Node* left;
	Node* right;

public:
	Node();
	Node(char v, int f);
	Node(int f, Node* l, Node* r);


	char getValue();
	void setValue(char v);

	int getFrequency();
	void setFrenquency(int f);

	Node* getChild(char child);
	void setChild(char child, Node &ref);
};

