#include <iostream>
using namespace std;

bool IsPalindrom(string str) {
    if(str.size() == 0) { 
        return true;
    }
    else {
        for(int i = 0; i < str.size() / 2; i++) {
            if(str[i] != str[str.size() - 1 - i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string str;
    cin >> str;

    cout << IsPalindrom(str);

    return 0;
}
