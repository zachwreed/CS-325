/**************************************************
** Author: Zach Reed
** Description: Measures time to merge sort an algorithm of n size taken as an argument.
** Date: 1/13/2019
***************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

/************************
** Author: Sanfoundry
** Title: C++ Program to Implement Merge Sort
** Type: Source code for the functions merge() and mergesort()
** Availability: https://www.sanfoundry.com/cpp-program-implement-merge-sort
*************************/

void merge(vector<int> &data, int low, int high, int mid){
	int i = low;
	int j = mid + 1;
	vector<int> tempData;

	while (i <= mid && j <= high) {
		// if in order
		if (data[i] < data[j]) {
			tempData.push_back(data[i]);
			i++;
		}
		// else if not in order
		else {
			tempData.push_back(data[j]);
			j++;
		}
	}

	while (i <= mid) {
		tempData.push_back(data[i]);
		i++;
	}

	while (j <= high) {
		tempData.push_back(data[j]);
		j++;
	}

	for (i = low; i <= high; i++) {
		data[i] = tempData[i - low];
	}
}


void mergeSort(vector<int> &data, int low, int high){
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(data, low, mid);
		mergeSort(data, mid + 1, high);

		merge(data, low, high, mid);
	}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	vector<int> data;
	int val, n;
	clock_t start, end;
	if (argc >= 2){
		std::istringstream iss(argv[1]);

		if (iss >> n)
		{
			for (int i = 0; i < n; i++) {
				val = rand() % 10000 + 0;
				data.push_back(val);
			}

			high_resolution_clock::time_point start = high_resolution_clock::now();
			mergeSort(data, 0, data.size() - 1);
			high_resolution_clock::time_point end = high_resolution_clock::now();

			auto runtime = duration_cast<microseconds>(end - start).count();
			cout << "Size of array n = " << n << endl;
			cout << "Duration of algorithm in microseconds = " << runtime << endl;
		}
	}

	return 0;
}