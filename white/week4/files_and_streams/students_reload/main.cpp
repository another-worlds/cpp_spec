#include "iostream"
#include "fstream"
#include "iomanip"
#include "vector"
#include "string"
using namespace std;

/*
how to control the input data?
maybe create my own set of input and runtime control
functions?

idea 1: input controller class for controlling input
variables of the variables like N, M, etc
*/

#define DEBUG
//#undef DEBUG

#ifdef DEBUG
ifstream is("test");
ofstream os("output.txt");
#else
istream& is = cin;
ostream& os = cout;
#endif


struct Student {
public:
    Student(string f_n, string s_n, 
            int d, int m, int y) {
        name = f_n + " " + s_n;
        date = to_string(d) + "." +
               to_string(m) + "." + 
               to_string(y);
    }

    string name;
    string date;
};

class StudentOperator {
public:

    void createStudents(int n) {
        string f_n, s_n;
        int d, m, y;
        if(is) {
            for(int i = 0; i < n; i++) {
                is >> f_n >> s_n;
                is >> d >> m >> y;
                Student st(f_n, s_n, d, m, y);
                studentVector.push_back(st);
            }
        } else {
            os << "STREAM ERROR";
        }
    }

    void processQueries(int m) {
        string query;
        int index;
        for(int i = 0; i < m; i++) {
            is >> query >> index;
            os << processQuery(index - 1, query) << endl;
        }
    }

    string processQuery(int index, string query) {
        string result = "bad request";
        if(index >= 0 && index < studentVector.size()) {
            if(query == "name") {
                return studentVector[index].name;
            } else if(query == "date") {
                return studentVector[index].date;
            }
        }
        return result;
    }

    vector<Student> studentVector;
};


int main() {

    int n = 0, m = 0;

    StudentOperator so;

    is >> n;

    so.createStudents(n);
    
    is >> m;

    so.processQueries(m);
}