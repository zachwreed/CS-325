/****************************************************************
** Author: Zach Reed
** Description: shopping algorithm implementation
** Date: 1/27/2019
*****************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int max(int x, int y) { 
	return (x > y) ? x : y; 
}

int knapsack(vector<int> P, vector<int> objectW, int N, int M, vector<int> &fSeq) {
	int** matrix = new int*[N + 1];
	for (int i = 0; i < N + 1; i++) {
		matrix[i] = new int[M + 1];
	}

	for (int i = 0; i <= N; i++) {

		for (int j = 0; j <= M; j++) {

			if (i == 0 || j == 0) {
				matrix[i][j] = 0;
			}

			else if (objectW[i - 1] <= j) {
				matrix[i][j] = max(P[i - 1] + matrix[i - 1][j - objectW[i - 1]], matrix[i - 1][j]);
			}

			else {
				matrix[i][j] = matrix[i - 1][j];
			}
		}
	}
	int weight = M;
	int max = matrix[N][M];
	
	for (int i = N; i > 0 && max > 0; i--) {

		if (max == matrix[i - 1][weight]) {
			continue;
		}

		else {
			fSeq.push_back(i);
			max = max - P[i - 1];
			weight = weight - objectW[i - 1];
		}
	}

	int val = matrix[N][M];

	for (int i = 0; i < N + 1; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return val;
}

int main() {
	std::ifstream inputFile;
	std::ofstream outputFile;
	inputFile.open("shopping.txt");
	outputFile.open("results.txt");
	if (inputFile.is_open()) {
		int t, n, p, w, f, m;
		inputFile >> t;

		int totalprice = 0;
		for (int i = 0; i < t; i++) { // test loops
			inputFile >> n; // num objects
			vector<int> objectP;
			vector<int> objectW;
			for (int j = 0; j < n; j++) { // item loop
				inputFile >> p;
				inputFile >> w;
				objectP.push_back(p);
				objectW.push_back(w);
			}
			int fMaxPrice = 0;
			inputFile >> f;
			outputFile << "Test Case " << (i + 1) << endl;
			for (int k = 0; k < f; k++) { // family loop
				inputFile >> m;
				vector<int> fSeq;
				fMaxPrice += knapsack(objectP, objectW, n, m, fSeq);
				
				outputFile << "   Member " << (k + 1) << " Items: ";
				for (size_t l = 0; l < fSeq.size(); l++) {
					outputFile << fSeq[l] << " ";
				}
				outputFile << endl;

			}				
			outputFile << "Total Price: " << fMaxPrice << endl;
			outputFile << endl;
		}
	inputFile.close();
	}
	
	return 0;
}

