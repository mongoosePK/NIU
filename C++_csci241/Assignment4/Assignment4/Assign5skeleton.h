int *queueArray;
     size_t queueCapacity;
     size_t queueSize;
     int queueFront;
     int queueRear;
public:
     Queue();
     ~Queue();
     Queue(const Queue &queue);  
     Queue& operator=(const Queue &queue);
     friend ostream& operator<<(ostream &out, const Queue &queue);
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
#include "stdafx.h"
#include "Queue.h"
#include <iostream>
using namespace std;
Queue::Queue()
{
     queueArray = new int[0];
     queueSize = 0;
     queueCapacity = 0;
     queueFront = 0;
     queueRear = queueCapacity - 1;   
}
Queue::~Queue()
{
     delete queueArray;
}
Queue::Queue(const Queue &queue)
{   
     this->queueArray = queue.queueArray;
     this->queueFront = queue.queueFront;
     this->queueRear = queue.queueRear;
     this->queueSize = queue.queueSize;
     this->queueCapacity = queue.queueCapacity;
}
Queue& Queue::operator=(const Queue &queue)
{   
     this->queueArray = queue.queueArray;
     this->queueFront = queue.queueFront;
     this->queueRear = queue.queueRear;
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
     queueRear = queueCapacity - 1;
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
     if(empty())
          throw underflow_error("underflow error");
     else
          return queueArray[queueFront];
}
int Queue::back() const
{
     if(empty())
          throw underflow_error("underflow error");
     else
          return queueArray[queueRear];
}
void Queue::push(int item)
{   
     int old = queueCapacity;
     if(queueSize == queueCapacity)
     {
          if(queueSize == 0)
              reserve(queueCapacity + 1);
          else
              reserve(queueCapacity * 2);
     }
     queueRear = (queueRear + 1 )% (queueCapacity) ;
     queueArray[queueRear] = item;             
     queueSize++;
}
void Queue::pop()
{
     if(empty())
          throw underflow_error("underflow error");
     else
     {            
          queueFront = (queueFront + 1)%queueCapacity;
          queueSize--;
     }
}
void Queue::reserve(size_t newSize)
{        
     //queueArray = new int[queueCapacity];
     int *newArray = new int[newSize];
    
     if(queueFront > queueRear)
     {
          int i = 0;
          for(i = queueFront; i < queueCapacity ; i++)
          {        
              newArray[i-(queueRear+1)] = queueArray[i];    
          }
         
          for(int j = 0;j<=queueRear; j++)
          {
              newArray[i-(queueRear+1)] = queueArray[j];
              i++;
          }
          queueFront = 0;
          queueRear = queueCapacity-1;
     }
     else
     {                 
          for(int i = queueFront; i < queueSize; i++)
          {        
              newArray[i] = queueArray[i];        
          }            
     }
    
     delete[] queueArray;
     queueArray = newArray;
     queueCapacity = newSize;
}