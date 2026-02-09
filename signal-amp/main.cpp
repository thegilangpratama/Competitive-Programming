#include <iostream>
#include <unordered_map>

using namespace std;

void solve(int tc) {
    int n, m, k;
    cin >> n >> m >> k;

    bool grid[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    unordered_map<string, int> rowCnt;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int cntK = 0;
        string row = "";

        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 0)
                ++cntK;

            // Always push
            if (grid[i][j] == 0)
                row.push_back('0');
            else
                row.push_back('1');
        }

        // Check AFTER finishing row
        if (cntK <= k && (k - cntK) % 2 == 0) {
            rowCnt[row]++;
            ans = max(ans, rowCnt[row]);
        }
    }

    cout << "#" << tc << " " << ans << endl;
}

int main() {
    // Get folder path
    string path = __FILE__;
    path = path.substr(0, path.find_last_of("/\\"));

    // Redirect input
    freopen((path + "/sample.txt").c_str(), "r", stdin);

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        solve(i);
    }

    return 0;
}