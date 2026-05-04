#include <iostream>
#include <cmath>

using namespace std;

int x[20], y[20];
bool visited[20];
int answer;
int n;

int get_dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void solve(int curr, int count, int dist) {
    // pruning the answer
    if (dist >= answer) return;

    if (count == n) {
        int final_dist = dist + get_dist(curr, n + 1);
        if (final_dist < answer) answer = final_dist;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            solve(i, count + 1, dist + get_dist(curr, i));
            visited[i] = false;
        }
    }
}

int main () {
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

    // amount of test cases
    for (int tc = 1; tc <= 3; ++tc) {
        cin >> n;
        cin >> x[0] >> y[0];
        cin >> x[n + 1] >> y[n + 1];
        for (int i = 1; i <= n; ++ i) {
            cin >> x[i] >> y[i];
            visited[i] = false;
        }
        answer = 1e9;
        solve(0,0,0);

        cout << "#" << tc << " " << answer << endl;
    }
}