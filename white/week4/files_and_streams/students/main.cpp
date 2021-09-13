#include "iostream"
#include "fstream"
#include "iomanip"
#include "string"
#include "vector"
#include "map"
using namespace std;

struct Student {
public:
    explicit Student(string f_n, string s_n,
                     int d, int m, int y, int i) {
        first_name  = f_n;
        second_name = s_n;
        day = d;
        month = m;
        year = y;
        index = i;
    }


    string first_name;
    string second_name;
    int day;
    int month;
    int year;
    int index;
};

string process_query(int index, string query, vector<Student> students) {
    if(query == "date") {
        //smth
    } else if (query == "name")
}

int main() {
    vector<Student> students;
    int n, m;
    cin >> n;

    for(int i = 0; i < n; i++) {
        //read name and surame
        string f_n, s_n;
        cin >> f_n >> s_n;
        
        //read day, month and year
        int d, m, y;
        cin >> d >> m >> y;

        //create corresponding object
        Student student(f_n, s_n, d, m, y, i + 1);
        students.push_back(student);
    }

    //read number of queries
    cin >> m;

    for(int i = 0; i < m; i++) {
        //read type of query
        string query;
        cin >> query;

        //read object of query
        int index;
        cin >> index;

        //TODO:output query results
        process_query(index, query, students);
    }

    return 0;
}