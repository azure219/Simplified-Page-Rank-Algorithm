#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include "AdjacencyList.h"

// g++ -std=c++14 main.cpp AdjacencyList.cpp && ./a.out

using namespace std;

void printMap(unordered_map<string, set<string>> sitesMap) {

    unordered_map<string, set<string>>::iterator iter1 = sitesMap.begin();

	while (iter1 != sitesMap.end()) {
        cout << "KEY: " << iter1->first << " VALUE: ";

        set<string>::iterator iter2 = iter1->second.begin();
   
        // Displaying set elements
        while (iter2 != iter1->second.end()) 
        {
            cout << *iter2 << " ";
            ++iter2;
        }
        cout << "\n";
        ++iter1;
    }

}

void printFrequency(unordered_map<string, int> map) {

    unordered_map<string, int>::iterator iter = map.begin();

	while (iter != map.end()) {
        cout << "KEY: " << iter->first << " VALUE: " << iter->second << "\n";
        ++iter;
    }

}

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    unordered_map<string, int> uniqueSitesMap;
    unordered_map<string, set<string>> uniqueSitesSet;
    cin >> no_of_lines;
    cin >> power_iterations;

    AdjacencyList graph;

    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        // Do Something
  	    uniqueSitesMap[from]++;
        uniqueSitesSet[to].insert(from);
        //graph.insertEdge(from, to);
    }

    // cout << "\n";
    // graph.printOut();
    // cout << "\n";
    // graph.printIn();
    cout << "\n";
    printFrequency(uniqueSitesMap);
    cout << "\n";
    printMap(uniqueSitesSet);
    cout << "\n";
    graph.print(uniqueSitesSet);

    //Create a graph object
    // Created_Graph.PageRank(power_iterations);}
}
