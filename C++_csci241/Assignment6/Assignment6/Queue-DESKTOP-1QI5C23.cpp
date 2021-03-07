/*********************************************************************
PROGRAM:    CSCI 241 Assignment 6 Queue.cpp
PROGRAMMER: William Pulkownik
LOGON ID:   z1805341
DUE DATE:   due date of assignment

FUNCTION:   This program implements functionality of the Queue
class.
*********************************************************************/


#include "Queue.h"

//constructor defined in header file for class

/***************************************************************
destructor / copy constructor
Use: clear memory / make deep copy of queue object
Parameters: none / queue obj
Returns: nothing / creates a queue obj
***************************************************************/
Queue::~Queue()
{
	delete[] queueArray;
}
Queue::Queue(const Queue &queue)
{
	queueCapacity = queue.queueCapacity;
	queueSize = queue.queueSize;
	queueArray = new int[queueCapacity];

	for (size_t i = 0; i < queueCapacity; ++i)
		queueArray[i] = queue.queueArray[i];

	queueFront = queue.queueFront;
	queueBack = queue.queueBack;
}
/***************************************************************
assignment operator overload
Use: allow use of = with queue class
Parameters: const Queue obj
Returns: dereferenced pointer to calling object
***************************************************************/
Queue& Queue::operator=(const Queue &queue)
{
	if (this != &queue) //prevent self assignment
	{
		delete[] queueArray;
		queueCapacity = queue.queueCapacity;
		queueSize = queue.queueSize;
		queueArray = new int[queueCapacity];

		for (size_t i = 0; i < queueCapacity; ++i)
			queueArray[i] = queue.queueArray[i];
		queueFront = queue.queueFront;
		queueBack = queue.queueBack;
	}
	return *this;
}
/***************************************************************
output stream operator overload
Use: allows use of << with queue
Parameters: ostream obj, const queue obj
Returns: out stream obj
***************************************************************/
ostream& operator<<(ostream &out, const Queue &queue)
{
	size_t i, cell;
	for (cell = queue.queueFront, i = 0; i < queue.queueSize; ++i)
	{
		// Print queue element at subscript i
		out << queue.queueArray[cell] << ' ';
		// Increment i, wrapping around to front of queue array if necessary    
		cell = (cell + 1) % queue.queueCapacity;
	}
	return out;
}
/***************************************************************
clear ()
Use: reset queue to empty state
Parameters: none
Returns: nothing
***************************************************************/
void Queue::clear()
{
	queueSize = 0;
	queueCapacity = 0;
	queueFront = 0;
	queueBack = queueCapacity - 1;
}
/***************************************************************
size()
Use: get qSize
Parameters: none
Returns: size_t queueSize
***************************************************************/
size_t Queue::size() const
{
	return queueSize;
}
/***************************************************************
capacity()
Use: get qcapacity
Parameters: none
Returns: size_t qCap
***************************************************************/
size_t Queue::capacity() const
{
	return queueCapacity;
}
/***************************************************************
empty()
Use: checks if qsize == 0
Parameters: none
Returns: boolean 
***************************************************************/
bool Queue::empty() const
{
	return (queueSize == 0);
}
/***************************************************************
front()
Use: error check / test for q emptiness
Parameters: none
Returns: error (fail) qArray front (good)
***************************************************************/
int Queue::front() const
{
	if (empty())
		throw underflow_error("underflow error");
	else
		return queueArray[queueFront];
}
/***************************************************************
back()
Use: error check / test for q emptiness
Parameters: none
Returns: error (fail) qArray back (good)
***************************************************************/
int Queue::back() const
{
	if (empty())
		throw underflow_error("underflow error");
	else
		return queueArray[queueBack];
}
/***************************************************************
push()
Use: insert items on to back of queue
Parameters: int number
Returns: nothing 
***************************************************************/
void Queue::push(int num)
{
	if (queueSize == queueCapacity)
	{
		if (queueSize == 0)
			reserve(1);
		else
			reserve(queueCapacity * 2);
	}
	queueBack = (queueBack + 1) % (queueCapacity);
	queueArray[queueBack] = num;
	queueSize++;
}
/***************************************************************
pop()
Use: remove item from from queue
Parameters: none
Returns: nothing
***************************************************************/
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
/***************************************************************
reserve()
Use: Requests that the vector capacity be at least enough to contain n elements.
	If n is greater than the current vector capacity,
	the function causes the container to reallocate its storage 
	increasing its capacity to n (or greater).
Parameters: size_t number
Returns: nothing
***************************************************************/
void Queue::reserve(size_t n)
{
		if (n > queueCapacity)
	{
		int* tempArray = new int[n];

		int current = queueFront;
		for (size_t i = 0; i < queueSize; i++)
		{
			tempArray[i] = queueArray[current];
			current = (current + 1) % queueCapacity;
		}

		queueCapacity = n;
		queueFront = 0;
		queueBack = queueSize - 1;
		delete[] queueArray;
		queueArray = tempArray;
	}
}
	