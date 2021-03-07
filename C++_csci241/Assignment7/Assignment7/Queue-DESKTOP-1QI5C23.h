// william Pulkownik
// z1805341
// Assignment 7 'Queue.h'
// 10 NOV 2016
// this program declares and defines a linked queue ADT template
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using std::cout;
using std::underflow_error;
// define struct node
template <class T>
struct Node {
public:
	T data;
	Node<T>* next;
	//constructor sets default values for data types
	Node(const T& = T(), Node <T>* next = nullptr);
};
// alternate constructor takes data types and creates node
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext) {
	data = newData;
	next = newNext;
}
//template  forward-declaration 
template <class T>
class Queue;
// ostream out overload forward declaration
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue {
	//friend declaration of ostream out operator
	friend std::ostream& operator<< <> (std::ostream&, const Queue<T>&);
	
private:
	Node<T>* qFront; //declare queue data members
	Node<T>* qBack;
	size_t qSize;
	//declare copyList member function
	void copyList(const Queue<T>& other);
public:
	//default constructor and destructor and copy constructor declared
	Queue();
	~Queue();
	Queue(const Queue<T>& other);
	//method declarations
	Queue<T>& operator=(const Queue<T>&);
	void clear();
	size_t size() const;
	bool empty() const;
	const T& front() const;
	const T& back() const;
	void push(const T&);
	void pop();
};
/****************END QUEUE CLASS DECLARATION*************************/

/****************BEGIN QUEUE CLASS DEFINITIONS*************************/

//copyList takes a queue obj and copies its data to another queue obj
template <class T>
void Queue<T>::copyList(const Queue<T>& other) {
	Node<T>* ptr;
	for (ptr = other.qFront; ptr != nullptr; ptr = ptr->next)
		push(ptr->data);
}
//default constructor creates new empty queue of given data type
template <class T>
Queue<T>::Queue() {
	qFront = qBack = nullptr;
	qSize = 0;
}
// destructor calls clear method
template <class T>
Queue<T>::~Queue() {
	clear();
}
// copy constructor creates new queue obj from existing one
template <class T>
Queue<T>::Queue(const Queue<T>& other) {
	qFront = qBack = nullptr;
	qSize = 0;
	this->copyList(other);
}
// overload of assignment operator accepts queue and copies its data in
// to new queue
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
	if (this != &other)
	{
		clear();
		copyList(other);
	}
	return *this;
}
// overload of ostream out operator takes << and queue obj & returns std::out
template <class T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& in) {
	Node<T>* ptr;
	for (ptr = in.qFront; ptr != nullptr; ptr = ptr->next)
		out << ptr->data << ' ';
	return out;
}
// pop removes item from front of a queue obj & decreases size
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
// push inserts data member from arg into front if empty or back if populated
// moves back and increases qSize
template <class T>
void Queue<T>::push(const T& stuff) {
	Node<T>* newNode = new Node<T>(stuff);
	if (qFront == nullptr)
		qFront = newNode;
	else
		qBack->next = newNode;
	qBack = newNode;
	++qSize;
}
// clear() pops data while queue contains any
template <class T>
void Queue<T>::clear() {
	while (qFront != nullptr)
		pop();
}
// empty() checks size of queue and returns true if empty ... false if not
template <class T>
bool Queue<T>::empty() const {
	bool isEmpty = (qFront == nullptr ? true : false);
	return isEmpty;
}
// front() throws error if queue empty ... otherwise returns front data member
template <class T>
const T& Queue<T>::front() const {
	if (empty())
		throw underflow_error("underflow error for front()");
	return qFront->data;
}
// back() throws error if queue empty ... otherwise returns rear data member
template <class T>
const T& Queue<T>::back() const {
	if (empty())
		throw underflow_error("underflow error for back()");
	return qBack->data;
}
// size() returns qSize
template <class T>
size_t Queue<T>::size() const {
	return qSize;
}
#endif