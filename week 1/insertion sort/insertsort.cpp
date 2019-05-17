/*********************************************
** Author: Zach Reed
** Date: 1/13/2019
** Description: insert sort algorithm
**********************************************/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

		// Insertion Sort Algorithm ------------
		int i, k, temp;
		for (i = 1; i < data.size(); i++) {
			k = i;

			while ( k > 0 && data[k - 1] > data[k]) {
				temp = data[k - 1];
				data[k - 1] = data[k];
				data[k] = temp;
				k--;
			}
		}

		output_file.open("insert.txt");
		for (int i = 0; i < data.size(); i++) {
			output_file << data[i];
			output_file << " ";
		}
		output_file.close();
		cout << "data.txt read, values sorted and stored in insert.txt" << endl;
	}

	else {
		cout << "File was not openned." << endl;
	}


	return 0;
}