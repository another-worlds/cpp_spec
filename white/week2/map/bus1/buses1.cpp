#include <iostream>
#include <map>
#include <vector>
using namespace std;
<<<<<<< HEAD
vector<vector<string> > buses;
=======



map<string, vector<string> > buses;
>>>>>>> 6ad0fca6e55bd2551df1e49ddb59c80ad652ac38

int main() {
    int q;
    cin >> q;

<<<<<<< HEAD
    for (int i = 0; i < q; i++)
    {
        string command;
        cin >> command;
        if(command == "NEW_BUS") {
            
        }
    }
    
=======
    for(int l = 0; l < q; l++) {
        string command;
        cin >> command;
        if(command == "NEW_BUS") {
            string bus, stop;
            int count;
            cin >> bus >> count;
            for(int j = 0; j < count; j++) {
                cin >> stop;
                buses[bus].push_back(stop);
            }
        } else if(command == "BUSES_FOR_STOP") {
            string stop;
            int counter = 0;
            cin >> stop;
            for(const auto& item : buses) {
                for (int m = 0; m < item.second.size(); m++)
                {
                    if(item.second.at(m) == stop) {
                        cout << item.first << " ";
                        counter++;
                        break;
                    }
                }

                
            }
            if(counter == 0) {
                cout << "No stop";
            }
            cout << endl;

        } else if(command == "STOPS_FOR_BUS") {
            string busStr;
            vector<string> stops;
            cin >> busStr;

            //if we have no buses
            if(buses.count(busStr) == 0) {
                cout << "No bus" << endl;
            }
            else {
                //list of stops of the bus
                stops = buses[busStr];
                for(const auto& stop : stops) {
                    int counter = 0;
                    cout << "Stop " + stop + ": ";
                    //iterating through buses to search for stops
                    for(const auto& busItem : buses) {
                        if(busItem.first != busStr) {
                            //iterating through children stops
                            for(const auto& stopp : busItem.second) {
                                if(stopp == stop) {
                                    if(busItem.first == "272") {
                                        string lol = "kek";
                                    }
                                    cout << busItem.first << " ";
                                    counter++;
                                }
                            }

                        }
                    }
                    if(counter == 0) {
                        cout << "no interchange";
                    }
                    cout << endl;
                }
            }


        } else if(command == "ALL_BUSES") {
            if(buses.size() == 0) {
                cout << "No buses" << endl;
            }
            for(const auto& bus : buses) {
                cout << "Bus " << bus.first  << ": ";
                for(const auto& stop : bus.second) {
                    cout << stop << " ";
                }
                cout << endl;
            }
        }
    }
>>>>>>> 6ad0fca6e55bd2551df1e49ddb59c80ad652ac38

    return 0;
}