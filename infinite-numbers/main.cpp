#include <iostream>

using namespace std;

long a, b, c, k;

long log2(long& n) {
    if (n <= 0) return -1;
    return 63 - __builtin_clzl(n);
}

long f(long& a, long& b, long& c, long& n) {
    return a * n + b * n * log2(n) + c * (n * n * n);
}

long findN(long& a, long& b, long& c, long& k) {
    long high = 1, low = 1;

    while (f(a, b, c, high) < k) {
        low = high;
        high = high * 2;
    }

    while (low <= high) {
        long mid = (low + high) / 2;
        long val = f(a, b, c, mid);

        if (val == k) return mid;
        if (val < k) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
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
    freopen((path + "/sample.txt").c_str(), "r", stdin);

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) {
        cin >> a >> b >> c >> k;

        cout << "#" << i << " " << findN(a, b, c, k) << endl;
    }
}

// Expeted result
// #1 23001
// #2 1234567890
// #3 2
// #4 100
// #5 500
// #6 1000
// #7 42
// #8 999999
// #9 23000
// #10 987654321
// #11 777
// #12 1000000000
// #13 500000
// #14 3
// #15 1111111111