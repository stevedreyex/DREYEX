#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>

using namespace std;

class Course {
public:
	Course(string name, int credit, string description);
	const string getName() const;
	int getNumOfCredits() const;
	string getDescription() const;
private:
	string _name;
	int _credit;
	string _description;
};

vector<Course *> createCoursesFromFile(const char * fn);

#endif
