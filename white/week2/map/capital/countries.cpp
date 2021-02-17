#include <iostream>
#include <map>
using namespace std;
map<string, string> map1;

//change capital
void changeCapital(string country, string new_capital) {
    map1[country] = new_capital;
}

//rename
void renameCountry(string country, string new_name) {
    map1[country]
}

//about
string aboutCountry(string country) {

}

//dump
string dump() {

}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        string command;
        if(command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            changeCapital(country, new_capital);
        } else if(command == "RENAME") {
            string country, new_name;
            cin >> country >> new_name;
        } else if(command == "ABOUT") {
            string country;
            cin >> country;
        } else if(command == "DUMP") {
            string result;
            cout << result;
        }
    }
    


    return 0;
}