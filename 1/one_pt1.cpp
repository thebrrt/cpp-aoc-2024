#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

int main()
{
    std::cout << "Processing input file..." << std::endl;
    std::ifstream inputFile("input.txt");

    std::vector<int> IDs1, IDs2;
    int id1, id2;

    while (inputFile >> id1 >> id2)
    {
        IDs1.push_back(id1);
        IDs2.push_back(id2);
        std::cout << "NEW PAIR: [" << id1 << ", " << id2 << "]" << std::endl;
    }
    inputFile.close();

    std::sort(IDs1.begin(), IDs1.end());
    std::sort(IDs2.begin(), IDs2.end());

    int distance = 0;

    for (size_t i = 0; i < IDs1.size(); i++)
    {
        distance += std::abs(IDs1[i] - IDs2[i]);
        std::cout << "Distance at Index " << i << ": " << distance << std::endl;
    }

    std::cout << "Total distance: " << distance << std::endl;

    return 0;
}
