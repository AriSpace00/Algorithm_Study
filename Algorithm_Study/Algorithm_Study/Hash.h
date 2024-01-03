#pragma once
#include <vector>
#include <string>
#include <iostream>

template <typename T>
class Hash
{
public:
    Hash();
    ~Hash();

private:
    std::vector<std::vector<T>> m_typeData;

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
    m_typeData.resize(8191);
}

template <typename T>
inline Hash<T>::~Hash()
{
}

template <typename T>
void Hash<T>::Insert(T value)
{
    int index;
    index = (((5381 << 5) + 5381) + static_cast<int>(value)) % 8191;
    m_typeData[index].push_back(value);
}

template <>
void Hash<std::string>::Insert(std::string value)
{
    int index = (((5381 << 5) + 5381) + value.length()) % 8191;
    m_typeData[index].push_back(value);
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
    for (int i = 0; i < m_typeData.size(); i++)
    {
        for (int j = 0; j < m_typeData[i].size(); j++)
        {
            if (!m_typeData[i][j].empty())
            {
                std::cout << "[" << i << "][" << j << "] : " << m_typeData[i][j] << std::endl;
            }
        }
    }
}

template <typename T>
void Hash<T>::ShowInfo()
{
    int count = 0;

    for (int i = 0; i < m_typeData.size(); i++)
    {
        if (m_typeData[i].size() > 1)
        {
            count++;
        }
    }

    std::cout << "충돌된 버킷 수 : " << count << std::endl;
}