#include "singlyLinkedList.h"
#include <iostream>


using namespace std;


int main()
{
	SinglyLinkedList list;

	// Adding nodes
	cout << "Adding elements!" << endl << "-----------" << endl;
	list.printList();
	list.insertAtLast(17);
	list.printList();
	list.insertAtLast(28);
	list.printList();
	list.insertAtFirst(1);
        list.printList();
	list.insertAt(1,-100);
	list.printList();
	list.insertAt(100,100);
	list.printList();
	list.insertAtLast(3800);
	list.printList();
	list.insertAt(2,2222);
	list.printList();
	list.insertAt(4,4444);
	list.printList();

	// Remove nodes
	cout << "Removing elements!" << endl << "-----------" << endl;
      list.removeFirstNode();
	list.printList();
      list.removeFirstNode();
	list.printList();
	list.removeLastNode();
	list.printList();
      list.removeLastNode();
	list.printList();
      list.removeNodeAt(2);
	list.printList();
      list.removeNodeAt(2);
	list.printList();
      list.removeNodeAt(3);
	list.printList();
	return 0;
}