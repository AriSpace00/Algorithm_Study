#include "Hash.h"
#include "Timer.h"

#include <fstream>
#include <functional>
#include <unordered_map>

int main()
{
    std::cout << "<My Hash>" << std::endl;
    Hash<std::string> myHash1;

    std::string word;
    std::string wordPath = "../Resource/english3.txt";
    std::fstream file;
    file.open(wordPath.c_str());

    Timer timer;
    timer.Start();

    while(file >> word)
    {
        myHash1.Insert(word);
    }

    timer.End();
    file.clear();
    file.seekg(0, std::ios::beg);
    timer.GetElapsedTime();
    myHash1.ShowInfo();

    std::cout << "--------------------------------" << std::endl;

    std::cout << "<std::hash>" << std::endl;
    std::hash<std::string> stdHash;
    std::unordered_map<int, std::string> stdHashMap;

    timer.Start();

    while (file >> word)
    {
        int key = stdHash(word);
        stdHashMap.insert(make_pair(key, word));
    }

    timer.End();
    file.clear();
    file.seekg(0, std::ios::beg);
    timer.GetElapsedTime();

    std::cout << "--------------------------------" << std::endl;

    std::cout << "<My Hash2>" << std::endl;
    Hash<double> myHash2;

    double doubleDummy;
    std::string doublePath = "../Resource/doubleTest.txt";
    file.open(wordPath.c_str());

    timer.Start();
    while (file >> doubleDummy)
    {
        myHash2.Insert(doubleDummy);
    }

    timer.End();
    file.clear();
    file.seekg(0, std::ios::beg);
    timer.GetElapsedTime();
    myHash2.ShowInfo();

    return 0;
}
