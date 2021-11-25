#include"TreeHeader.h"



template<typename valueType>
tree<valueType>::tree() {
	head = nullptr;
}


template<typename valueType>
tree<valueType>::tree(valueType n) {
	node *temp = new node(n);
	head = temp;
}


template<typename valueType>
void tree<valueType>::add(valueType n) {
	if (head == nullptr)
	{
		//node* temp = new node(n, nullptr);
		//head = temp;
		head = new node(n, nullptr);
		return;
	}
	node* ptr = head;
	node* ptrPrev = head;
	while (1) {
		if (ptr == nullptr) {
			//node* temp = new node(n, ptrPrev);
			//ptr = temp;
			ptr = new node(n, ptrPrev);
			if (ptrPrev == nullptr) {
				return;
			}

			if (n > ptrPrev->data) {
				ptrPrev->rightptr = ptr;
			}
			else {
				ptrPrev->leftptr = ptr;
			}
			return;
		}
		if (n > ptr->data) {
			ptrPrev = ptr;
			ptr = ptr->rightptr;
		}
		else {
			ptrPrev = ptr;
			ptr = ptr->leftptr;
		}
	}
}

template<typename valueType>
void tree<valueType>::output() {
	//this->rec_output(head);
	cout << "\n";
	this->printTree(head);
}

template<typename valueType>
void tree<valueType>::rec_output(node *ptr) {
	if (!ptr) {
		return;
	}
	std::cout << ptr->data << " ";
	this->rec_output(ptr->leftptr);
	this->rec_output(ptr->rightptr);
}


template<typename valueType>
bool tree<valueType>::rec_search(valueType n, node *ptr) {
	if (!ptr) {
		return 0;
	}
	if (ptr->data == n) {
		return 1;
	}
	bool temp = this->rec_search(n,ptr->leftptr);
	if (temp == true) return temp;
	temp = this->rec_search(n,ptr->rightptr);
}

template<typename valueType>
bool tree<valueType>::search(valueType n) {
	return rec_search(n, head);
}


template<typename valueType>
bool tree<valueType>::deleteNode(valueType n) {
	
	if (head->leftptr == nullptr && head->rightptr == nullptr) {
		node* t = head;
		head = nullptr;
		delete t;
		return 1;
	}


	node* ptr = head;
	node* ptrPrev = head;

	
	while (1) {
		if (ptr == nullptr) {
			return 0;
		}
		//нашли элемент для удаления
		if (ptr->data == n) {
			//если у узла нет дочерних узлов
			if (!ptr->leftptr && !ptr->rightptr)
			{
				if (n > ptrPrev->data) {
					ptrPrev->rightptr = nullptr;
				}
				else {
					ptrPrev->leftptr = nullptr;
				}
				delete ptr;
				return 1;
			}
			//если есть один дочерний узел
			if (!ptr->leftptr || !ptr->rightptr)
			{
				
				if (!ptr->leftptr)
				{
					//проверка на удаление первого узла 
					if (ptr == head) {
						head = ptr->rightptr;
						delete ptr;
						return 1;
					}
					if (ptrPrev->leftptr == ptr) {
						ptrPrev->leftptr = ptr->rightptr;
					}
					else {
						ptrPrev->rightptr = ptr->rightptr;
					}
					node* temp = ptr->rightptr;
					temp->prevptr = ptrPrev;

				}
				else if (!ptr->rightptr) {
					//проверка на удаление первого узла 
					if (ptr == head) {
						head = ptr->leftptr;
						delete ptr;
						return 1;
					}
					if (ptrPrev->leftptr == ptr) {
						ptrPrev->leftptr = ptr->leftptr;
					}
					else {
						ptrPrev->rightptr = ptr->leftptr;
					}
					node* temp = ptr->leftptr;
					temp->prevptr = ptrPrev;

				}
				delete ptr;
				return 1;
			}
			//у узла два дочерних элемента 
			if (ptr->leftptr && ptr->rightptr)
			{
				node* temp = ptr->leftptr;
				if (!temp->leftptr && !temp->rightptr) {
					temp->rightptr = ptr->rightptr;
					temp->leftptr = nullptr;
					temp->prevptr = ptrPrev;
					//проверка на удаление первого узла
					if (ptr == ptrPrev) {
						head = temp;
					}
					if (ptr == ptrPrev->leftptr)
					{
						ptrPrev->leftptr = temp;
					}
					else {
						ptrPrev->rightptr = temp;
					}
					delete ptr;
					return 1;
				}
				node* tempPrev = temp;
				while (1) {
					if (temp->rightptr == nullptr) {
						if (temp->leftptr) {
							tempPrev->rightptr = temp->leftptr;
							node* left = temp->leftptr;
							left->prevptr = tempPrev;
						}
						temp->leftptr = ptr->leftptr;
						temp->rightptr = ptr->rightptr;
						temp->prevptr = ptr->prevptr;
						if (ptr == ptrPrev->leftptr)
						{
							ptrPrev->leftptr = temp;
						}
						else
						{
							ptrPrev->rightptr = temp;
						}
						delete ptr;
						return 1;
					}
					tempPrev = temp;
					temp = temp->rightptr;
				}


			}


		}
		//проход по дереву 
		if (n > ptr->data) {
			ptrPrev = ptr;
			ptr = ptr->rightptr;
		}
		else {
			ptrPrev = ptr;
			ptr = ptr->leftptr;
		}


	}return false;
}


template<typename valueType>
void tree<valueType>::operator=( valueType n) {
	this->add(n);
}

template<typename valueType>
void tree<valueType>:: printTree(node* root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->data << endl;
	printSubtree(root, "");
	cout << endl;
}

template<typename valueType>
void tree<valueType>::printSubtree(node* root, const string& prefix)
{
	if (root == NULL)
	{
		return;
	}

	bool hasLeft = (root->leftptr != NULL);
	bool hasRight = (root->rightptr != NULL);

	if (!hasLeft && !hasRight)
	{
		return;
	}

	cout << prefix;
	cout << ((hasLeft && hasRight) ? "|-- " : "");
	cout << ((!hasLeft && hasRight) ? "|-- " : "");

	if (hasRight)
	{
		bool printStrand = (hasLeft && hasRight && (root->rightptr->rightptr != NULL || root->rightptr->leftptr != NULL));
		string newPrefix = prefix + (printStrand ? "|   " : "    ");
		cout << root->rightptr->data << endl;
		printSubtree(root->rightptr, newPrefix);
	}

	if (hasLeft)
	{
		cout << (hasRight ? prefix : "") << "|-- " << root->leftptr->data << endl;
		printSubtree(root->leftptr, prefix + "    ");
	}
}

//template<typename valueType>
//void tree<valueType>::menu() {
//	valueType temp;
//	while (1) {
//		print();
//		cin >> in;
//		system("cls");
//		switch (in) {
//		case 1:
//			cout << " input value plz\n";
//			cin >> temp;
//			n = temp;
//			break;
//		case 2:
//			cout << "\n";
//			n.output();
//			cout << "\n";
//			break;
//		case 3:
//			cout << " input value plz\n";
//			cin >> temp;
//			n.deleteNode(temp);
//			break;
//		case 4:
//			cout << " input value plz\n";
//			cin >> temp;
//			if (n.search(temp)) cout << "true\n";
//			else cout << "false\n";
//			break;
//		case 5:return 0;
//		default: break;
//		}
//	}
//}


//template class tree<int>;
//template class tree<float>;
//template class tree<char>;
//template class tree<a>;