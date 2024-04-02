#pragma once

#include <string>
#include <map>

using namespace std;

class AdjacencyList {
    private:
    //Think about what member variables you need to initialize
    int numVertices;

    public:
    //Think about what helper functions you will need in the algorithm
    string PageRank(int n);
};

// This class and method are optional.
