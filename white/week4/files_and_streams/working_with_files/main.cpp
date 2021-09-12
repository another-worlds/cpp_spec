#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

vector<string> readFile(string filename) {
	ifstream i(filename);
	vector<string> file;

	if(i) {
		string line;
		while(getline(i, line)){
			file.push_back(line);
		}
	}
	return file;
}

int main() {
	string filename = "input.txt";
	vector<string> file = readFile(filename);
	for(const auto& line : file) {
		cout << line << endl;
	}

	return 0;
}
