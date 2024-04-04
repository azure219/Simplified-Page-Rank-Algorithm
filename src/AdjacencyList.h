#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class AdjacencyList {

    private: // Think about what member variables you need to initialize

        int numVertices; // number of vertices

        map<string, set<pair<string, float>>> graphM; // graph M
        map<string, float> graphR; // graph r
        vector<string> empties;

        map<string, int> frequencyMap; // map that holds the frequency of websites (d)
        map<string, set<string>> edgesMap; // map that holds the edges of websites

    public: // Think about what helper functions you will need in the algorithm

        // constructor
        AdjacencyList() {}

        // parsing function for testing
        string ParseInput(string input);

        // print functions
        void PrintEdges();
        void PrintFrequency();

        // graph generation functions
        void GenerateGraphs(string from, string to);
        void CreateGraphM();
        void CreateGraphR();

        // rank algorithm function
        string PageRank(int n);

};