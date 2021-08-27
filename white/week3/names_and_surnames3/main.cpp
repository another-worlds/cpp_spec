#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;


class Person {
public:
	Person(string first_name, string last_name, int year) {
		first_names[year] = first_name;
		last_names[year] = last_name;
		birthday = year; 
	}

	void ChangeFirstName(int year, const string& first_name){
		if (year >= birthday) {first_names[year] = first_name; }
	}
	void ChangeLastName(int year, const string& last_name){
		if (year >= birthday) {last_names[year]  = last_name; }
	}
	string GetFullNameWithHistory(const int& year) const {
		if (year < birthday) { return "No person"; }
		string first_name = FindNameWithHistory(year, first_names);
		string last_name = FindNameWithHistory(year, last_names);
		if(first_name == "" && last_name == "") {
			return "Incognito";
		} else if(first_name != "" && last_name == "") {
			return first_name + " with unknown last name";
		} else if(first_name == "" && last_name != "") {
			return last_name + " with unknown first name";
		}
		return first_name + " " + last_name;
		
	}

	string GetFullName(const int year) const {
		if (year < birthday) { return "No person"; }
		string first_name = FindFullName(year, first_names);
		string last_name = FindFullName(year, last_names);
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
	string FindFullName(int year, map<int, string> map_names) const {
	    string name = "";
	    for(auto item : map_names) {
			if(item.first <= year) {
				name = item.second;
			}
			else {
				break;
			}
	    }
	    return name;
	}

	string FindNameWithHistory(int year, map<int, string> map_names) const {
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


	string vecToStr(vector<string> vec) const {
		string last_name = vec[vec.size()-1];
		string result = last_name;
		int length = 0;
		
		for (int i = vec.size()-2; i >= 0; i--) {
			// The same => ingore
			if(vec[i] == last_name) {
				continue;
			} else {
				// Not the same
				if (length == 0) {
					result += " (";
					result += vec[i];
					last_name = vec[i];
					length++;
				} else {
					result += ", ";
					result += vec[i];
					last_name = vec[i];
					length++;
				}
				
			}
		}
		// Last elements
		if(length == 0) {
			return result;
		} else {
			result += ")";
			return result;
		}
		
	}

	map<int, string> first_names;
	map<int, string> last_names;
	int birthday;
};



int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}

/*
ANSWER:

No person
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Appolinaria (Polina) Ivanova (Sergeeva)

*/


// int main() {
//   Person person;
  
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1966, "Polina");
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1900, "Polina");

//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeFirstName(1990, "Polina");
//   person.ChangeLastName(1990, "Volkova-Sergeeva");
//   cout << person.GetFullNameWithHistory(1990) << endl;
  
//   person.ChangeFirstName(1966, "Pauline");
//   cout << person.GetFullNameWithHistory(1966) << endl;
  
//   person.ChangeLastName(1960, "Sergeeva");
//   for (int year : {1960, 1967}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeLastName(1961, "Ivanova");
//   cout << person.GetFullNameWithHistory(1967) << endl;
  
//   return 0;
// }

// int main() {
//   Person person;

//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeFirstName(1965, "Appolinaria");

//   person.ChangeLastName(1965, "Sergeeva");
//   person.ChangeLastName(1965, "Volkova");
//   person.ChangeLastName(1965, "Volkova-Sergeeva");

//   for (int year : {1964, 1965, 1966}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }

//   return 0;
// }