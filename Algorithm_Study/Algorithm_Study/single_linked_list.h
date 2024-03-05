#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* node;
};

template <typename T>
class SingleLinkedList
{
public:
	SingleLinkedList();
	~SingleLinkedList();

public:
	Node<T>* headNode;

public:
	void PushBack(T data);
	void PopBack();
	void Print();
};

template<typename T>
inline SingleLinkedList<T>::SingleLinkedList()
{
	// ���� ���� ����Ʈ ������ �� nullptr�� headNode ����
	headNode = new Node<T>;
	headNode->data = 0;
	headNode->node = nullptr;
}

template<typename T>
inline SingleLinkedList<T>::~SingleLinkedList()
{
	while (headNode->data != 0)
	{
		PopBack();
	}

	cout << "���� ����Ʈ�� �����Ͽ����ϴ�." << endl;
}

/// ����Ʈ�� �������� ��� ����
template <typename T>
void SingleLinkedList<T>::PushBack(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->node = nullptr;

	// 1. ����Ʈ�� �� ���
	if (headNode->data == 0 && headNode->node == nullptr)
	{
		headNode = newNode;
		return;
	}

	// 2. ����Ʈ�� ��尡 �ϳ��� �ִ� ��� (headNode�� �ִ� ���)
	if (headNode->data != 0 && headNode->node == nullptr)
	{
		headNode->node = newNode;
		return;
	}

	// 3. ����Ʈ�� ���� ��尡 �ִ� ���
	if (headNode->data != 0 && headNode->node != nullptr)
	{
		Node<T>* lastNode = headNode->node;
		while (lastNode->node != nullptr)
			lastNode = lastNode->node;
		lastNode->node = newNode;
	}
}

/// ����Ʈ�� ������ ��� ����
template <typename T>
void SingleLinkedList<T>::PopBack()
{
	// 1. ����Ʈ�� �� ���
	if (headNode->node == nullptr)
	{
		if (headNode->data != 0)
			headNode->data = 0;
		else
			return;
	}

	if (headNode->data != 0)
	{
		// 2. ����Ʈ�� ��尡 �ϳ��� �ִ� ��� (headNode�� �ִ� ���)
		if (headNode->node == nullptr)
		{
			headNode->data = 0;
			return;
		}

		// 3. ����Ʈ�� ���ִ� ���
		else
		{
			Node<T>* prevNode = headNode;
			Node<T>* lastNode = headNode->node;
			while (lastNode->node != nullptr)
			{
				prevNode = lastNode;
				lastNode = lastNode->node;
			}

			prevNode->node = nullptr;
			delete lastNode;
		}
	}
}

/// ����Ʈ�� ��� ��� ���
template <typename T>
void SingleLinkedList<T>::Print()
{
	// 1. ����Ʈ�� �� ���
	if (headNode->data == 0 && headNode->node == nullptr)
	{
		cout << "����Ʈ�� ��尡 �ϳ��� �����ϴ�." << endl;
		return;
	}

	// 2. ����Ʈ�� ���ִ� ���
	if (headNode->data != 0)
	{
		cout << "���� ���� ����Ʈ : [";
		if (headNode->node == nullptr)
		{
			cout << headNode->data << "]" << endl;
			return;
		}
		else
		{
			Node<T>* lastNode = headNode;
			cout << lastNode->data << "-->";
			while (lastNode->node != nullptr)
			{
				lastNode = lastNode->node;
				cout << lastNode->data;
				if (lastNode->node != nullptr)
				{
					cout << "-->";
				}
			}
			cout << "]" << endl;
		}

	}
}
