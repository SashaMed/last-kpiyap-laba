#pragma once 
#include<iostream>
#include<string>
#include<vector>
#include"Header.h"
using namespace std;



class iterator;

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
	void rec_output_to_file(node* ptr, const char *path);
	void rec_output(node* ptr);
	bool rec_search(valueType n, node* ptr);
	void add(valueType n);
	void printTree(node* root);
	void printSubtree(node* root, const string& prefix);
public:


	//template<typename valueType>
	friend valueType myFind(tree<valueType> t, valueType val) {
		//valueType ret;
		iterator it;
		it = t.cbegin();
		while (1) {
			if (it == nullptr) return 0;
			if (it.getNode().data == val) { return it.getNode().data; };
			//if (*it == val) { return *it; };
			if (val > it.getNode().data) { it++; }
				else ++it;
		}
		return t.head->data;
	};







	class iterator {
	private:
		node* ptr;
	public:
		node getNode() {
			return ptr;
		};
		iterator() {
			ptr = nullptr;
		};
		iterator(node* p) {
			ptr = p;
		};
		iterator(const iterator& obj) {
			ptr = obj.ptr;
		};

		bool operator!=(const iterator& obj) {
			if (ptr != obj.ptr)
				return true;
			return false;
		};

		bool operator==(const iterator& obj) {
			if (ptr->data == obj.ptr->data)
				return true;
			return false;
		};

		const iterator& operator*() {
			return ptr.data;
		};

		void operator++() {
			if (ptr->leftptr != nullptr)
				ptr = ptr->leftptr;
		};

		void operator--() {
			if (ptr->prevptr != nullptr)
				ptr = ptr->prevptr;
		};

		void operator++(int) {
			if (ptr->rightptr != nullptr)
				ptr = ptr->rightptr;
		};
		iterator& operator=(const iterator& obj) {
			this->ptr = obj.ptr;
			return *this;
		};
		//node<valueType>& operator*() {
		//	return *ptr;
		//};
	};

	friend valueType myItFind(tree<valueType> t, valueType val) {
		//valueType ret;
		iterator it;
		vector<valueType> vis;

		it = t.cbegin();
		while (1) {
			//if (it.getNode() == nullptr) it--;
			////if (find(vis.begin(), vis.end, *it) == vis[0]) {
			////
			////	if (find(vis.begin(), vis.end, it.getNode()->rightptr.data) == vis[0]  ) {}
			////}
			//vis.push_back(*it);
			//if (it == t.cend()) return t.head->data;
			//if (*(it) == val) { return *it; };

			////if (*it == val) { return *it; };
			//++it;
		}
		return t.head->data;
	};



	iterator cbegin() {
		iterator temp(head);
		return temp;
	};

	iterator cend() {
		node *temp = head;
		while (1) {
			if (temp->rightptr == nullptr) {
				return iterator(temp);
			}
			temp = temp->rightptr;
		}
	};

	void outputTofile(const char* path);
	void output();
	tree();
	tree(valueType n);
	bool deleteNode(valueType n);
	bool search(valueType n);
	void operator =(valueType n);
};





