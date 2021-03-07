#ifndef QUEUE_H
#define QUEUE_H
/*********************************************************************
PROGRAM:    Queue.h
PROGRAMMER: William Pulkownik
LOGON ID:   z1805341
DUE DATE:   due date of assignment

FUNCTION:   This program tests the functionality of the Queue
class.
*********************************************************************/
#include <iostream>
#include <stdexcept>
#include "Queue.h"

using std::cout;
using std::endl;
using std::underflow_error;

class Queue {
	friend ostream& operator<<(ostream &out, const Queue &queue);
private:
	int *queueArray;
	size_t queueCapacity;
	size_t queueSize;
	int queueFront, queueBack;
public:
	Queue(int* queueArray = nullptr, int queueCapacity = 0,
	int queueSize = 0, int queueFront = 0, 
		int queueBack = queueCapacity - 1;
	~Queue();
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
	void reserve(size_t newSize);
};
#endif