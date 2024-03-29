#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool compareNumbers(int a) {

}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name){
		first_names[year] = first_name;
		first_vec.push_back(year);
	}
	void ChangeLastName(int year, const string& last_name){
		last_names[year]  = last_name;
		last_vec.push_back(year);
	}
	string GetFullName(int year) {
		string first_name = FindName(year, first_names, first_vec);
		string last_name = FindName(year, last_names, last_vec);
		if(first_name == "" && last_name == "") {
			return "Incognito";
		} else if(first_name != "" && last_name == "") {
			return first_name + " with unknown last name";
		} else if(first_name == "" && last_name != "") {
			return last_name + " with unknown first name";
		}
		return first_name + " " + last_name;
	}
private:
	// string FindName1(int& year, map<int, string>& map_names, vector<int>& vec) {
	// 	if(vec.size() > 1) {
	// 		sort(vec.begin(), vec.end());
	// 		int y = *max_element(vec.begin(), vec.end(), [year](int a, int b){return (b > a && b <= year);});
	// 		return map_names[y];
	// 	} else if(vec.size() == 1) {
	// 		return map_names[year];
	// 	} 
	// 	else {
	// 		return "";
	// 	}
	// }

	string FindName(int year, map<int, string> map_names, vector<int> vec) {
		if(vec.size() > 1) {
			if(map_names.count(year) >= 1) {return map_names[year];}
			// if (year == 1970) {
			// 	cout << "kek";
			// }
			vec.push_back(year);
			sort(vec.begin(), vec.end());
			// Check the year is the first element => Incognito
			if(vec.size())
			if(vec[0] == year && vec[0] != vec[1]) {return "";};
			vector<int>::iterator iterator_year = find(vec.begin(), vec.end(), year);
			int current_index = distance(vec.begin(), iterator_year);
			int name_index = vec[current_index - 1];
			return map_names[name_index];
		} else if(vec.size() == 1) {
			if(year < vec[0]) {return "";} else {return map_names[vec[0]];}
		} else {
			return "";
		}
	}

	map<int, string> first_names;
	map<int, string> last_names;

	vector<int> first_vec;
	vector<int> last_vec;
};

int main() {
	Person person;
	bool debug =  true;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
