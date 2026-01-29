#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

// map example
void mapSet() {
    map<int, string> m = {
        {1, "C++"},
        {2, "is"},
        {3, "Fun!"}
    };

    // will print second map only "C++ is Fun!"
    for (auto i : m) {
        cout << i.second << " ";
    }

    cout << endl;

    // will print full sets
    for (auto i : m) {
        cout << i.first << ": " << i.second << endl;
    }
}

// unordered map example
void unorderedMapSet () {
    unordered_map<int, string> um = {
        {1, "C++"},
        {2, "is"},
        {3, "Fun!"}
    };

    // will print second map unordered "C++ is Fun!"
    for (auto i : um) {
        cout << i.second << " ";
    }

    cout << endl;

    // will print full sets unordered
    for (auto i : um) {
        cout << i.first << ": " << i.second << endl;
    }
}

int main () {
    mapSet();
    cout << endl;
    unorderedMapSet();
    return 0;
}