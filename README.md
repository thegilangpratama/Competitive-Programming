# Competitive Programming Solutions

A collection of competitive programming problem solutions and basic data structure implementations in C++.

## Project Structure

This project contains solutions to various algorithmic problems and implementations of fundamental data structures, organized as follows:

### Basic Data Structures (`basic/`)

- **graph.cpp** - Graph implementation and traversal algorithms
- **grid.cpp** - 2D grid/matrix operations
- **linked_list.cpp** - Linked list data structure
- **maps.cpp** - Hash map/dictionary operations

### Problem Solutions

- **burst-balloon/** - Burst Balloons problem solution
  - Dynamic programming approach to find maximum coins obtainable
- **is-bipartate/** - Bipartite Graph problem
  - Determines if a graph is bipartite using BFS coloring algorithm
- **wormholes/** - Wormholes problem
  - Path optimization using wormhole shortcuts
  - Manhattan distance calculations with teleportation
- **signal-amp/** - Signal Amplification problem
  - Signal processing and amplification algorithm
- **delivery-problem/** - Delivery Route Optimization
  - Route planning and optimization solution
- **infinite-numbers/** - Infinite Numbers problem
  - Number theory or sequence-based problem solution

- **blank/** - Template for new problem solutions

## Building the Project

This project uses CMake for building. All solutions are compiled as separate executables.

### Prerequisites

- C++14 compatible compiler
- CMake 4.1 or higher

### Build Instructions

```bash
# Create build directory
mkdir cmake-build-debug
cd cmake-build-debug

# Generate build files
cmake ..

# Build all executables
cmake --build .
```

### Running Solutions

After building, run individual problem solutions:

```bash
./Competitive_Programming    # Infinite numbers solution
./grid                       # Grid data structure demo
./graph                      # Graph data structure demo
./linked_list                # Linked list demo
./maps                       # Maps/hash table demo
./signal                     # Signal amplification
./bipartate                  # Bipartite graph checker
./balloon                    # Burst balloon problem
./delivery                   # Delivery optimization
./wormholes                  # Wormholes pathfinding
```

## Test Cases

Each problem directory includes a `case.txt` file containing sample test cases for that problem.

## Project Structure

```
.
├── CMakeLists.txt          # Build configuration
├── main.cpp                # Main entry point
├── README.md               # This file
├── basic/                  # Data structures
├── burst-balloon/          # Problem solutions
├── delivery-problem/
├── infinite-numbers/
├── is-bipartate/
├── signal-amp/
├── wormholes/
└── blank/                  # Template for new problems
```

## Technologies Used

- **Language:** C++14
- **Build System:** CMake
- **Data Structures:** Graphs, Linked Lists, Hash Maps, Grids
- **Algorithms:** BFS, DFS, Dynamic Programming, Graph Coloring

## Notes

- All solutions are implemented in C++ for competitive programming contexts
- Each solution is self-contained within its directory
- Test cases are provided in `case.txt` files where applicable
