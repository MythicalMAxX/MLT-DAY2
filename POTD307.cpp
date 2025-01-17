#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPathsUtil(vector<vector<int>>& mat, int x, int y, int n, string path, vector<string>& paths, vector<vector<bool>>& visited) {
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    visited[x][y] = true;

    static int rowNum[] = { 1, 0, 0, -1 };
    static int colNum[] = { 0, -1, 1, 0 };
    static char move[] = { 'D', 'L', 'R', 'U' };

    for (int i = 0; i < 4; i++) {
        int next_x = x + rowNum[i];
        int next_y = y + colNum[i];

        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && mat[next_x][next_y] == 1 && !visited[next_x][next_y]) {
            findPathsUtil(mat, next_x, next_y, n, path + move[i], paths, visited);
        }
    }

    visited[x][y] = false;
}

vector<string> findPaths(vector<vector<int>>& mat, int n) {
    vector<string> paths;
    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) return paths;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    findPathsUtil(mat, 0, 0, n, "", paths, visited);
    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
    vector<vector<int>> mat1 = { {1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1} };
    vector<vector<int>> mat2 = { {1, 0},
                                 {1, 0} };

    vector<string> result1 = findPaths(mat1, 4);
    if (result1.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& path : result1) {
            cout << path << " ";
        }
        cout << endl;
    }

    vector<string> result2 = findPaths(mat2, 2);
    if (result2.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& path : result2) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
