#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct kek {
    vector<string> stops;
    int pos;
};

vector<vector<string> > buses;
int count;

int main() {
    int q;
    cin >> q;

    for(int m = 0; m < q; m++) {
        string command;
        cin >> command;
        if(command == "NEW_BUS") {
            vector<string> stops;
            string busStr;
            int count;
            cin >> busStr >> count;
            stops.push_back(busStr);
            for(int j = 0; j < count; j++) {
                string stop;
                cin >> stop;
                stops.push_back(stop);
            }
            buses.push_back(stops);
        }
        else if(command == "BUSES_FOR_STOP") {
            string stopStr;
            int stopCounter = 0;
            cin >> stopStr;

            //searching for buses

            //iterating through bus vectors
            for(int i = 0; i < buses.size(); i++) {

                //iterating through strings
                for(int j = 1; j < buses.at(i).size(); j++) {
                    string stopItem = buses.at(i).at(j);

                    //checking if strings matches the stop
                    if(stopItem == stopStr) {
                        cout << buses.at(i).at(0) << " ";
                        stopCounter++;
                        break;
                    }
                }
            }
            //if no bus found
            if(stopCounter == 0) {
                cout << "No stop";
            }
            cout << endl;
        } else if(command == "STOPS_FOR_BUS") {
            string busStr;
            int busCounter = 0, busPos;

            cin >> busStr;
            
            //finding position of current pos
            for(int i = 0; i < buses.size(); i++) {
                if(buses.at(i).at(0) == busStr) {
                    busCounter++;
                    busPos = i;
                    break;
                }
            }
            if(busCounter == 0) {
                cout << "No bus" << endl;
            } else {
                //iterating through each stop
                for(int i = 1; i < buses.at(busPos).size(); i++) {
                    int inter = 0;
                    string currentStop = buses.at(busPos).at(i);
                    cout << "Stop " << currentStop << ": ";
                    //searching for buses
                    for(int k = 0; k < buses.size(); k++) {
                        if(k != busPos) {
                            for(int j = 1; j < buses.at(k).size(); j++) {
                                if(buses.at(k).at(j) == currentStop) {
                                    cout << buses.at(k).at(0) << " ";
                                    inter++;
                                }
                            }
                        }
                        
                    }
                    if(inter == 0) {
                        cout << "no interchange";
                    }
                    cout << endl;
                }
            }



        }
        else if(command == "ALL_BUSES") {
            if(buses.size() == 0) {
                cout << "No buses" << endl;
            } else {
                map<string, vector<string> > alp;
                for(int k = 0; k < buses.size(); k++) {
                    vector<string> stops;
                    for(int j = 1; j < buses.at(k).size(); j++) {
                        stops.push_back(buses.at(k).at(j));
                    }
                    alp[buses[k][0]] = stops;
                }
                for(auto& item : alp) {
                    cout << "Bus " << item.first << ": ";
                    for(auto& str : item.second) {
                        cout << str << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}