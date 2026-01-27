#include <iostream>
#include <string> // Added for the 'string' type usage in main
using namespace std;

// Global variables to store input.
long a, b, c, k;

// ---------------------------------------------------------
// Find Log2
// ---------------------------------------------------------
long log2(long& n) {
    if (n <= 0) return -1;

    // __builtin_clzl counts "Leading Zeros" in the binary representation.
    // On a 64-bit system, a number has 64 bits.
    // Example: The number 8 is ...00001000 (roughly).
    // It has 60 leading zeros. 63 - 60 = 3. And 2^3 = 8.
    // This is much faster than using standard library std::log2.
    return 63 - __builtin_clzl(n);
}

long f(long& a, long& b, long& c, long& n) {
    // Calculates the value of the formula for a given n
    return a * n + b * n * log2(n) + c * (n * n * n);
}

long findN(long& a, long& b, long& c, long& k) {
    long high = 1, low = 1;

    // ---------------------------------------------------------
    // Exponential Search (Finding the Range)
    // ---------------------------------------------------------
    // We don't know how big 'n' is. It could be 10 or 1,000,000.
    // Instead of guessing, we double 'high' (1, 2, 4, 8...) until
    // f(high) exceeds our target k. This finds a valid range [low, high] quickly.
    while (f(a, b, c, high) < k) {
        low = high;
        high = high * 2;
    }

    // ---------------------------------------------------------
    // Binary Search (Finding the Exact Value)
    // ---------------------------------------------------------
    // Now that we know the answer is between 'low' and 'high',
    // we cut the range in half repeatedly to pin down the exact number.
    while (low <= high) {
        long mid = (low + high) / 2;
        long val = f(a, b, c, mid);

        if (val == k) return mid;      // Found it!
        if (val < k) low = mid + 1;    // Result too small? Look in the upper half
        else high = mid - 1;           // Result too big? Look in the lower half
    }

    return -1; // Should technically not reach here if a solution is guaranteed
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
        // Prints output in standard CP format: "#1 Answer", "#2 Answer", etc.
        cout << "#" << i << " " << findN(a, b, c, k) << endl;
    }
}