#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {
    string in_n = "input.txt";
    ifstream in(in_n);

    cout << setprecision(3) << fixed;

    if(in) {
        string line;
        while(getline(in, line)) {
            //cout << line;
            cout << stod(line) << endl;
        }
    }
}
