#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    set<string> set1;
    set1.insert("kek");

    cout << set1.count("kek");

    return 0;
}