#include <iostream>
#include <vector>
using namespace std;

vector<bool> v(0);

//�������� i-�� �������� � ������ ������� ��� ��������������
void worry(int i) {
    if(i < v.size()) {
        v[i] = true;
    }
    
}

//�������� i-�� �������� ��� ��������������;
void quiet(int i) {
    if(i < v.size()) {
        v[i] = false;
    }
}

//�������� k ��������� ������� � ����� �������;
void come(int k) {
    if(k > 0) {
        for (int i = 0; i < k; i++)
        {
            v.push_back(false);
        }
    } 
//������ k ������� �� ����� �������;
    else if(k < 0) {
        v.resize(v.size() + k);
    }
}



//������ ���������� ������������� ����� � �������.
int worry_count() {
    int sum  = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == true) {
            sum++;
        }
    }
    return sum;
}

int extract(string str) {
    string num = "";
    for (int i = 4; i < str.size(); i++)
    {
        num.push_back(str[i]);
    }
    return stoi(num);
}

int main() {

    int n = 0;
    string command = "";
    int num = 0;
    cin >> n;
    vector<int> res;

    for(int i = 0; i < n; i++) {
        cin >> command;
        if(command == "WORRY_COUNT") {
            cout << worry_count() << endl;
        }
        else if(command == "COME") {
            cin >> num;
            come(num);
        }
        else if(command == "WORRY") {
            cin >> num;
            worry(num);
        }
        else if(command == "QUIET") {
            cin >> num;
            quiet(num);
        }
    }
    
    return 0;
}