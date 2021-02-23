#include <iostream>
#include <map>
#include <set>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> result;
  for(const auto& item : m) {
      result.insert(item.second);
  }
  return result;
}

// int main() {
//     map<int, string> kek = {
//         {1, "odd"},
//         {2, "even"},
//         {3, "odd"},
//         {4, "even"},
//         {5, "odd"}
//     };
//     set<string> values = BuildMapValuesSet(kek);
//     for (const string& value : values) {
//     cout << value << endl;
//     }

//     return 0;
// }