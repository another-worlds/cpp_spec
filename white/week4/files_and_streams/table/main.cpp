#include "iostream"
#include "fstream"
#include "iomanip"
#include "string"
#include "vector"
using namespace std;


// void printVector(vector<int> vec) {
//     for(int i = 0; i < vec.size(); i++) {
//         cout << "[" << i << "] = " << vec[i];
//         if(i != vec.size() - 1) {
//             cout << ", ";
//         }
//     }
// }


// void printVectors(vector<vector<int> > vecs) {
//     for(int i = 0; i < vecs.size(); i++) {
//         cout << "vec#" << i << ": " << endl;
//         printVector(vecs[i]);
//         cout << endl;
        
//     }
// }

//
//
//vector<vector<int> > vecs readTable(istream& is=cin, delimiter=',') {
//	string line;
//	vector<int> nums;
//	vector<int> ints;
//	vector<vector<int> > vecs;
//	if (is) {
//		
//	} else {
//		printStreamError();
//		return 
//	}
//}


int printStreamError(string msg="ERR: STREAM ENDED") {
    cout << msg;
    return -1;
}

vector<int> extractFirstLineNumbers(istream& is, int numbers=2, char delimiter=' ') {
	int temp;
	string line;
	vector<int> ints;
	if(is) {
		for(int i = 0; i < numbers - 1; i++) {
			getline(is, line, delimiter);
			temp = stoi(line);
			ints.push_back(temp);
		}
		getline(is, line, '\n');
		temp = stoi(line);
		ints.push_back(temp);
		return ints;
	} else{
		printStreamError("Stream does not exist");
		return ints;
	}
}

void createTable(vector<vector<int> > vecs, ostream& os=cout) {
    for(int i = 0; i < vecs.size(); i++) {
        os << setfill(' ') << fixed;
        for(int j = 0; j < vecs[i].size(); j++) {
            os << setw(10) << vecs[i][j];
            if(j < vecs[i].size() - 1) { 
                os << " ";
            }
        }
        if(i != vecs.size() - 1) { os << endl; }
    }
}


int main() {
    ifstream is_("input.txt");
    ofstream os("output.txt");

    int n, m;
    string line;
    vector<vector<int> > vecs;
    vector<int> ints;

    ints = extractFirstLineNumbers(is_, ' ');
    n = ints[0];
    m = ints[1];

    ifstream is("input.txt");
   
    
    //cout << n << endl << m << endl;
    if(is) {
        getline(is, line);
        for(int i = 0; i < n; i++) {
            vector<int> ints;
            string num;
            for(int j = 0; j < m - 1; j++) {
                if(getline(is, num, ',')) {
                    ints.push_back(stoi(num));
                }
                else { return printStreamError(); }
            }
            if(getline(is, num, '\n')) {
                ints.push_back(stoi(num));
            }
            vecs.push_back(ints);
        }
    }
    createTable(vecs);
}
