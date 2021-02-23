#include <iostream>
#include <map>
using namespace std;
map<string, string> map1;

//change capital
string changeCapital(string country, string new_capital) {
    string result;
    if(map1[country].empty()) {
        result = "Introduce new country " + country + " with capital " + new_capital; 
    } else if(map1[country] == new_capital) {
        result = "Country " + country + " hasn't changed its capital";
    } else {
        result = "Country " + country + " has changed its capital from " + map1[country] + " to " + new_capital;
    }
    map1[country] = new_capital;
    return result;
}

//rename
string renameCountry(string country, string new_name) {
    string result;
    if(country == new_name || map1.count(country) == 0 || map1.count(new_name) == 1) {
        result = "Incorrect rename, skip";
    } else {
        result = "Country " + country + " with capital " + map1[country] + " has been renamed to " + new_name;
        string temp = map1[country];
        map1[new_name] = temp;
        map1.erase(country);
    }

    return result;
}

//about
string aboutCountry(string country) {
    string result;
    if(map1.count(country) == 0) {
        result = "Country " + country + " doesn't exist";
    } else {
        result = "Country " + country + " has capital " + map1[country];
    }
    return result;
}

//dump
void dump() {
    string result;
    if(map1.empty()) {
        cout << "There are no countries in the world" << endl;
    } else {
        for(auto &item : map1) {
            cout << item.first << "/" << item.second << " ";
        }
        cout << endl;
    }
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        string command;
        cin >> command;
        if(command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            cout << changeCapital(country, new_capital) << endl;
        } else if(command == "RENAME") {
            string country, new_name;
            cin >> country >> new_name;
            cout << renameCountry(country, new_name) << endl;
        } else if(command == "ABOUT") {
            string country;
            cin >> country;
            cout << aboutCountry(country) << endl;
        } else if(command == "DUMP") {
            dump();
        }
    }


    return 0;
}