#pragma once
#include<iostream>

using namespace std;

template <class T >
class clsDblLinkedList
{
protected:
	int _Size = 0;

public:

	// Inner class that represents each node
	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;
	};

	Node* Head = NULL;

	
	// Insert a node at the start of a double linked list
	void InsertAtBeginning(T x)
	{
		Node* node = new Node();
		node->value = x;
		node->next = Head;
		node->prev = NULL;

		if (Head != NULL)
		{
			Head->prev = node;
		}

		Head = node;
		_Size++;
	}

	// Insert a node at the end of a double linked list
	void InsertAtEnd(T x)
	{
		Node* newNode = new Node();
		newNode->value = x;
		newNode->next = NULL;

		if (Head == NULL)
		{
			newNode->prev = NULL;
			Head = newNode;
		}

		else
		{
			Node* Current = Head;

			while (Current->next != NULL)
			{
				Current = Current->next;
			}

			Current->next = newNode;
			newNode->prev = Current;
		}

		_Size++;

	}

	// Insert a node after another specified node in a double linked list
	void InsertAfter(Node* Current, T x)
	{
		Node* newNode = new Node();
		newNode->value = x;
		newNode->next = Current->next;
		newNode->prev = Current;

		if (Current->next != NULL)
		{
			Current->next->prev = newNode;
		}

		Current->next = newNode;

		_Size++;
	}

	// Insert a node after another specified node using its index in a double linked list
	bool InsertAfter(int index, T x)
	{
		Node* N = GetNode(index);

		if (N == NULL)
			return false;

		InsertAfter(N, x);
		return true;
	}

	// Delete a specific node ( get its pointer using the " FindNode " method ) in a double linked list
	void DeleteNode(Node*& NodeToDelete)
	{
		if (Head == NULL || NodeToDelete == NULL)
		{
			return;
		}

		if (Head == NodeToDelete)
		{
			Head = NodeToDelete->next;
		}

		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}

		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}

		delete NodeToDelete;

		_Size--;
	}

	// Delete the first node in a double linked list
	void DeleteFirstNode()
	{
		if (Head == NULL)
		{
			return;
		}

		Node* Temp = Head;

		Head = Head->next;

		if (Head != NULL)
		{
			Head->prev = NULL;
		}

		delete Temp;
		_Size--;
	}

	// Delete the last node in a double linked list
	void DeleteLastNode()
	{
		if (Head == NULL)
		{
			return;
		}

		if (Head->next == NULL)
		{
			delete Head;
			Head = NULL;
			_Size--;
			return;
		}

		Node* Current = Head;

		while (Current->next->next != NULL)
		{
			Current = Current->next;
		}

		Node* Temp = Current->next;
		Current->next = NULL;
		delete Temp;

		_Size--;
	}

	// Find a node in a double linked list using its value
	Node* FindNode(T x)
	{

		Node* Current = Head;

		while (Current != NULL)
		{
			if (Current->value == x)
			{
				return Current;
			}

			Current = Current->next;
		}

		return NULL;
	}

	// Print the value of each node in the linked list
	void PrintList()
	{
		Node* Temp = Head;

		cout << "NULL <--> ";
		while (Temp != NULL)
		{
			cout << Temp->value << " <--> ";
			Temp = Temp->next;
		}
		cout << "NULL\n\n";

	}

	int Size()
	{
		// Get the list size in O(1)
		// _Size is incremented and decremented in any insert or delete method to keep track of the list size

		return _Size;

	}

	// Check if the list is empty using its size
	bool IsEmpty()
	{
		return _Size == 0 ? 1 : 0;
	}

	// Delete all nodes in the list
	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* Temp = Head;

		while (Temp != NULL)
		{
			// Store the prev and next pointers in temp pointers
			Node* Temp1 = Head->next;
			Node* Temp2 = Head->prev;

			// Move to the next node
			Temp = Temp->next;

			// Swap the two pointers
			Head->next = Temp2;
			Head->prev = Temp1;

			// Change the Head of the list
			if (Temp != NULL)
			{
				Head = Temp;

			}

		}
	}

	// Get a node pointer at specific index
	Node* GetNode(int index)
	{
		Node* Temp = Head;

		int current = 0;

		// Same as index out of range in an array
		if (index > _Size - 1 || index < 0)
		{
			return NULL;
		}

		// Iterate till reaching the node with the specified index
		while (Temp != NULL)
		{
			if (current == index)
			{
				return Temp;
			}

			Temp = Temp->next;
			current++;
		}

	}

	// Get node value at specified index
	T GetItem(int index)
	{
		Node* Item = GetNode(index);

		if (Item == NULL)
			return NULL;

		return Item->value;

		
	}

	bool UpdateItem(int index, T value)
	{
		Node* Item = GetNode(index);

		if (Item == NULL)
			return false;

		Item->value = value;
		return true;
	}
};

