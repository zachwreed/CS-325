/**************************************************
** Author: Zach Reed
** Date: 1/20/2019
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

void merge(vector<int> &data, int low, int high, int mid1, int mid2, int mid3){
	int i= low, j = mid1, k = mid2;
	vector<int> tempVect;

	while ((i < mid1) && (j < mid2) && (k < high)) {
		if (data[i] < data[j]) {
			if (data[i] < data[k]) {
				tempVect.push_back(data[i]);
				i++;
			}

			else {
				tempVect.push_back(data[k]);
				k++;
			}
		}

		else {
			if (data[j] < data[k]) {
				tempVect.push_back(data[j]);
				j++;
			}

			else {
				tempVect.push_back(data[k]);
				k++;
			}
		}
	}

	// Cases where i and j ranges have remaining values
	while ((i < mid1) && (j < mid2)) {
		if (data[i] < data[j]) {
			tempVect.push_back(data[i]);
			i++;
		}

		else {
			tempVect.push_back(data[j]);
			j++;
		}
	}

	while ((j < mid2) && (k < high)) {
		if (data[j] < data[k]) {
			tempVect.push_back(data[j]);
			j++;
		}

		else {
			tempVect.push_back(data[k]);
			k++;
		}
	}

	while ((i < mid1) && (k < high)) {
		if (data[i] < data[k]) {
			tempVect.push_back(data[i]);
			i++;
		}

		else {
			tempVect.push_back(data[k]);
			k++;
		}
	}

	// copy remaining values from i, j, k
	while (i < mid1) {
		tempVect.push_back(data[i]);
		i++;
	}

	while (j < mid2) {
		tempVect.push_back(data[j]);
		j++;
	}

	while (k < high) {
		tempVect.push_back(data[k]);
		k++;
	}
	
	for (int x = low; x < high; x++) {
		data[x] = tempVect[x - low];
	}
}


void mergeSort(vector<int> &data, int low, int high){
	int mid1 = low + ((high - low) /4);
	int mid2 = low + 2 * ((high - low) / 4) + 1;
	int mid3 = low + 2 * ((high - low) / 4) + 1;
	
	if (high - low >= 2) {
		mergeSort(data, low, mid1);
		mergeSort(data, mid1, mid2);
		mergeSort(data, mid2, mid3);
		mergeSort(data, mid3, high);
		
		merge(data, low, high, mid1, mid2, mid3);
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
			mergeSort(data, 0, data.size() - 1);
			high_resolution_clock::time_point end = high_resolution_clock::now();

			auto runtime = duration_cast<microseconds>(end - start).count();
			cout << "Size of array n = " << n << endl;
			cout << "Duration of algorithm in microseconds = " << runtime << endl;
		}
	}

	return 0;
}