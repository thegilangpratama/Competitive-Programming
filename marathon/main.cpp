#include <iostream>
#include <algorithm>
#include <cstring> // For memset

using namespace std;

int tc, D, H;
int memo[105][505];
const int INF = 1e9;

struct Pace {
    int energy;
    int time;
} pace[5];

int f(int D, int H) {
    if (H < 0) return INF;
    if (D == 0) return 0;
    if (memo[D][H] != -1) return memo[D][H];

    int result = INF;
    for (int i = 0; i < 5; i++) {
        result = min(result, f(D - 1, H - pace[i].energy) + pace[i].time);
    }

    return memo[D][H] = result;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

    if (!(cin >> tc)) return 0;

    for (int ntc = 1; ntc <= tc; ntc++) {
        cin >> D >> H;

        int minute, second, energy;
        for (int i = 0; i < 5; i++) {
            cin >> minute >> second >> energy;
            pace[i].energy = energy;
            pace[i].time = minute * 60 + second;
        }

        memset(memo, -1, sizeof(memo));

        int ans = f(D, H);

        if (ans >= INF) {
            cout << "#" << ntc << " " << -1 << endl;
        } else {
            cout << "#" << ntc << " " << ans / 60 << " " << ans % 60 << "\n";
        }
    }
    return 0;
}