#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v(0);
    cout << v.size() << endl;

    v.clear();
    cout << v.size() << endl;

    v.resize(0);
    cout << v.size() << endl;

    cout << "ffff".type() << endl;

    return 0;
}