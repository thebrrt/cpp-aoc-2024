#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

int main()
{
    std::ifstream infile("input.txt");

    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");

    auto matches_begin = std::sregex_iterator(content.begin(), content.end(), pattern);
    auto matches_end = std::sregex_iterator();

    int runningSum = 0;
    bool mulEnabled = true;
    std::cout << "Found matches:\n";
    for (std::sregex_iterator i = matches_begin; i != matches_end; ++i)
    {
        std::smatch match = *i;
        std::cout << match.str() << '\n';
        std::cout << "X = " << match[1] << ", Y = " << match[2] << '\n';
        if (mulEnabled)
        {
            runningSum += std::stoi(match[1]) * std::stoi(match[2]);
        }
    }

    std::cout << "Running sum: " << runningSum << std::endl;

    return 0;
}