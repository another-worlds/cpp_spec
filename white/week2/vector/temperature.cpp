#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0, temp = 0, sum = 0;

    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v[i] = temp;
        sum += temp;
    }

    int avg = sum / n;

    vector<int> result;

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] > avg) {
            result.push_back(i);
        }
    }

    cout << result.size() << endl;

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    
    

    return 0;
}