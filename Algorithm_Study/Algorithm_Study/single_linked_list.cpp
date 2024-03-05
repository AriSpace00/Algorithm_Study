#include "single_linked_list.h"

void main()
{
	cout << "int" << endl;
	SingleLinkedList<int> list1;
	list1.Print();
	list1.PushBack(1);
	list1.Print();
	list1.PushBack(2);
	list1.Print();
	list1.PushBack(3);
	list1.Print();
	list1.PushBack(42);
	list1.Print();
	list1.PushBack(442);
	list1.Print();
	list1.PushBack(244);
	list1.Print();

	cout << "float" << endl;
	SingleLinkedList<float> list2;
	list2.Print();
	list2.PushBack(1.2f);
	list2.PushBack(5.4f);
	list2.PushBack(1.6f);
	list2.PushBack(1.3f);
	list2.PushBack(1.99f);
	list2.PushBack(9.8f);
	list2.PushBack(1.10f);
	list2.PushBack(1.01f);
	list2.PushBack(1.0111f);
	list2.PopBack();
	list2.Print();

	cout << "char" << endl;
	SingleLinkedList<char> list3;
	list3.Print();
	list3.PushBack('a');
	list3.PushBack('b');
	list3.PushBack('c');
	list3.PushBack('d');
	list3.PushBack('e');
	list3.PushBack('f');
	list3.PushBack('g');
	list3.PushBack('h');
	list3.PushBack('i');
	list3.PushBack('j');
	list3.PushBack('k');
	list3.Print();
	list3.PopBack();
	list3.PopBack();
	list3.PopBack();
	list3.PopBack();
	list3.Print();

}