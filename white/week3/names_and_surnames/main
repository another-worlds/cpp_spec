#include <iostream>
#include <vector>
#include <map>
using namespace std;

string FindName(int year, map<int, string> map_names) {
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
        string result = names[names.size()-1];
        result += " (";
        for (int i = names.size()-2; i >= 0; i--) {
            if(i != 0) {
                result += names[i];
                result += ", ";
            } else {
                result += names[i];
                result += ")";
            }
            
        }
        return result;
    } 
    return name;
}

int main() {
    map<int, string> map1 = {{1967, "Polina"}, {1975, "Karina"}, {1980, "Ira"}, {1990, "Anya"}};
    int year = 0;
    cin >> year;
    string result = FindName(year, map1);

    cout << result << endl;

    return 0;
}