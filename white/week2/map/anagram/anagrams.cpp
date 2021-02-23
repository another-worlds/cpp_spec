#include <iostream>
#include <map>

using namespace std;

map<char, int> createMap(string word) {
    map<char, int> result;
    for (int j = 0; j < word.size(); j++) {
        {
            result[word[j]]++;
        }
    }
    return result;
}

int main() {

    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        map<char, int> map1, map2;
        string word1, word2;
        cin >> word1 >> word2;
        if(word1.size() == word2.size()) {
            map1 = createMap(word1);
            map2 = createMap(word2);
            if(map1 == map2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
    }
    

    return 0;
}