#include <iostream>
using namespace std;

int main() {
    string str;
    int in = 0;

    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'f') {
            in++;
        }
        if(in == 2) {
            cout << i;
            break;
            return 0;
        }
    
    }

    if(in == 1) {
        cout << "-1";
    } else if (in == 0) {
        cout << -2;
    }

    return 0;
}