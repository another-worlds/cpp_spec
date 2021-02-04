#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> cringe;
    int kek[10];

    cin >> n;

    while(n > 0) {
        cringe.push_back(n % 2);
        n /= 2;
    }

    for(int i = cringe.size() - 1; i >= 0; i--) {
        cout << cringe[i];
    }
    
    return 0;
}
