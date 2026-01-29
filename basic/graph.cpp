#include <iostream>
#include <list>
#include <map> // Using 'map' instead of 'unordered_map' keeps keys sorted

using namespace std;

class graph {
    private:
    // Adjacency List Representation
    // Key (int): The vertex data.
    // Value (list<int>): A linked list of all vertices connected to this key.
    // Note: std::map is implemented as a Tree (usually Red-Black Tree),
    // so keys are stored in sorted order.
    map<int, list<int>> adj;

    public:
    // Function to register a new vertex in the graph
    // Time Complexity: O(log V) due to map insertion
    void addVertex(int data) {
        // .find() checks if the key exists. returns .end() if not found.
        // We only create a new list if the vertex is NOT already present.
        if (adj.find(data) == adj.end()) {
            adj[data] = list<int>();
        }
    }

    // Function to create a connection between two vertices
    // Time Complexity: O(log V) to find vertices + O(1) to push to list
    void addEdge(int src, int dest) {
        // Ensure both vertices exist before connecting them
        addVertex(src);
        addVertex(dest);

        // Add edge logic for an Undirected Graph
        // Connection goes both ways: src -> dest AND dest -> src
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    // Search function to check existence
    // Time Complexity: O(log V) because std::map uses binary search tree logic
    bool hasData(int data) {
        // If iterator is not at the end, the element was found
        if (adj.find(data) != adj.end()) {
            return true;
        }
        return false;
    }

    // Visualizes the graph structure
    // Time Complexity: O(V + E) - Visits every vertex and every edge
    void printGraph() {
        // uses C++17 "Structured Binding" to unpack the map pair
        // 'vertex' gets the key, 'neighbors' gets the value (the list)
        for (auto const& [vertex, neighbors] : adj) {
            cout << vertex << "->";
            // Iterate through the linked list of neighbors
            for (int neighbor: neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

};

int main () {
    graph g;

    // 1. Build the Graph
    // Vertices will be stored internally as: 0, 1, 2, 3 (sorted)
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    // 2. Define Relationships
    // Note: Order of adding edges doesn't affect the map's key sorting,
    // but it determines the order inside the neighbor lists.
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    // 3. Output
    // Because we used std::map, this will print in order: 0, 1, 2, 3
    cout << "Graph Adjacency List:" << endl;
    g.printGraph();

    // 4. Test Search Functionality
    int st = 2;
    cout << "\nIs " << st << " present?" << endl;
    // Ternary operator for cleaner output: (condition ? if_true : if_false)
    cout << (g.hasData(st) ? "Yes" : "No") << endl;

    return 0;
}