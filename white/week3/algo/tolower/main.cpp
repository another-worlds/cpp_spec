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
    vector<string> vec;
    

    for (int i = 0; i < q; i++)
    {
        string ch;
        cin >> ch;
        vec.push_back(ch);
    }

    
    sort(begin(vec), end(vec), [](string x, string y) {
        string x1, y1;
        x1 = x; 
        y1 = y;
        for(int l = 0; l < x1.size(); l++) {
            x1[l] = tolower(x1[l]);
        }
        for(int k = 0; k < y1.size(); k++) {
            y1[k] = tolower(y1[k]);
        }
        
        return x1 < y1;
    });

    for (int j = 0; j < q; j++)
    {
        cout << vec[j] << " ";
    }
    
    return 0;
}