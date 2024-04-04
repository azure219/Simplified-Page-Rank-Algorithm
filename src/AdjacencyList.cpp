#include <iostream>
#include "AdjacencyList.h"

using namespace std;

// functions to print frequencyMap and edgesMap
void AdjacencyList::PrintEdges() {

    map<string, set<string>>::iterator iter1 = edgesMap.begin();

	while (iter1 != edgesMap.end()) {
        cout << "KEY: " << iter1->first << " | VALUE: ";

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
void AdjacencyList::PrintFrequency() {

    map<string, int>::iterator iter = frequencyMap.begin();

	while (iter != frequencyMap.end()) {
        cout << "KEY: " << iter->first << " | VALUE: " << iter->second << "\n";
        ++iter;
    }

}

// generates 'frequencyMap' and 'edgesMap' by appropriately inserting in passed strings 'from' and 'to'
void AdjacencyList::GenerateGraphs(string from, string to) {

    frequencyMap[from]++;
    edgesMap[to].insert(from);
    numVertices = frequencyMap.size(); // 'numVertices' updates as the size of 'frequencyMap' increases

}

// generates 'graphM'
void AdjacencyList::CreateGraphM() {

    // iterator to run through 'edgesMap'
    map<string, set<string>>::iterator iter1 = edgesMap.begin();

	while (iter1 != edgesMap.end()) {

        // iterator to run through the set of websites in each iteration of 'edgesMap'
        set<string>::iterator iter2 = iter1->second.begin();
   
        while (iter2 != iter1->second.end()) {

            // creates a temporary pair of the current website and it's rank (1.0 / d)
            pair<string, float> tempPair(*iter2, 1.0 / frequencyMap.find(*iter2)->second);

            // stores temporary pair in graphM with appropriate website key
            graphM[iter1->first].insert(tempPair);
            ++iter2;
        }

        ++iter1;
    }

    // to print: 
    // map<string, set<pair<string, float>>>::iterator itr1 = graphM.begin();
	// while (itr1 != matrixM.end()) {
    //     cout << "KEY: " << itr1->first << " | VALUE: ";
    //     set<pair<string, float>>::iterator itr2 = itr1->second.begin();
    //     // Displaying set elements
    //     while (itr2 != itr1->second.end()) {
    //         cout << "(" << itr2->first << ", " << to_string(itr2->second) << ") ";
    //         ++itr2;
    //     }
    //     cout << "\n";
    //     ++itr1;
    // }

}

// generates 'graphR'
void AdjacencyList::CreateGraphR() {

        map<string, set<string>>::iterator iter1 = edgesMap.begin();

        while (iter1 != edgesMap.end()) {

            graphR[iter1->first] = (float)(1.00 / edgesMap.size());
            ++iter1;

        }

        // to print
        // map<string, float>::iterator iter2 = graphR.begin();
	    // while (iter2 != graphR.end()) {
        //     cout << iter2->first << " " << iter2->second << "\n";
        //     ++iter2;
        // }

    }

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n) {

    string result;
    map<string, float> tempRP; // temporary 'graphR' graph

    // do your page rank
    if (n > 1) {
        for (int i = 1; i < n; i++) {

            result = "";
            tempRP = graphR;

            map<string, set<pair<string, float>>>::iterator iteration1 = graphM.begin();

            while (iteration1 != graphM.end()) {

                set<pair<string, float>>::iterator iteration2 = iteration1->second.begin();
                float sum = 0.0;
                
                while (iteration2 != iteration1->second.end()) {

                    //cout << iteration1->first << "(" << iteration2->second << " * " << rankedPages[iteration2->first] << ")";
                    
                    sum += (iteration2->second * graphR[iteration2->first]); 
                    ++iteration2;

                }

                tempRP[iteration1->first] = sum;
                ++iteration1;
            }

            graphR = tempRP;
        }
    }

    // to print
    map<string, float>::iterator iter = graphR.begin();

    // generates string 'result'
    while (iter != graphR.end()) {
            
        float rankFloat = iter->second;
        stringstream stream;
        stream << fixed << setprecision(2) << rankFloat;
        string rankString = stream.str();

        result += (iter->first + " " + rankString + "\n");
        ++iter; 
    }

    cout << "\n" << result << endl;

    return result;
}
