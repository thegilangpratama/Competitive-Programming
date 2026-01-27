#include <iostream>
// Include algorithm for __builtin_clzll if not on GCC/Clang,
// but usually <iostream> is enough in CP environments.
using namespace std;

// 1. Use long long for everything
long long a, b, c, k;

long long log2(long long n) {
    if (n <= 0) return -1;
    // 2. Use __builtin_clzll (note the 'll' at the end)
    // 63 is correct for 64-bit integers (0 to 63 indices)
    return 63 - __builtin_clzll(n);
}

long long f(long long a, long long b, long long c, long long n) {
    return a * n + b * n * log2(n) + c * (n * n * n);
}

long long findN(long long a, long long b, long long c, long long k) {
    long long high = 1, low = 1;

    // Check upper bound expansion
    while (f(a, b, c, high) < k) {
        low = high;
        high *= 2;
    }

    // Binary Search
    while (low <= high) {
        long long mid = low + (high - low) / 2; // Prevent overflow in addition
        long long val = f(a, b, c, mid);

        if (val == k) return mid;
        if (val < k) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}

int main() {
    // 1. Get the path of the current main.cpp file
    string path = __FILE__;

    // 2. Strip the file name to get the directory
    path = path.substr(0, path.find_last_of("/\\"));

    // 3. Open sample.txt in that specific directory
    freopen((path + "/sample.txt").c_str(), "r", stdin);

    int tc;
    if (cin >> tc) {
        for (int i = 1; i <= tc; i++) {
            cin >> a >> b >> c >> k;
            cout << "#" << i << " " << findN(a, b, c, k) << endl;
        }
    }
    return 0;
}