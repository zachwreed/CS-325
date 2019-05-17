/************************************
** Author: Zach Reed
** Description: Wrestler Algorithm
************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char * args[]) {
	ifstream inFile(args[1]);
	int w, r;
	vector<string> rivTemp;
	vector<pair<string, string>> rivalries;
	vector<pair<string, pair<string, int>>> wrestlers;
	string sTemp = " ";
	string sTemp2;
	if (!inFile.is_open()) {
		cout << "Could not open file" << endl;
	}

	else {
		inFile >> w;
		getline(inFile, sTemp);
		for (int i = 0; i < w; i++) {
			getline(inFile, sTemp);
			wrestlers.push_back(make_pair(sTemp, make_pair("BabyFace", 0)));
		}

		inFile >> r;
		getline(inFile, sTemp);
		for (int j = 0; j < r; j++) {	
			// get line from file
			getline(inFile, sTemp);
			int i = -1;
			for (int k = 0; k < 2; k++) {
				vector<char> cTemp;
				i++;
				// break char array when space is found
				while (sTemp.at(i) != ' ' ) {
					cTemp.push_back(sTemp.at(i));

					size_t x = i;
					if (x == sTemp.size() - 1)
					{
						break;
					}
					i++;
				 }
				// convert char aray to string and push to temporary vector
				string str(cTemp.begin(), cTemp.end());
				rivTemp.push_back(str);	
			}
		}
		int k = 1;
		for (int i = 1; i <= r; i++) {
			rivalries.push_back(make_pair(rivTemp[k -1], rivTemp[k]));
			k = k + 2;
		}

		// begin sorting
		for (int i = 0; i < w; i++) {
			
			for (int j = 0; j < r; j++) {

				// If werestler matches first in rivalry
				if (wrestlers[i].first == rivalries[j].first || wrestlers[i].first == rivalries[j].second) {
					// get index of rival in wrestler vector
					int k = 0;
					// if wrestler[i] == first rival, get index of second rival
					if (wrestlers[i].first == rivalries[j].first) {
						while (1) {
							if (rivalries[j].second == wrestlers[k].first) {
								break;
							}
							if (k == w - 1) {
								break;
							}
							k++;
						}
					}
					// if wrestler[i] == second rival, get index of first rival
					if (wrestlers[i].first == rivalries[j].second)
					while (1) {
						if (rivalries[j].first == wrestlers[k].first) {
							break;
						}
						if (k == w - 1) {
							break;
						}
						k++;
					}

					// two compares are not same type
					if (wrestlers[i].second.first != wrestlers[k].second.first) {
						continue;
					}

					// if compares are same type 
					else {
						// second hasnt been swapped more than once
						if (wrestlers[k].second.second < 1) {
							if (wrestlers[k].second.first == "BabyFace") {
								wrestlers[k].second.first = "Heels";
								wrestlers[k].second.second++;		// increment 
							}
							// if Heels, switch to Baby Face
							else {
								wrestlers[k].second.first = "BabyFace";
								wrestlers[k].second.second++;
							}
						}

						// first hasnt been swapped more than once
						else if (wrestlers[i].second.second < 1) {
							// if BabyFace, switch to Heels
							if (wrestlers[i].second.first == "BabyFace") {
								wrestlers[i].second.first = "Heels";
								wrestlers[i].second.second++;	// increment 
							}
							// if Heels, switch to Baby Face
							else {
								wrestlers[i].second.first = "BabyFace";
								wrestlers[i].second.second++;
							}
						}

						else {
							cout << "Not a possible combination of rivals" << endl;
							return 0;
						}
						
					}
				}
			}
		}
		cout << "BabyFaces: ";
		for (int i = 0; i < w; i++) {
			if (wrestlers[i].second.first == "BabyFace") {
				cout << wrestlers[i].first << ", ";
			}
		}
		cout << endl;

		cout << "Heels: ";
		for (int i = 0; i < w; i++) {
			if (wrestlers[i].second.first == "Heels") {
				cout << wrestlers[i].first << ", ";
			}
		}
		cout << endl;
	}

	return 0;
}


