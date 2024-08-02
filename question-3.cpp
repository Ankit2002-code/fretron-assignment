#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int BOARD_SIZE = 9;

vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));
vector<vector<string>> paths;

void printBoard() {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "S " : ". ");
        }
        cout << endl;
    }
}

bool isValidMove(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

void findPaths(int x, int y, int startX, int startY, vector<string>& path, int killed) {
    if (x == startX && y == startY && killed > 0) {
        paths.push_back(path);
        return;
    }

    for (int ny = y + 1; ny < BOARD_SIZE; ++ny) {
        if (board[x][ny] == 1) {
            board[x][ny] = 0;
            path.push_back("Kill (" + to_string(x + 1) + "," + to_string(ny + 1) + "). Turn Left");
            findPaths(x, ny, startX, startY, path, killed + 1);
            path.pop_back();
            board[x][ny] = 1;
        } else if (ny == BOARD_SIZE - 1) {
            path.push_back("Jump to (" + to_string(x + 1) + "," + to_string(ny + 1) + ")");
            findPaths(x, ny, startX, startY, path, killed);
            path.pop_back();
        }
    }

    for (int nx = x - 1; nx >= 0; --nx) {
        if (board[nx][y] == 1) {
            board[nx][y] = 0;
            path.push_back("Kill (" + to_string(nx + 1) + "," + to_string(y + 1) + "). Turn Left");
            findPaths(nx, y, startX, startY, path, killed + 1);
            path.pop_back();
            board[nx][y] = 1;
        } else if (nx == 0) {
            path.push_back("Jump to (" + to_string(nx + 1) + "," + to_string(y + 1) + ")");
            findPaths(nx, y, startX, startY, path, killed);
            path.pop_back();
        }
    }
}

int main() {
    int soldiers = 11;
    cout << "find_my_home_castle –soldiers " << soldiers << endl;

    for (int i = 0; i < soldiers; ++i) {
        int x, y;
        cout << "Enter coordinates for soldier " << i + 1 << ": ";
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }

    cout << "Fretron LLP" << endl;
    cout << "http://www.fretron.com" << endl;

    int startX, startY;
    cout << "Enter the coordinates for your \"special\" castle: ";
    cin >> startX >> startY;
    startX--; startY--;

    vector<string> initialPath = {"Start (" + to_string(startX + 1) + "," + to_string(startY + 1) + ")"};
    findPaths(startX, startY, startX, startY, initialPath, 0);

    cout << "Thanks. There are " << paths.size() << " unique paths for your 'special_castle'" << endl;

    for (size_t i = 0; i < paths.size(); ++i) {
        cout << "\nPath " << i + 1 << ":" << endl;
        cout << "=======" << endl;
        for (const string& step : paths[i]) {
            cout << step << endl;
        }
        cout << "Arrive (" << startX + 1 << "," << startY + 1 << ")" << endl;
    }

    return 0;
}
