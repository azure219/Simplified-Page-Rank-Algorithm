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
    private:
    //Think about what member variables you need to initialize
    int numVertices;

    map<string, float> rankedPages;
    map<string, float> matrixMSums;

    public:
    //Think about what helper functions you will need in the algorithm

    unordered_map<string, unsigned int> outDegreeGraph;  // Store the out_degree connection (from -> to)
    unordered_map<string, vector<string>> inDegreeGraph;  // Store the in_degree connection (to -> from (out_degree)
    void printOut();
    void printIn();
    void insertEdge(string &from, string &to);

    AdjacencyList() {

    }

    void CreateGraph(unordered_map<string, set<string>> sitesMap, unordered_map<string, int> frequencyMap);
    
    string PageRank(int n);

    void CreateR(unordered_map<string, set<string>> mapUO) {

        unordered_map<string, set<string>>::iterator iter1 = mapUO.begin();

        while (iter1 != mapUO.end()) {
            rankedPages[iter1->first] = (float)(1.00 / mapUO.size());
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
