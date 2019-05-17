/***********************************************************
 ** Author: Zach Reed
 ** Description: Bin-Packing Algorithms
 ***********************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

// First Fit Function *************************************
int firstFit (vector<int> items, int mBin) {
    int nItems = items.size();
    vector<int> bins;
    vector<int> binCount;
    
    for(int i = 0; i < items.size(); i++) {
        bins.push_back(mBin);
        binCount.push_back(0);
    }
    
    for(int i = 0; i < nItems; i++) {
        for(int j = 0; j < sizeof(bins); j++) {
            if (bins[j] - items[i] >= 0) {
                bins[j] -= items[i];
                binCount[j] += 1;
                break;
            }
        }
    }
    int nBin = 0;
    for (int k = 0; k < nItems; k++) {
        if (binCount[k] > 0){
            nBin = nBin + 1;
        }
    }
    return nBin;
}
// Best Fit Function ****************************************
int bestFit(vector<int> items, int mBin) {
    int nItems = items.size();
    int bins[nItems];
    int binsUsed = 0;
    
    for(int i = 0; i < nItems; i++) {
        int j;
        int min = mBin + 1;
        int binIdx = 0;
        
        for(j = 0; j < binsUsed; j++) {
            if(bins[j] >= items[i] && bins[j] - items[i] < min) {
                binIdx = j;
                min = bins[j] - items[i];
            }
        }
        if(min == mBin + 1) {
            bins[binsUsed] = nItems - items[i];
            binsUsed++;
        }
        else {
        bins[binIdx] -= items[i];
        }
    }
    return binsUsed;
}

int main() {
    int tests, mBin, nItems;
    ifstream inFile;
    inFile.open("bin.txt");
    
    if (!inFile.is_open()) {
        cout << "Could not open file" << endl;
    }
    
    else {
        inFile >> tests;
        for (int i = 0; i < tests; i++) {
            vector<int> items;
            vector<int> itemsFFD;
            vector<int> itemsFF;
            vector<int> itemsBF;
            inFile >> mBin;
            inFile >> nItems;
            int itemJ;
            
            for(int j = 0; j < nItems; j++) {
                inFile >> itemJ;
                items.push_back(itemJ);
            }
            
            itemsFFD = items;
            itemsFF = items;
            itemsBF = items;
            sort(itemsFFD.begin(), itemsFFD.end());
            reverse(itemsFFD.begin(), itemsFFD.end());
            
            int valFFD = firstFit(itemsFFD, mBin);
            int valFF = firstFit(itemsFF, mBin);
            int valBF = bestFit(itemsBF, mBin);
            
            cout << "Test Case " << i << " First Fit: " << valFF << ", First Fit Decreasing: " << valFFD << ", Best Fit: " << valBF << endl;
            
        }
        
    }
    return 0;
}
