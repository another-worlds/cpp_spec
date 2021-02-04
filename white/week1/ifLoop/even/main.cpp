#include <iostream>
using namespace std;

int main() {
    int a, b, i;

    cin >> a >> b;

    if(a % 2 == 0) {
        i = a;
    }
    else {
        i = a + 1;
    }

    while(i <= b) {
        cout << i << " ";
        i += 2;
    }

    return 0;
}