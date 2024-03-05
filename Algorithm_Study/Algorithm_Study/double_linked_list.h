#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* prevNode = nullptr;
	Node<T>* nextNode = nullptr;
};

template <typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();

public:
	Node<T>* headNode = nullptr;
	Node<T>* tailNode = nullptr;

public:
	// tailNode
	void PushBack(T data);
	void PopBack();

	// headNode
	void PushFront(T data);
	void PopFront();

	// Ư�� Node
	Node<T>* FindNode(T data);
	void DeleteNode(Node<T>* node);
	void DeleteNode(T data);

	// ��� Node
	void PrintAll();
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
}

template <typename T>
void DoubleLinkedList<T>::PushBack(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	// 1. ����Ʈ�� ������� ��
	if (tailNode == nullptr)
	{
		headNode = newNode;
		tailNode = newNode;
		return;
	}

	// 2. ����Ʈ�� ������ ��
	if (tailNode != nullptr)
	{
		tailNode->nextNode = newNode;
		newNode->prevNode = tailNode;
		tailNode = newNode;
	}
}

template <typename T>
void DoubleLinkedList<T>::PopBack()
{
	// 1. ����Ʈ�� ������� ��
	if (tailNode == nullptr)
	{
		return;
	}

	// 2. ����Ʈ�� ������ ��
	if (tailNode != nullptr)
	{
		Node<T>* prev = tailNode->prevNode;
		prev->nextNode = nullptr;
		tailNode = prev;
	}
}

template <typename T>
void DoubleLinkedList<T>::PushFront(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	// 1. ����Ʈ�� ������� ��
	if (headNode == nullptr)
	{
		headNode = newNode;
		tailNode = newNode;
		return;
	}

	// 2. ����Ʈ�� ������ ��
	if (headNode != nullptr)
	{
		headNode->prevNode = newNode;
		newNode->nextNode = headNode;
		headNode = newNode;
	}
}

template <typename T>
void DoubleLinkedList<T>::PopFront()
{
	// 1. ����Ʈ�� ������� ��
	if (headNode == nullptr)
	{
		return;
	}

	// 2. ����Ʈ�� ������ ��
	if (headNode != nullptr)
	{
		Node<T>* next = headNode->nextNode;
		next->prevNode = nullptr;
		headNode = next;
	}
}

template <typename T>
Node<T>* DoubleLinkedList<T>::FindNode(T data)
{
	// �����Ͱ� ���� ù��° ��� �ּҸ� ��ȯ
	Node<T>* currentNode = headNode;
	while(currentNode != nullptr)
	{
		if (currentNode->data == data)
		{
			return currentNode;
		}
		currentNode = currentNode->nextNode;
	}
}

template <typename T>
void DoubleLinkedList<T>::DeleteNode(Node<T>* node)
{
	// Ư�� ��� ����
	if (node == headNode && node == tailNode)
	{
		headNode = nullptr;
		tailNode = nullptr;
		return;
	}

	if (node == headNode)
	{
		PopFront();
		return;
	}
		
	if (node == tailNode)
	{
		PopBack();
		return;
	}
		
	Node<T>* prev = node->prevNode;
	Node<T>* next = node->nextNode;

	prev->nextNode = next;
	next->prevNode = prev;
}

template <typename T>
void DoubleLinkedList<T>::DeleteNode(T data)
{
	// ���� �����͸� ���� ��� ��� ����
	Node<T>* currentNode = headNode;
	while (currentNode != nullptr)
	{
		if (currentNode->data == data)
		{
			DeleteNode(currentNode);
		}
		currentNode = currentNode->nextNode;
	}
}

template <typename T>
void DoubleLinkedList<T>::PrintAll()
{
	Node<T>* currentNode = headNode;
	cout << "���� ���� ����Ʈ : [";
	while (currentNode != nullptr)
	{
		cout << currentNode->data;
		if (currentNode->nextNode != nullptr)
		{
			cout << "-->";
		}
		currentNode = currentNode->nextNode;
	}
	cout << "]" << endl;
}

