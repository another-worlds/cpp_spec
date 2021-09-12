#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "iomanip"
using namespace std;

int main() {
	ifstream in("input.txt");
	int n, m;
	string my_endl;
	vector<int> temp;
	if(in) {
		in >> n >> m;
		for(int i = 0; i < n + 1; i++) {
			cout << "i = " << i << ": ";
			string line;
			// getline(in, line);
			in >> line;
			cout << line << endl;
		}
	}

	return 0;
}
