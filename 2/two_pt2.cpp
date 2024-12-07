#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

bool is_safe(const std::vector<int> &levels)
{
    if (levels.size() <= 1)
        return true;

    int direction = 0;

    for (size_t i = 0; i < levels.size() - 1; ++i)
    {
        int diff = levels[i + 1] - levels[i];
        if (std::abs(diff) < 1 || std::abs(diff) > 3)
        {
            return false;
        }
        if (diff == 0)
        {
            return false;
        }
        if (direction == 0)
        {
            direction = (diff > 0) ? 1 : -1;
        }
        else
        {
            if ((direction == 1 && diff < 0) || (direction == -1 && diff > 0))
            {
                return false;
            }
        }
    }
    return true;
}

bool is_safe_with_removal(const std::vector<int> &levels)
{
    if (is_safe(levels))
    {
        return true;
    }
    for (size_t i = 0; i < levels.size(); ++i)
    {
        std::vector<int> temp_levels = levels;
        temp_levels.erase(temp_levels.begin() + i);
        if (is_safe(temp_levels))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string line;
    int safe_reports = 0;
    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        int num;
        std::vector<int> levels;
        while (iss >> num)
        {
            levels.push_back(num);
        }
        if (is_safe_with_removal(levels))
        {
            ++safe_reports;
        }
    }
    std::cout << safe_reports << std::endl;
    return 0;
}