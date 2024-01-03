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
    std::vector<std::vector<std::string>> m_stringData;

public:
    void Insert(T value);
    void Insert(std::string value);
    void Find(int key);
    void Erase(int key);
    void ShowTypeData();
    void ShowStringData();
};

template <typename T>
inline Hash<T>::Hash()
{
    m_typeData.resize(8191);
    m_stringData.reserve(8191);
}

template <typename T>
inline Hash<T>::~Hash()
{
}

template <typename T>
void Hash<T>::Insert(T value)
{
    int index = (((5381 << 5) + 5381) + (int)value) % 8191;
    m_typeData[index].push_back(value);
}

template <>
void Hash<std::string>::Insert(std::string value)
{
    int index = (((5381 << 5) + 5381) + value.length()) % 8191;
    m_stringData[index].push_back(value);
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
inline void Hash<T>::ShowTypeData()
{
    for (int i = 0; i < m_typeData.size(); i++)
    {
        for (int j = 0; j < m_typeData[i].size(); j++)
        {
            if (m_typeData[i][j] != 0)
            {
                std::cout << "[" << i << "][" << j << "] : " << m_typeData[i][j] << std::endl;
            }
        }
    }
}

template <typename T>
void Hash<T>::ShowStringData()
{
    for (int i = 0; i < m_stringData.size(); i++)
    {
        for (int j = 0; j < m_stringData[i].size(); j++)
        {
            if (!m_stringData[i][j].empty())
            {
                std::cout << "[" << i << "][" << j << "] : " << m_stringData[i][j] << std::endl;
            }
        }
    }
}
