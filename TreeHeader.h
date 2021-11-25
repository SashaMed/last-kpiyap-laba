#pragma once 
#include<iostream>
#include<string>
using namespace std;




template<typename valueType>
class tree {
private:
	class node {
	public:
		valueType data;
		node* leftptr;
		node* rightptr;
		node* prevptr;
		node(valueType n) {
			data = n;
			leftptr = nullptr;
			rightptr = nullptr;
			prevptr = nullptr;
		}
		node(valueType n, node* prev) {
			data = n;
			leftptr = nullptr;
			rightptr = nullptr;
			prevptr = prev;
		}
	};
	node* head;
	void rec_output(node* ptr);
	bool rec_search(valueType n, node* ptr);
	void add(valueType n);
	void printTree(node* root);
	void printSubtree(node* root, const string& prefix);
public:
	void output();
	tree();
	tree(valueType n);
	bool deleteNode(valueType n);
	bool search(valueType n);
	void operator =(valueType n);
};

//