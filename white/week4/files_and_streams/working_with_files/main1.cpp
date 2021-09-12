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

void writeFile(string filename, vector<string> file) {
	ofstream out(filename, ios::app);

	for(const auto& line : file) {
		out << line << endl;
	}
}

int main() {
	string file_in = "input.txt";
	string file_out = "output.txt";
	
	ifstream i(file_in);
	ofstream o(file_out);
	string line;
	while(getline(i, line)) {
		o << line << endl;
	}

	return 0;
}
