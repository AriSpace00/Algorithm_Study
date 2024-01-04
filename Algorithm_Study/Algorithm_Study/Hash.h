#pragma once
#include <vector>
#include <string>
#include <iostream>

constexpr int HASH_SIZE = 8191;

template <typename T>
class Hash
{
public:
	Hash();
	~Hash();

private:
	std::vector<std::vector<T>> m_data;

public:
	void Insert(T value);
	void Find(int key);
	void Erase(int key);
	void ShowData();
	void ShowInfo();
};

template <typename T>
inline Hash<T>::Hash()
{
	m_data.resize(HASH_SIZE);
}

template <typename T>
inline Hash<T>::~Hash()
{
}

template <typename T>
void Hash<T>::Insert(T value)
{
	int index = (((5381 << 5) + 5381) + static_cast<int>(value)) % HASH_SIZE;

	if (m_data[index].empty())
	{
		std::vector<T> chainingVector;
		chainingVector.push_back(value);
		m_data[index] = std::move(chainingVector);
	}
	else
	{
		m_data[index].push_back(value);
	}
}

template <>
void Hash<std::string>::Insert(std::string value)
{
	int index = (((5381 << 5) + 5381) + value.length()) % HASH_SIZE;

	if (m_data[index].empty())
	{
		std::vector<std::string> chainingVector;
		chainingVector.push_back(value);
		m_data[index] = std::move(chainingVector);
	}
	else
	{
		m_data[index].push_back(value);
	}
}

template <typename T>
inline void Hash<T>::Find(int key)
{
}

template <typename T>
inline void Hash<T>::Erase(int key)
{
}

template <typename T>
inline void Hash<T>::ShowData()
{
	for (int i = 0; i < m_data.size(); i++)
	{
		for (int j = 0; j < m_data[i].size(); j++)
		{
			if (!m_data[i][j].empty())
			{
				std::cout << "[" << i << "][" << j << "] : " << m_data[i][j] << std::endl;
			}
		}
	}
}

template <typename T>
void Hash<T>::ShowInfo()
{
	int count = 0;

	for (int i = 0; i < m_data.size(); i++)
	{
		if (m_data[i].size() > 1)
		{
			count++;
		}
	}

	std::cout << "충돌된 버킷 수 : " << count << std::endl;
}