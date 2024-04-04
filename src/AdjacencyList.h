#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <iomanip>
#include <sstream>

using namespace std;

class AdjacencyList {
    private: //Think about what member variables you need to initialize
    int numVertices;

    map<string, float> rankedPages;
    map<string, float> matrixMSums;
    map<string, set<pair<string, float>>> matrixM;

    map<string, int> frequencyMap;
    map<string, set<string>> edgesMap;

    public: //Think about what helper functions you will need in the algorithm

    AdjacencyList() {

    }

    void PrintEdges();
    void PrintFrequency();

    void GenerateGraphs(string from, string to);

    void CreateGraphM();
    
    string PageRank(int n);

    void CreateGraphR() {

        map<string, set<string>>::iterator iter1 = edgesMap.begin();

        while (iter1 != edgesMap.end()) {
            rankedPages[iter1->first] = (float)(1.00 / edgesMap.size());
            ++iter1;
        }

        // map<string, float>::iterator iter2 = rankedPages.begin();

	    // while (iter2 != rankedPages.end()) {
        //     cout << iter2->first << " " << iter2->second << "\n";
        //     ++iter2;
        // }

    }
    
};

// This class and method are optional.
