// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // matric with no of col and row
    int n = 3, m = 4;
    vector<vector<int>> matrix(n, vector<int>(m));

    // matrix with val
    vector<vector<long>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // input matrix based on col and row size
    cout << "Input Matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // output matrix based on col and row size
    cout << endl;
    cout << "Matrix Value: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // output of matrix based on vector of vector grid value
    cout << endl;
    cout << "Grid Value: " << endl;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}