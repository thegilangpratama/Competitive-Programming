#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 11;
const int INF = 1e9;

int n, m;

bool graph[MAXN][MAXN];
bool visited[MAXN];

vector<int> path;
vector<int> bestCycle;

int minSum;


void dfs(int node) {

    if (visited[node]) {

        int sum = 0;
        vector<int> cycle;

        for (int i = path.size() - 1; i >= 0; i--) {

            sum += path[i];
            cycle.push_back(path[i]);

            if (path[i] == node)
                break;
        }

        if (sum < minSum) {
            minSum = sum;
            bestCycle = cycle;
        }

        return;
    }

    visited[node] = true;
    path.push_back(node);

    for (int next = 1; next <= n; next++) {
        if (graph[node][next]) {
            dfs(next);
        }
    }

    path.pop_back();
    visited[node] = false;
}


int main() {

    // ---------------------------------------------------------
    // Automated Input test case
    // ---------------------------------------------------------

    // Get folder of this source file
    string filePath = __FILE__;
    filePath = filePath.substr(0, filePath.find_last_of("/\\"));

    // Open input file
    if (!freopen((filePath + "/case.txt").c_str(), "r", stdin)) {
        cout << "Failed to open case.txt\n";
        return 0;
    }

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {

        cin >> n >> m;

        // Reset for each test case
        memset(graph, 0, sizeof(graph));
        memset(visited, false, sizeof(visited));

        minSum = INF;
        bestCycle.clear();
        path.clear();

        // Read edges
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a][b] = true;
        }

        // Run DFS from every node
        for (int i = 1; i <= n; ++i) {
            dfs(i);
        }

        // Sort answer
        sort(bestCycle.begin(), bestCycle.end());

        // Print result
        cout << "#" << tc << " ";

        if (bestCycle.empty()) {
            cout << "-1";
        } else {
            for (int x : bestCycle) {
                cout << x << " ";
            }
        }

        cout << endl;
    }

    return 0;
}