/**************************************************
** Author: Zach Reed
** Date: 1/13/2019
***************************************************/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

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

int main() {
	vector<int> data;
	ifstream input_file;
	ofstream output_file;

	input_file.open("data.txt");

	if (input_file.is_open()) {
		int val;
		while (!input_file.eof()) {
			input_file >> val;
			data.push_back(val);
		}
		input_file.close();

		mergeSort(data, 0, data.size() - 1);

		output_file.open("merge.txt");
		for (int i = 0; i < data.size(); i++) {
			output_file << data[i];
			output_file << " ";
		}
		output_file.close();
		cout << "data.txt has been read and merge sorted into merge.txt" << endl;
	}

	else {
		cout << "File was not openned." << endl;
	}

	return 0;
}