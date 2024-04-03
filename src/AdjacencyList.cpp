#include <iostream>
#include "AdjacencyList.h"

using namespace std;

void AdjacencyList::CreateGraph(unordered_map<string, set<string>> sitesMap, unordered_map<string, int> frequencyMap) {

    unordered_map<string, set<string>>::iterator iter1 = sitesMap.begin();

	while (iter1 != sitesMap.end()) {
    
        set<string>::iterator iter2 = iter1->second.begin();
        float sum = 0.0;

        // Displaying set elements
        while (iter2 != iter1->second.end()) {

            sum += (float)(1.0 / frequencyMap.find(*iter2)->second);
            ++iter2;
        }
        
        matrixMSums[iter1->first] = sum;
        ++iter1;
    }

    // map<string, float>::iterator iter = matrixMSums.begin();

	// while (iter != matrixMSums.end()) {
    //     cout << "KEY: " << iter->first << " VALUE: " << iter->second << "\n";
    //     ++iter;
    // }

}

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    // optionally, store your output in a string/stringstream and then return it from this function after printing so that it is easier to test with Catch
    string result;

    // do your page rank
    for (int i = 1; i < n; i++) {

        map<string, float>::iterator iter1 = rankedPages.begin();

        while (iter1 != rankedPages.end()) {
            rankedPages[iter1->first] = iter1->second * matrixMSums.at(iter1->first);
            ++iter1;
        }

    }

    map<string, float>::iterator iter = rankedPages.begin();

        while (iter != rankedPages.end()) {
            
            float rankFloat = iter->second;
            stringstream stream;
            stream << fixed << setprecision(2) << rankFloat;
            string rankString = stream.str();

            result += (iter->first + " " + rankString + "\n");
            ++iter;
        }

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
