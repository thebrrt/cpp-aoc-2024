#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream file("input.txt");
    std::string line;

    int sum = 0;
    int total = 0;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::vector<int> row;
        int number;
        bool isFirst = true;
        bool isSecond = true;
        bool trendPositive;
        int oldValue;
        int isValid = true;
        while (iss >> number)
        {
            row.push_back(number);

            std::cout << number << " ";

            if (isFirst)
            {
                isFirst = false;
                oldValue = number;
                continue;
            }

            int delta = std::abs(oldValue - number);
            if (delta < 1 || delta > 3)
            {
                std::cout << "INVALID DELTA DIFF";
                isValid = false;
                break;
            }

            if (isSecond)
            {
                isSecond = false;
                trendPositive = oldValue < number;
                oldValue = number;
                continue;
            }

            bool deltaPositive = oldValue < number;
            if (trendPositive != deltaPositive)
            {
                std::cout << "INVALID TREND";
                isValid = false;
                break;
            }

            oldValue = number;
        }

        std::cout << std::endl;
        if (isValid)
        {
            sum++;
        }
        total++;
    }
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Total: " << total << std::endl;

    file.close();

    return 0;
}
