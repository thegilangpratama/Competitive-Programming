#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> balloon) {
    if (balloon.empty()) {
        return 0;
    }

    int best = 0;
    int gain = 0;
    int n = balloon.size();

    for (int i = 0; i < n; ++i) {

        if (i > 0 && i < n - 1 ) {
            gain = balloon[i-1] * balloon[i+1];
        } else if (i > 0) {
            gain = balloon[i-1];
        } else if (i < n - 1) {
            gain = balloon[i+1];
        } else {
            gain = balloon[i];
        }

        vector<int> next = balloon;
        next.erase(next.begin() + i);

        int total = gain + solve(next);
        best = max(total, best);
    }

    return best;
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

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) {
        int n;
        cin >> n;
        vector<int> balloon (n);
        for (int i = 0; i < n; ++i) {
            cin >> balloon[i];
        }

        cout << "#" << i << " " << solve(balloon) << endl;
    }

    return 0;
}