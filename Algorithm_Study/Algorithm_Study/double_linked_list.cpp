#include "double_linked_list.h"

void main()
{
	DoubleLinkedList<int> list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(2);
	list1.PushBack(2);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	list1.PrintAll();
	list1.DeleteNode(2);
	list1.PrintAll();

}