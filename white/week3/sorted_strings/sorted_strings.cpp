#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class SortedStrings {
public:
	void AddString(const string& s) {
		strings.push_back(s);
	}

	vector<string> GetSortedStrings() {
		SortStrings();
		return strings;
	}
	
	void SortStrings() {sort(strings.begin(), strings.end());}
private:
	vector<string> strings;
};


void PrintStrings(const vector<string>& strings) {
	for(const string& s : strings) {
		cout << s << endl;
	}
}

int main() {
	SortedStrings sortedStrings;
	sortedStrings.AddString("first");
	sortedStrings.AddString("third");
	sortedStrings.AddString("second");

	PrintStrings(sortedStrings.GetSortedStrings());

	sortedStrings.AddString("second");
	PrintStrings(sortedStrings.GetSortedStrings());

	return 0;
}
