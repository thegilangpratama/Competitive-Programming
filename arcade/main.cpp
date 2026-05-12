#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 12;
const int MAXM = 5;
int grid[MAXN][MAXM];
int n;
int maxGold;

bool isValid(int col) {
    return col >= 0 && col < MAXM;
}

void dfs(int row, int col, int gold, bool bombUsed) {
    if (row < 0) {
        maxGold = max(maxGold, gold);
        return;
    }
   
    if (!isValid(col)) {
        return;
    }
   
    int currentGold = gold;
    int cellValue = grid[row][col];
   
    if (cellValue == 1) {
        currentGold++;
    } else if (cellValue == 2) {
        currentGold--;
        if (currentGold < 0) {
            currentGold = -1; 
        }
    }
   
    if (currentGold >= 0) {
        for (int move = -1; move <= 1; move++) {
            int newCol = col + move;
            dfs(row - 1, newCol, currentGold, bombUsed);
        }
    }
   
    if (!bombUsed) {
        int originalValues[5][MAXM];
        int rowsAffected = min(5, row + 1);  
       
        for (int r = row; r > row - rowsAffected; r--) {
            for (int c = 0; c < MAXM; c++) {
                originalValues[row - r][c] = grid[r][c];
                if (grid[r][c] == 2) {
                    grid[r][c] = 0; 
                }
            }
        }
       
        int bombGold = gold;
        if (grid[row][col] == 1) {
            bombGold++;
        }
       
        for (int move = -1; move <= 1; move++) {
            int newCol = col + move;
            dfs(row - 1, newCol, bombGold, true);
        }
       
        for (int r = row; r > row - rowsAffected; r--) {
            for (int c = 0; c < MAXM; c++) {
                grid[r][c] = originalValues[row - r][c];
            }
        }
    }
}

void solve(int t) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < MAXM; ++j) {
            cin >> grid[i][j];
        }
    }
   
    maxGold = -1;
    int startCol = 2;
   
    for (int move = -1; move <= 1; move++) {
        int newCol = startCol + move;
        if (isValid(newCol)) {
            dfs(n - 1, newCol, 0, false);
        }
    }
   
    cout << "#" << t << " " << maxGold << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}
