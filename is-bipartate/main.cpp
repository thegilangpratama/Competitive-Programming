#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(int start, vector<vector<int>>& graph, vector<int>& color) {
    queue<int> q;

    q.push(start);
    color[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (color[next] == -1) {
                color[next] = 1 - color[cur];
                q.push(next);
            }
            else if (color[next] == color[cur]) {
                return false;
            }
        }
    }

    return true;
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (!isBipartite(i, graph, color)) {
                cout << "#" << tc << " -1\n";
                return;
            }
        }
    }

    vector<int> blacks;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 1) {
            blacks.push_back(i);
        }
    }

    cout << "#" << tc << " " << blacks.size() << ": ";

    for (int x : blacks) {
        cout << x << " ";
    }

    cout << "\n";
}

int main() {
    // ---------------------------------------------------------
    // Automated Input test case
    // ---------------------------------------------------------
    // __FILE__ is a compiler macro that holds the full path of your source code.
    // e.g., "/Users/gilangpratama/Project/.../main.cpp"
    string path = __FILE__;

    // This strips off the filename "/main.cpp" to get just the folder path.
    path = path.substr(0, path.find_last_of("/\\"));

    // We build the full path to sample.txt so the program never gets lost.
    freopen((path + "/case.txt").c_str(), "r", stdin);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        solve(i);
    }

    return 0;
}