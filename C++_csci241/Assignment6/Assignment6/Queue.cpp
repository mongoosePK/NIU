/*********************************************************************
PROGRAM:    CSCI 241 Assignment 6
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
Queue::Queue()
{
	queueArray = new int[0];
	queueSize = 0;
	queueCapacity = 0;
	queueFront = 0;
	queueBack = queueCapacity - 1;
}
Queue::~Queue()
{
	delete queueArray;
}
Queue::Queue(const Queue &queue)
{
	this->queueArray = queue.queueArray;
	this->queueFront = queue.queueFront;
	this->queueBack = queue.queueBack;
	this->queueSize = queue.queueSize;
	this->queueCapacity = queue.queueCapacity;
}
Queue& Queue::operator=(const Queue &queue)
{
	this->queueArray = queue.queueArray;
	this->queueFront = queue.queueFront;
	this->queueBack = queue.queueBack;
	this->queueSize = queue.queueSize;
	this->queueCapacity = queue.queueCapacity;
	return *this;
}
ostream& operator<<(ostream &out, const Queue &queue)
{
	size_t current, i;
	for (current = queue.queueFront, i = 0; i < queue.queueSize; ++i)
	{
		// Print queue element at subscript i
		out << queue.queueArray[current] << ' ';
		// Increment i, wrapping around to front of queue array if necessary    
		current = (current + 1) % queue.queueCapacity;
	}
	return out;
}
void Queue::clear()
{
	queueSize = 0;
	queueCapacity = 0;
	queueFront = 0;
	queueBack = queueCapacity - 1;
}
size_t Queue::size() const
{
	return queueSize;
}
size_t Queue::capacity() const
{
	return queueCapacity;
}
bool Queue::empty() const
{
	return (queueSize == 0);
}
int Queue::front() const
{
	if (empty())
		throw underflow_error("underflow error");
	else
		return queueArray[queueFront];
}
int Queue::back() const
{
	if (empty())
		throw underflow_error("underflow error");
	else
		return queueArray[queueBack];
}
void Queue::push(int item)
{
	if (queueSize == queueCapacity)
	{
		if (queueSize == 0)
			reserve(queueCapacity + 1);
		else
			reserve(queueCapacity * 2);
	}
	queueBack = (queueBack + 1) % (queueCapacity);
	queueArray[queueBack] = item;
	queueSize++;
}
void Queue::pop()
{
	if (empty())
		throw underflow_error("underflow error");
	else
	{
		queueFront = (queueFront + 1) % queueCapacity;
		queueSize--;
	}
}
void Queue::reserve(size_t newSize)
{
//queueArray = new int[queueCapacity];
	int *newArray = new int[newSize];
	if (queueFront > queueBack)
	{
		int i = 0;
		for (i = queueFront; i < queueCapacity; i++)
		{
			newArray[i - (queueBack + 1)] = queueArray[i];
		}

		for (int j = 0;j <= queueBack; j++)
		{
			newArray[i - (queueBack + 1)] = queueArray[j];
			i++;
		}
		queueFront = 0;
		queueBack = queueCapacity - 1;
	}
	else
	{
		for (int i = queueFront; i < queueSize; i++)
		{
			newArray[i] = queueArray[i];
		}
	}
	delete[] queueArray;
	queueArray = newArray;
	queueCapacity = newSize;
}