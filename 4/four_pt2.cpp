#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> grid;
    string line;
    ifstream infile("input.txt");

    if (!infile)
    {
        cerr << "Error: Cannot open input.txt" << endl;
        return 1;
    }

    while (getline(infile, line))
    {
        if (!line.empty())
            grid.push_back(line);
    }
    infile.close();

    int rows = grid.size();
    if (rows == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    int cols = grid[0].size();

    int count = 0;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (grid[y][x] == 'A')
            {
                bool dir1_valid = false;
                bool dir2_valid = false;

                if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < cols && y + 1 < rows)
                {
                    char c1 = grid[y - 1][x - 1];
                    char c2 = grid[y + 1][x + 1];
                    if ((c1 == 'M' && c2 == 'S') || (c1 == 'S' && c2 == 'M'))
                    {
                        dir1_valid = true;
                    }
                }

                if (x + 1 < cols && y - 1 >= 0 && x - 1 >= 0 && y + 1 < rows)
                {
                    char c1 = grid[y - 1][x + 1];
                    char c2 = grid[y + 1][x - 1];
                    if ((c1 == 'M' && c2 == 'S') || (c1 == 'S' && c2 == 'M'))
                    {
                        dir2_valid = true;
                    }
                }

                if (dir1_valid && dir2_valid)
                {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}