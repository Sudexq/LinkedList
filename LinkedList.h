#pragma once

#include <iostream>
using namespace std;

template <class T>
struct nodeType {
	T data;
	nodeType* link;
};

template <class T>
class LinkedList {
	nodeType* first, * last;
	int count;
public:
	LinkedList();
	void insertFirst(T item);
	void insertLast(T item);
	void insertAt(T item, int pos);
	void print();
	bool simplecompare(LinkedList<T>& rL);
	int compare(LinkedList<T>& rL);
	~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList() {
	first = NULL;
	last = NULL;
	count = 0;
}

template<class T>
void LinkedList<T>::insertFirst(T item) {
	nodeType<T>* newNode = new nodeType<T>; //crating a new node for we inserting item
	newNode->data = item; //give a data which is item to that we created
	newNode->link = first; //location is first so we pointed first
	first = newNode; //and our new node is our first node
	if (last == NULL) //if last element is null so we have one element which is we created newNode
		last = newNode;

	count++; //now we have 1 more node
}

template<class T>
void LinkedList<T>::insertLast(T item)
{
	nodeType<T>* newNode = new nodeType<T>; //we created a node
	newNode->data = item; //giving data(item) to node
	newNode->link = NULL; //last element is linking NULL
	if (first == NULL)
		first = newNode; //if there is no element so newNode is first element
	else
		last->link = newNode; //if there are elements last linking newNode

	last = newNode;
	count++;
}

template<class T>
void LinkedList<T>::insertAt(T item, int pos)
{
	if (pos == 0) { //if at first we use insertFirst func
		insertFirst(item);
	}
	else if (pos >= count - 1) { //if at last we use insertLast func
		insertLast(item);
	}
	else {
		nodeType<T>* newNode = new nodeType<T>; //we created newNode
		newNode->data = item; //data is item
		nodeType<T>* cur = first; //we created a pointer which is following position
		for (int i = 0; i < pos - 1; i++, cur = cur->link)
			newNode->link = cur->link;
	}
	count++;
}

template<class T>
void LinkedList<T>::print()
{
	nodeType<T>* cur;
	for (cur = first; cur != last; cur = cur->link)
		cout << cur->data << " ";
	cout << cur->data << endl
}

template<class T>
bool LinkedList<T>::simplecompare(LinkedList<T>& rL)
{
	if (count != rL.count)
		return false;

	nodeType<T>* cur, * rCur;
	for (cur = first, rCur = rL.first; cur != NULL; cur = cur->link, rCur = rCur->link)
		if (cur->data != rCur->data)
			return false;
	return true;
}

template<class T>
int LinkedList<T>::compare(LinkedList<T>& rL)
{
	nodeType<T>* cur = first, * rCur = rL.first;

	for (; cur && rCur && (cur->data == rCur->data);
		cur = cur->link, rCur = rCur->link);

	if (cur == NULL) {
		if (rCur == NULL)
			return 0;
		else return -1;
	}
	else if (rCur == NULL)
		return 1;
	else
		return (cur->data > rCur->data) ? 1 : -1;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	nodeType<T>* temp;
	while (first != NULL) {
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}
