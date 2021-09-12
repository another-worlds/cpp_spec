#include "iostream"
#include "fstream"
#include "iomanip"
#include "string"
#include "vector"
using namespace std;


void printVector(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << "[" << i << "] = " << vec[i];
        if(i != vec.size() - 1) {
            cout << ", ";
        }
    }
}


void printVectors(vector<vector<int> > vecs) {
    for(int i = 0; i < vecs.size(); i++) {
        cout << "vec#" << i << ": " << endl;
        printVector(vecs[i]);
        cout << endl;
        
    }
}

void createTable(vector<vector<int> > vecs, ostream& os=cout) {
    for(int i = 0; i < vecs.size(); i++) {
        os << setfill(' ');
        for(int j = 0; j < vecs[i].size(); j++) {
            os << setw(10) << vecs[i][j];
            if(j == vecs[i].size() - 1) { 
                continue; 
            }
	        else { os << " "; }
        }
        if(i != vecs.size() - 1) { os << endl; }
    }
}

int printStreamError() {
    cout << "ERR: STREAM ENDED";
    return -1;
}

int main() {
    ifstream is("input.txt");
    ofstream os("output.txt");

    int n, m;
    string line;
    vector<vector<int> > vecs;

    getline(is, line);
    n = line[0] - '0';
    m = line[2] - '0';
    //cout << n << endl << m << endl;
    if(is) {
        for(int i = 0; i < n; i++) {
            vector<int> ints;
            string num;
            for(int j = 0; j < m - 1; j++) {
                if(getline(is, num, ',')) {
                    ints.push_back((int)num[0] - '0');
                }
                else { return printStreamError(); }
            }
            if(getline(is, num, '\n')) {
                ints.push_back((int)num[0] - '0');
            }
            vecs.push_back(ints);
            //is.ignore(1);
        }
    }
    createTable(vecs);
}