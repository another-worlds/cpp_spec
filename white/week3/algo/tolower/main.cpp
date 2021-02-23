#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;


int main() {
    vector<int> cap;
    int q;
    cin >> q;
    string str;
    vector<char> vec;
    

    for (int i = 0; i < q; i++)
    {
        char ch;
        cin >> ch;
        vec.push_back(ch);
    }

    
    sort(begin(vec), end(vec), [](int x, int y) { 
        return tolower(x) < tolower(y);
    });

    for (int j = 0; j < q; j++)
    {
        cout << vec[j] << " ";
    }
    
    return 0;
}