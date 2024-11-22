#include <iostream>
#include <vector>
using namespace std;;

// Matrix (2D Grid)
int grid[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {0, 1, 0, 0}
};

// Adjacency matrix
int adjMatrix[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 1},
    {0, 1, 0, 0}
};
// an edge exists from v1 to v2
//adjMatrix[v1][v2] = 1;

// an edge exists from v2 to v1
//adjMatrix[v2][v1] = 1;

// No edge exists from v1 to v2
//adjMatrix[v1][v2] = 0;

// No edge exists from v2 to v1
//adjMatrix[v2][v1] = 0;

class GraphNode {
public:
    int val_;
    vector<int> neighbors_;

    GraphNode(int val) {
        val_ = val;
    }
};