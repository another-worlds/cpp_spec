#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Specialization {
	explicit Specialization(string v) {
		value = v;
	}
	string value;
};

struct Course {
	explicit Course(string v) {
		value = v;
	}string value;
};

struct Week {
	explicit Week(string v) {
		value = v;
	}
	string value;
};

struct LectureTitle {
	explicit LectureTitle(Specialization s, Course c, Week w) {
		specialization = s.value;
		course = c.value;
		week = w.value;
	}

	string specialization;
	string course;
	string week;
};

int main() {
	LectureTitle(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
	return 0;
}
