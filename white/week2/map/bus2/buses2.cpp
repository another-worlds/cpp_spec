#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<vector<string>, int> buses;
int counter = 0;

int main() {
    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        vector<string> stops;
        int stopNum;
        cin >> stopNum;
        for(int j = 0; j < stopNum; j++) {
            string stop;
            cin >> stop;
            stops.push_back(stop);
        }
        if(i == 3) {

        }
        if(buses[stops] != 0) {
            cout << "Already exists for " << buses[stops] << endl;
        } else {
            counter++;
            buses[stops] = counter;
            cout << "New bus " << counter << endl;
        }
    }

    return 0;
}