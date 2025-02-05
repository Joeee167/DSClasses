#include<iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{

	clsDblLinkedList <int> MydblLinkedList;

	
	MydblLinkedList.InsertAtBeginning(5);
	MydblLinkedList.InsertAtBeginning(4);
	MydblLinkedList.InsertAtBeginning(3);
	MydblLinkedList.InsertAtBeginning(2);
	MydblLinkedList.InsertAtBeginning(1);
	MydblLinkedList.InsertAtEnd(6);

	cout << "\nLinked List Content : ";
	MydblLinkedList.PrintList();

	cout << "\nNumber of items in the list : " << MydblLinkedList.Size() << endl;


	MydblLinkedList.InsertAfter(10, 100);
	MydblLinkedList.PrintList();
	
	return 0;

}