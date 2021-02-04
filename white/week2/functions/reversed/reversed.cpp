#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> v1 = v;
    int first = v1[0];
    for(int i = i; i < v1.size() / 2; i++) {
        first = v1[i];
        v1[i] = v1[v1.size() - 1 - i];
        v1[v1.size() - 1 - i] = first;
    }

    return v1;
}

int main() {
    vector<int> v1, v = {1, 5, 3, 4, 2};
    v1 = v;

    v1 = Reversed(v);

    return 0;
}