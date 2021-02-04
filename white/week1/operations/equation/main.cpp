#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, d, x1, x2;

    cin >> a >> b >> c;

    if(a == 0) {
        if(a == 0 && b == 0) {
            cout << "";
        } else {
            cout << -c / b;
        }
    } else {
        d = b * b - 4 * a * c;
        if(d == 0) {
            cout << (sqrt(d) - b) / (2 * a);
        } else if(d < 0) {
            cout << "";
        } else {
            cout << (-sqrt(d) - b) / (2 * a) << " " << (sqrt(d) - b) / (2 * a);
        }
    }


    return 0;
}