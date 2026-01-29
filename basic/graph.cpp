#include <iostream>
#include <list>
#include <map>

using namespace std;

class graph {
    private:
    map<int, list<int>> adj;

    public:
    void addVertex(int data) {
        if (adj.find(data) == adj.end()) {
            adj[data] = list<int>();
        }
    }

    void addEdge(int src, int dest) {
        addVertex(src);
        addVertex(dest);

        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    bool hasData(int data) {
        if (adj.find(data) != adj.end()) {
            return true;
        }
        return false;
    }

    void printGraph() {
        for (auto const& [vertex, neighbors] : adj) {
            cout << vertex << "->";
            for (int neighbor: neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

};

int main () {
    graph g;

    // adding vertex to graph
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    // adding edge to graph
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    // print graph
    g.printGraph();

    // find element
    int st = 2;
    cout << "is " << st << " present?" << endl;
    cout << (g.hasData(st) ? "Yes" : "No") << endl;



}