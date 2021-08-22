#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;


class Person {
public:
	void ChangeFirstName(int year, const string& first_name){
		first_names[year] = first_name;
		first_set.insert(first_name);
	}
	void ChangeLastName(int year, const string& last_name){
		last_names[year]  = last_name;
		last_set.insert(last_name);
	}
	string GetFullNameWithHistory(int year) {
		string first_name = FindName(year, first_names, first_set);
		string last_name = FindName(year, last_names, last_set);
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

	string FindName(int year, map<int, string> map_names, set<string> set_names) {
	    string name = "";
	    vector<string> names;
	    for(auto item : map_names) {
			if(item.first <= year) {
				name = item.second;
				names.push_back(name);
			}
			else {
				break;
			}
	    }
	    if (names.size() > 1) {
			return vecToStr(names);
	    } 
	    return name;
	}


	string vecToStr(vector<string> vec) {
		string result = vec[vec.size()-1];
		result += " (";
		for (int i = vec.size()-2; i >= 0; i--) {
			if(i != 0) {
				result += vec[i];
				result += ", ";
			} else if(vec[i] == vec[i - 1]) {
				continue;
			} else {
				result += vec[i];
				result += ")";
			}
		}
		return result;
	}

	map<int, string> first_names;
	map<int, string> last_names;

	set<string> first_set;
	set<string> last_set;
};

int main() {
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;


	return 0;
}
