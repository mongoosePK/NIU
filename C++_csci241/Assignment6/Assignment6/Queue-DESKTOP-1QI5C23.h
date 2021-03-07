#ifndef QUEUE_H
#define QUEUE_H
/*********************************************************************
PROGRAM:    Queue.h
PROGRAMMER: William Pulkownik
LOGON ID:   z1805341
DUE DATE:   1 NOV 2016

FUNCTION:   This program defines the functionality of the Queue
class.
*********************************************************************/
#include <iostream>
#include <stdexcept>
#include "Queue.h"
using std::ostream;
using std::cout;
using std::endl;
using std::underflow_error;
//class definition
class Queue 
{
	//ostream friend
	friend ostream& operator<<(ostream &out, const Queue &queue);
private:
	int *queueArray;
	size_t queueCapacity;
	size_t queueSize;
	int queueFront, queueBack;
public:
	Queue() // functional constructor
	{
		queueArray = nullptr;
		queueSize = 0;
		queueCapacity = 0;
		queueFront = 0;
		queueBack = queueCapacity - 1;
	}
	~Queue();
	//method declatations
	Queue(const Queue &queue);
	Queue& operator=(const Queue &queue);
	void clear();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	int front() const;
	int back() const;
	void push(int item);
	void pop();
	void reserve(size_t n);
};
#endif
