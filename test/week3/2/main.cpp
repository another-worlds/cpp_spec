#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string tolower(string s) {
	for(int i = 0; i < s.length(); i++){
		s[i] = tolower(s[i]);
	}
	return s;
}

bool islower(string s1, string s2) {
	s1 = tolower(s1);
	s2 = tolower(s2);
	return (s1 < s2);
}


int main() {

	vector<string> strings;
	int N;

	cin >> N;

	for(int i = 0; i < N; i++) {
		string temp; cin >> temp;
		strings.push_back(temp);
	}

	sort(strings.begin(), strings.end(), [](string s1, string s2){return (tolower(s1) < tolower(s2)); });
	
	for (int i = 0; i < N; i++) {
		cout << strings[i] << " ";
	}
	return 0;
}
