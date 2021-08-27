#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString(string str_input) { str = str_input; }

  void Reverse() {
    vector<int> strR;
    for (const auto& let : str) { strR.push_back(let); }
    for (int i = strR.size(); i >= 0; i--) { str[strR.size()-1 - i] = strR[i]; }
  }

  string ToString() const {
    return str;
  }

private:
	string str;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
