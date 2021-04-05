#pragma once

#ifndef STACK_H
#define STACK_H
#include <cstddef>

typedef struct moves
{
	int row;
	int col;
	moves* next;
}pos;

struct node
{
	int val;
	moves pos;
	node* next;
};
class Stack
{
public:
	Stack();
	Stack(int);
	~Stack();
	bool push(int);
	bool pop(int&);
	bool peek(int&)const;
	bool isEmpty()const;
	bool isFull()const;
	bool makeEmpty();
	int getQty()const;

private:
	node* topPtr;
	int qty;
	int max;
};


inline Stack::Stack()
{
	qty = 0;
	max = 1024;
	topPtr = NULL;
}

inline Stack::Stack(int maxSize)
{
	qty = 0;
	max = maxSize;
	topPtr = NULL;
}

inline Stack::~Stack()
{
	makeEmpty();
}

inline bool Stack::push(int num)
{
	node* temp;
	if (isFull())
	{
		return false;
	}
	temp = new node;
	temp->val = num;
	temp->next = topPtr;
	topPtr = temp;
	qty++;
	return true;
}

inline bool Stack::pop(int& num)
{
	node* temp;
	if (isEmpty())
	{
		num = -1;
		return false;
	}
	temp = topPtr;
	topPtr = topPtr->next;
	num = temp->val;
	delete temp;
	qty--;
	return true;
}

inline bool Stack::peek(int& num)const
{
	if (isEmpty())
	{
		return false;
	}
	num = topPtr->val;
	return true;
}

inline bool Stack::isEmpty()const
{
	if (topPtr == NULL)
	{
		return true;
	}
	return false;
}

inline bool Stack::isFull()const
{
	if (qty >= max)
	{
		return true;
	}
	return false;
}

inline bool Stack::makeEmpty()
{
	node* temp;
	if (isEmpty())
	{
		return false;
	}
	while (topPtr != NULL)
	{
		temp = topPtr;
		topPtr = topPtr->next;
		delete temp;
	}
	qty = 0;
	return true;
}
inline int Stack::getQty()const
{
	return qty;
}

#endif