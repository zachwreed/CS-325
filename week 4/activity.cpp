/************************************
 ** Author: Zach Reed
 ** Description: Greed Sort Algorithm
 ************************************/

#include <iostream>
#include <vector>
 #include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("act.txt");
    int numAct = 0;
    int a, s, f;
    int set = 1;
    
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            vector<pair<int, pair<int, int>>> act;
            vector<int> actSel;
            inFile >> numAct;
            for (int i = 0; i < numAct; i++) {
                inFile >> a;
                inFile >> s;
                inFile >> f;
                act.push_back(make_pair(f, make_pair(s, a))); // act[f][s][a]
            }
            sort(act.begin(), act.end());
            
            actSel.push_back(act[0].second.second);
            int end = 0;
            for(int i = 1; i < numAct; i++) {
                if (act[i].second.first >= act[end].first) { // if start of [i] > finish [i - 1]
                    actSel.push_back(act[i].second.second);
                    end = i;
                }
            }
            
            cout << "Set: " << set << endl;
            set++;
            cout << "Number of activities selected: " << numAct << endl;
            cout << "Activities: ";
            for (size_t i = 0; i < actSel.size(); i++) {
                cout << actSel[i] << " ";
            }
            cout << endl;
        }
        inFile.close();
    }
    
    return 0;
}

