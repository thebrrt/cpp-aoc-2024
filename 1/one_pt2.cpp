#include <iostream>
#include <fstream>
#include <unordered_map>

int main()
{
    std::ifstream inputFile("input.txt");

    std::unordered_map<int, int> numberCounts;

    int id1, id2;

    while (inputFile >> id1 >> id2)
    {
        if (numberCounts.find(id1) == numberCounts.end())
        {
            numberCounts[id1] = 0;
        }
    }

    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    while (inputFile >> id1 >> id2)
    {
        if (numberCounts.find(id2) != numberCounts.end())
        {
            numberCounts[id2]++;
            std::cout << "New Counter for " << id2 << ": " << numberCounts[id2] << std::endl;
        }
    }
    inputFile.close();

    int totalScore = 0;

    std::cout << "Similarity Scores:" << std::endl;
    for (const auto &pair : numberCounts)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
        totalScore += pair.first * pair.second;
    }

    std::cout << "Total score: " << totalScore << std::endl;

    return 0;
}