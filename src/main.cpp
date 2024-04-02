#include <iostream>
#include <map>
#include "AdjacencyList.h"

// g++ -std=c++14 main.cpp AdjacencyList.cpp && ./a.out

using namespace std;

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    unordered_map<string, int> uniqueSitesMap;
    cin >> no_of_lines;
    cin >> power_iterations;
    
    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        // Do Something
  	    uniqueSitesMap[from]++;
    }

    // map<string, int>::iterator it = uniqueSitesMap.begin();
	// while (it != uniqueSitesMap.end()) {
    //     cout << "KEY: " << it->first << ", VALUE: " << it->second << endl;
    //     ++it;
    // }

    //Create a graph object
    // Created_Graph.PageRank(power_iterations);}
}
