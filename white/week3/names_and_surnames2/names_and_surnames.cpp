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
		string last_name = vec[vec.size()-1];
		string result = last_name;
		
		for (int i = vec.size()-2; i >= 0; i--) {
			if(vec[i] == last_name) {
				continue;
			} else if(i == vec.size()-2){
				result += " (";
			}
			// if(vec[i] == "Sokolov") {
			// 	cout << endl;
			// }
			if(i > 0) {
				if(vec[i] == last_name) {
					continue;
				} else {
					last_name = vec[i];
					result += last_name;
					result += ", ";
				}
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
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}
