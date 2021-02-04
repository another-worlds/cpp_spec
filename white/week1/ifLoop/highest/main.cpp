#include <iostream>
using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    while(b > 0 && a > 0) {
        if(a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    cout << b + a;

    return 0;
}