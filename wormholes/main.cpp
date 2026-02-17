#include <iostream>

using namespace std;

const int MAX_N = 7;

int n, startX, startY, endX, endY;
int wsX[MAX_N], wsY[MAX_N];
int weX[MAX_N], weY[MAX_N];
int wTime[MAX_N];

bool visited[MAX_N];

int bestDistance;

inline int dist(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

void solve (int x, int y, int cost) {
    int est = cost + dist(x, y, endX, endY);
    if (est >= bestDistance) return;

    bestDistance = min(est, bestDistance);

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;

        visited[i] = true;

        int cost1 = cost
            + dist(x, y, wsX[i], wsY[i])
            + wTime[i];

        solve(weX[i], weY[i], cost1);

        int cost2 = cost
            + dist(x, y, weX[i], weY[i])
            + wTime[i];

        solve(wsX[i], wsY[i], cost2);

        visited[i] = false;

    }

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

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        cin >> n;
        cin >> startX >> startY >> endX >> endY;

        for (int i = 0; i < n; ++i) {
            cin >> wsX[i]
                >> wsY[i]
                >> weX[i]
                >> weY[i]
                >> wTime[i];
        }

        memset(visited, false, sizeof(visited));

        bestDistance = dist(startX, startY, endX, endY);

        solve(startX, startY, 0);

        cout << "#" << tc << " " << bestDistance << endl;
    }

    return 0;
}