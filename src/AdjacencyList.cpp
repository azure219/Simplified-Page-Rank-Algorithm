#include <iostream>
#include "AdjacencyList.h"

using namespace std;

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    // optionally, store your output in a string/stringstream and then return it from this function after printing so that it is easier to test with Catch
    string result;

    // do your page rank

    cout << result;
    return result;
}

void AdjacencyList::insertEdge(string &from, string &to) {
        // Push value into the graph
        outDegreeGraph[from] += 1;  // From -> to (out_degree of from)
        inDegreeGraph[to].push_back(from);  // To -> from (in_degree of from)

        // Add (from) key with empty value into the graph if it is not there
        if (outDegreeGraph.find(to) == outDegreeGraph.end()) outDegreeGraph[to] = 0;

        // Add (to) key with empty value into the graph if it is not there
        if (inDegreeGraph.find(from) == inDegreeGraph.end()) inDegreeGraph[from] = {};
}

void AdjacencyList::printOut() {

    unordered_map<string, unsigned int>::iterator it = outDegreeGraph.begin();

	while (it != outDegreeGraph.end()) {
        cout << "KEY: " << it->first << " VALUE: " << it->second << "\n";
        ++it;
    }

}

void AdjacencyList::printIn() {

    unordered_map<string, vector<string>>::iterator it = inDegreeGraph.begin();

	while (it != inDegreeGraph.end()) {
        cout << "KEY: " << it->first << " VALUE: ";

        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second.at(i) << ", ";
        } 

        cout << "\n";

        ++it;
    }

}
