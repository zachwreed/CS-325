/*********************************************
** Author: Zach Reed
** Date: 1/13/2019
** Description: insert sort algorithm
**********************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <chrono>
using namespace std;
using namespace std::chrono;


void insertsort(vector<int> &datasort) {
	int i, k, temp;
	for (i = 1; i < datasort.size(); i++) {
		k = i;

		while (k > 0 && datasort[k - 1] > datasort[k]) {
			temp = datasort[k - 1];
			datasort[k - 1] = datasort[k];
			datasort[k] = temp;
			k--;
		}
	}
}


int main(int argc, char *argv[]) {
	srand(time(NULL));
	vector<int> data;
	int val, n;
	clock_t start, end;
	if (argc >= 2) {
		std::istringstream iss(argv[1]);

		if (iss >> n)
		{
			for (int i = 0; i < n; i++) {
				val = rand() % 10000 + 0;
				data.push_back(val);
			}

			high_resolution_clock::time_point start = high_resolution_clock::now();
			insertsort(data);
			high_resolution_clock::time_point end = high_resolution_clock::now();

			auto runtime = duration_cast<microseconds>(end - start).count();
			cout << "Size of array n = " << n << endl;
			cout << "Duration of algorithm in microseconds = " << runtime << endl;
		}
	}

	return 0;
}