#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    map<int, vector<string> > buses = {{0, {"Marushkino", "Kokoshkino"}}, {1, {"Kokoshkino", "Marushkino"}}};
    map<vector<string>, int> buses1;
    buses1[{"Marushkino", "Kokoshkino"}] = 0;
    buses1[{"Kokoshkino", "Marushkino"}] = 1;

    cout << buses1[{"lle", "Kokoshewefkino"}];
    if(buses[0] == buses[1]) {
        cout << "true";
    }
    return 0;
}