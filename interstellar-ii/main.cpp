#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
bool visited[5];
long long w[5][5];
long long ex, ey;
long long min_total_time;

long long get_dist(int sx, int sy, int ex, int ey) {
    return abs(ex-sx) + abs(ey-sy);
}

void dfs (long long cx, long long cy, long long curr_time) {
    long long time_to_dest = curr_time + get_dist(cx, cy, ex, ey);
    min_total_time = min(min_total_time, time_to_dest);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;

            int ax = w[i][0], ay = w[i][1];
            int bx = w[i][2], by = w[i][3];
            int t = w[i][4];

            long long time_A = curr_time + get_dist(cx, cy, ax, ay) + t;
            dfs(bx, by, time_A);

            long long time_B = curr_time + get_dist(cx, cy, bx, by) + t;
            dfs(ax, ay, time_B);

            visited[i] = false;
        }
    }
}

void solve(int tc) {
    cin >> n;
    long long sx, sy;
    cin >> sx >> sy >> ex >> ey;

    for (int i = 0; i < n; ++i) {
        cin >> w[i][0] >> w[i][1] >> w[i][2] >> w[i][3] >> w[i][4];
        visited[i] = false;
    }

    min_total_time = get_dist(sx, sy, ex, ey);

    dfs(sx, sy, 0);

    cout << "#" << tc << " " << min_total_time << endl;
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

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve(i);
    }



    return 0;
}