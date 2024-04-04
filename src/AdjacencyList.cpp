#include <iostream>
#include "AdjacencyList.h"

using namespace std;

void AdjacencyList::GenerateGraphs(string from, string to) {

    frequencyMap[from]++;
    edgesMap[to].insert(from);

}

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

void AdjacencyList::CreateGraphM() {

    map<string, set<string>>::iterator iter1 = edgesMap.begin();

	while (iter1 != edgesMap.end()) {

        set<string>::iterator iter2 = iter1->second.begin();
   
        while (iter2 != iter1->second.end()) {
            pair<string, float> tempPair(*iter2, 1.0 / frequencyMap.find(*iter2)->second);
            matrixM[iter1->first].insert(tempPair);
            ++iter2;
        }
        ++iter1;
    }

    // print instructions
    // map<string, set<pair<string, float>>>::iterator itr1 = matrixM.begin();

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

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    // optionally, store your output in a string/stringstream and then return it from this function after printing so that it is easier to test with Catch
    string result;
    map<string, float> tempRP;


    // do your page rank
    if (n > 1) {
        for (int i = 1; i < n; i++) {

            result = "";
            
            tempRP = rankedPages;

            map<string, set<pair<string, float>>>::iterator iteration1 = matrixM.begin();

            while (iteration1 != matrixM.end()) {
                set<pair<string, float>>::iterator iteration2 = iteration1->second.begin();
                float sum = 0.0;
                while (iteration2 != iteration1->second.end()) {
                    //cout << iteration1->first << "(" << iteration2->second << " * " << rankedPages[iteration2->first] << ")";
                    sum += (iteration2->second * rankedPages[iteration2->first]);
                    ++iteration2;
                }
                tempRP[iteration1->first] = sum;
                ++iteration1;
            }
            rankedPages = tempRP;

            
        }
    }
    // print
    map<string, float>::iterator iter = rankedPages.begin();

    while (iter != rankedPages.end()) {
            
        float rankFloat = iter->second;
        stringstream stream;
        stream << fixed << setprecision(2) << rankFloat;
        string rankString = stream.str();

        result += (iter->first + " " + rankString + "\n");
        ++iter; 
    }

    cout << result << endl;

    return result;
}
