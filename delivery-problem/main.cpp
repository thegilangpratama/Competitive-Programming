#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

const int MAX_N = 12;

int posX[MAX_N], posY[MAX_N];
int n;
int answer;

int dist(int from, int to) {
    return abs(posX[from] - posX[to]) + abs(posY[from] - posY[to]);
}

void solve(int current, bool visited[], int count, int cost) {
    if (cost >= answer) return;

    if (count == n) {
        answer = min(answer, cost + dist(current, n + 1));
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            solve(i, visited, count + 1, cost + dist(current, i));
            visited[i] = false;
        }
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

    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; ++i) {
        cin >> n;
        answer = INT_MAX;

        cin >> posX[n +1] >> posY[n +1];
        cin >> posX[0] >> posY[0];

        for (int i = 1; i <= n; ++i) {
            cin >> posX[i] >> posY[i];
        }

        bool visited[MAX_N] = {false};

        solve(0, visited, 0, 0);

        cout << "#" << i << " " << answer << endl;
    }

    return 0;
}