#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class AdjacencyList {
    private:
    //Think about what member variables you need to initialize
    int numVertices;

    map<string, float> rankedPages;

    public:
    //Think about what helper functions you will need in the algorithm

    unordered_map<string, unsigned int> outDegreeGraph;  // Store the out_degree connection (from -> to)
    unordered_map<string, vector<string>> inDegreeGraph;  // Store the in_degree connection (to -> from (out_degree)
    void printOut();
    void printIn();
    void insertEdge(string &from, string &to);

    AdjacencyList() {

    }

    string PageRank(int n);

    void print(unordered_map<string, set<string>> mapUO) {

        for (auto &node : mapUO) {
            rankedPages[node.first] = (float)(1.0 / mapUO.size());
        }

        map<string, float>::iterator iter2 = rankedPages.begin();

	    while (iter2 != rankedPages.end()) {
            cout << iter2->first << " " << iter2->second << "\n";
            ++iter2;
        }

    }
    
};

// This class and method are optional.
