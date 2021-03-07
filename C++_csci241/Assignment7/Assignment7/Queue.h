// william Pulkownik
// Assignment 7 'Queue.h'
// 10 NOV 2016

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using std::cout;
using std::underflow_error;
template <class T>
struct Node {
public:
	T data;
	Node<T>* next;
	//constructor

	Node(const T& = T(), Node <T>* next = nullptr);
};
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext) {
	data = newData;
	next = newNext;
}
//template declaration
template <class T>
class Queue;
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue {
	friend std::ostream& operator<< <> (std::ostream&, const Queue<T>&);
private:
	Node<T>* qFront;
	Node<T>* qBack;
	size_t qSize;
public:
	//d. constructor and destructor and copy constructor
	Queue();
	~Queue();
	Queue(const Queue<T>& other);
	Queue<T>& operator=(const Queue<T>&);
	void clear();
	size_t size();
	bool empty();
	const T& front() const;
	const T& back() const;
	void push(const T&);
	void pop();
	void copyList(const Queue<T>&);
};
/****************END QUEUE CLASS DECLARATION*************************/
/****************BEGIN QUEUE CLASS DEFINITIONS*************************/

template <class T>
Queue<T>::Queue() {
	qFront = qBack = nullptr;
	qSize = 0;
}
template <class T>
Queue<T>::~Queue() {
	clear();
}
template <class T>
Queue<T>::Queue(const Queue<T>& other) {
	qFront = qBack = nullptr;
	qSize = 0;
	copylist(other);
}
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
	if (this != &other)
	{
		clear();
		copyList(other);
	}
	return *this;
}
template <class T>
void Queue<T>::copyList(const Queue<T>& other) {
	Node<T>* ptr;
	for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
		push(ptr->data);
}
template <class T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& in) {
	size_t current, i;
	Node<T> ptr;
	for (ptr = in.qFront; ptr != nullptr; ptr = ptr->next)
		out << ptr->data << ' ';
	return out;
}
template <class T>
void Queue<T>::pop() {
	if (qFront == nullptr)
		throw underflow_error("underflow error during pop");
	Node<T>* delNode = qFront; //remove first node
	qFront = qFront->next;
	if (qFront == nullptr)
		qBack = nullptr;
	delete delNode;
	--qSize;
}

template <class T>
void Queue<T>::push(const T& stuff) {
	Node<T>* newNode = new Node<T>(stuff);
	if (qFront == nullptr)
		qFront = newNode;
	else
		qBack->next = newNode;
	++qSize;
}

template <class T>
void Queue<T>::clear() {
	while (qFront != nullptr)
		pop();
}


template <class T>
bool Queue<T>::empty() {
	bool isEmpty = (qFront == nullptr ? true : false);
	return isEmpty;
}
template <class T>
const T& Queue<T>::front() const {
	if (empty())
		throw underflow_error("underflow error for front()");
	return qFrontdata;
}

template <class T>
const T& Queue<T>::back() const {
	if (empty())
		throw underflow_error("underflow error for back()");
	return qBack->data;
}

template <class T>
size_t Queue<T>::size() {
	size_t qSize = this->qSize;
	return qSize;
}
#endif
