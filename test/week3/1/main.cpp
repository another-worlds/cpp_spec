#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> kek;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        kek.push_back(temp);
    }

    sort(kek.begin(), kek.end(), [](int a, int b) {return (abs(a) < abs(b));});
    

    for (int i = 0; i < N; i++) {

        cout << kek[i] << " ";
    }

    return 0;
}
