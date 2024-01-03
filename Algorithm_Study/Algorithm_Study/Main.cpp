#include "Hash.h"

#include <fstream>

int main()
{
    std::cout << "english3.txt" << std::endl;

    Hash<std::string> stringHash;
    std::fstream file;
    std::string word;
    std::string filePath = "../Resource/english3.txt";
    file.open(filePath.c_str());
    while(file >> word)
    {
        stringHash.Insert(word);
    }

    stringHash.ShowStringData();

    /*std::cout << "int" << std::endl;
    Hash<int> hash1;
    hash1.Insert(1);
    hash1.Insert(2);
    hash1.Insert(3);
    hash1.Insert(4);
    hash1.Insert(5);
    hash1.Insert(6);
    hash1.ShowTypeData();

    std::cout << std::endl;

    std::cout << "char" << std::endl;
    Hash<char> hash2;
    hash2.Insert('a');
    hash2.Insert('b');
    hash2.Insert('c');
    hash2.Insert('d');
    hash2.Insert('e');
    hash2.Insert('f');
    hash2.ShowTypeData();

    std::cout << std::endl;

    std::cout << "float" << std::endl;
    Hash<float> hash3;
    hash3.Insert(1.1f);
    hash3.Insert(2.1f);
    hash3.Insert(3.1f);
    hash3.Insert(4.1f);
    hash3.Insert(5.1f);
    hash3.Insert(6.1f);
    hash3.ShowTypeData();*/
}
