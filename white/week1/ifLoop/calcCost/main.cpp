#include <iostream>
using namespace std;

int main() {
    double N, A, B, X, Y, res;

    cin >> N >> A >> B >> X >> Y;

    res = N;
    if(N > A) {
        res = N * (100 - X)/ 100;
    }
    if(N > B) {
        res = N * (100 - Y)/ 100;
    } 
    cout << res;


    return 0;
}