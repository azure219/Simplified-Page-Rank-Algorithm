#include <iostream>
#include "AdjacencyList.h"

// g++ -std=c++14 main.cpp AdjacencyList.cpp && ./a.out

using namespace std;

int main() {

    AdjacencyList graph;

    int no_of_lines, power_iterations;
    string from, to;

    cin >> no_of_lines;
    cin >> power_iterations;

    for (int i = 0; i < no_of_lines; i++) {

        cin >> from;
        cin >> to;
  	    graph.GenerateGraphs(from, to);

    }

    // cout << "\n";
    // graph.PrintFrequency(); // printOut
    // cout << "\n";
    // graph.PrintEdges(); // printIn

    graph.CreateGraphR();
    graph.CreateGraphM();
    graph.PageRank(power_iterations);

}