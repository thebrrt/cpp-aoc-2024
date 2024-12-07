#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main()
{
    std::ifstream infile("input.txt");
    if (!infile)
    {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

    std::regex pattern(R"((mul\((\d{1,3}),(\d{1,3})\))|(do\(\))|(don't\(\)))");

    auto matches_begin = std::sregex_iterator(content.begin(), content.end(), pattern);
    auto matches_end = std::sregex_iterator();

    bool mul_enabled = true;

    int running_sum = 0;
    std::cout << "Processing instructions:\n";
    for (std::sregex_iterator i = matches_begin; i != matches_end; ++i)
    {
        std::smatch match = *i;

        if (match[1].matched)
        {
            if (mul_enabled)
            {
                std::string mul_instruction = match[1];
                std::string X = match[2];
                std::string Y = match[3];
                std::cout << "Processing " << mul_instruction << ": X = " << X << ", Y = " << Y << '\n';
                running_sum += std::stoi(X) * std::stoi(Y);
            }
            else
            {
                std::cout << "Skipping " << match[1] << " (mul instructions are disabled)\n";
            }
        }
        else if (match[4].matched)
        {
            mul_enabled = true;
            std::cout << "do() encountered: mul instructions enabled.\n";
        }
        else if (match[5].matched)
        {
            mul_enabled = false;
            std::cout << "don't() encountered: mul instructions disabled.\n";
        }
    }
    std::cout << "Final running sum: " << running_sum << std::endl;

    return 0;
}