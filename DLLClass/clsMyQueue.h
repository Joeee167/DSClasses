#pragma once
#include<iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T>
class clsMyQueue
{


protected:

	clsDblLinkedList<T> _MyList;

public:

	void push(T item)
	{
		_MyList.InsertAtEnd(item);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();

	}

	int Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	T GetItem(int index)
	{
		return _MyList.GetItem(index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int index, T value)
	{
		_MyList.UpdateItem(index, value);
	}

	void InsertAfter(int index, T value)
	{
		_MyList.InsertAfter(index, value);
	}

	void InsertAtFront(T x)
	{
		_MyList.InsertAtBeginning(x);
	}

	void InsertAtBack(T x)
	{
		_MyList.InsertAtEnd(x);
	}

	void Clear()
	{
		_MyList.Clear();
	}

	
};

