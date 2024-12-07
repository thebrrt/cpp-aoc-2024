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

    string word = "XMAS";
    int word_length = word.length();

    // Directions: N, NE, E, SE, S, SW, W, NW
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    int count = 0;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int k;
                for (k = 0; k < word_length; k++)
                {
                    int nx = x + dx[dir] * k;
                    int ny = y + dy[dir] * k;
                    if (nx < 0 || nx >= cols || ny < 0 || ny >= rows)
                        break;
                    if (grid[ny][nx] != word[k])
                        break;
                }
                if (k == word_length)
                    count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}