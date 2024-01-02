#pragma once
#include <vector>
#include <iostream>
class Hash
{
public:
    Hash();
    ~Hash();

private:
    std::vector<std::vector<int>> m_data;

public:
    void Insert(int value);
    void Find(int key);
    void Erase(int key);
    void Show();
};

inline Hash::Hash()
{
    m_data.resize(8191);
}

inline Hash::~Hash()
{
}

void Hash::Insert(int value)
{
    int index = (((5381 << 5) + 5381) + value) % 8191;
    m_data[index].push_back(value);
}

inline void Hash::Find(int key)
{
}

inline void Hash::Erase(int key)
{
}

inline void Hash::Show()
{
    for (int i = 0; i < m_data.size(); i++)
    {
        for (int j = 0; j < m_data[i].size(); j++)
        {
            if (m_data[i][j] != 0)
            {
                std::cout << "[" << i << "][" << j << "] : " << m_data[i][j] << std::endl;
            }
        }
    }
}
