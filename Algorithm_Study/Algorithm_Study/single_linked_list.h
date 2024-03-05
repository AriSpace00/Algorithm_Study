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
	// 단일 연결 리스트 생성할 때 nullptr인 headNode 생성
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

	cout << "단일 리스트를 삭제하였습니다." << endl;
}

/// 리스트의 마지막에 노드 삽입
template <typename T>
void SingleLinkedList<T>::PushBack(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->node = nullptr;

	// 1. 리스트가 빈 경우
	if (headNode->data == 0 && headNode->node == nullptr)
	{
		headNode = newNode;
		return;
	}

	// 2. 리스트에 노드가 하나만 있는 경우 (headNode만 있는 경우)
	if (headNode->data != 0 && headNode->node == nullptr)
	{
		headNode->node = newNode;
		return;
	}

	// 3. 리스트에 여러 노드가 있는 경우
	if (headNode->data != 0 && headNode->node != nullptr)
	{
		Node<T>* lastNode = headNode->node;
		while (lastNode->node != nullptr)
			lastNode = lastNode->node;
		lastNode->node = newNode;
	}
}

/// 리스트의 마지막 노드 제거
template <typename T>
void SingleLinkedList<T>::PopBack()
{
	// 1. 리스트가 빈 경우
	if (headNode->node == nullptr)
	{
		if (headNode->data != 0)
			headNode->data = 0;
		else
			return;
	}

	if (headNode->data != 0)
	{
		// 2. 리스트에 노드가 하나만 있는 경우 (headNode만 있는 경우)
		if (headNode->node == nullptr)
		{
			headNode->data = 0;
			return;
		}

		// 3. 리스트가 차있는 경우
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

/// 리스트의 모든 노드 출력
template <typename T>
void SingleLinkedList<T>::Print()
{
	// 1. 리스트가 빈 경우
	if (headNode->data == 0 && headNode->node == nullptr)
	{
		cout << "리스트에 노드가 하나도 없습니다." << endl;
		return;
	}

	// 2. 리스트가 차있는 경우
	if (headNode->data != 0)
	{
		cout << "단일 연결 리스트 : [";
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
