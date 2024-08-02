#include <iostream>
#include <vector>
#include <set>

using namespace std;

void drawFlightPaths(vector<vector<pair<int, int>>> &flights) {
    int maxX = 0, maxY = 0;
    for (const auto &flight : flights) {
        for (const auto &coord : flight) {
            if (coord.first > maxX) maxX = coord.first;
            if (coord.second > maxY) maxY = coord.second;
        }
    }

    vector<vector<char>> grid(maxX + 1, vector<char>(maxY + 1, '.'));

    char flightChar = 'A';
    for (const auto &flight : flights) {
        for (const auto &coord : flight) {
            if (grid[coord.first][coord.second] == '.') {
                grid[coord.first][coord.second] = flightChar;
            } else {
                grid[coord.first][coord.second] = 'X';
            }
        }
        flightChar++;
    }

    // Print the grid
    for (int i = 0; i <= maxX; ++i) {
        for (int j = 0; j <= maxY; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<pair<int, int>>> flights = {
        {{1, 1}, {2, 2}, {3, 3}}, // Flight 1
        {{1, 1}, {2, 4}, {3, 2}}, // Flight 2
        {{1, 1}, {4, 2}, {3, 4}}  // Flight 3
    };

    drawFlightPaths(flights);

    return 0;
}
