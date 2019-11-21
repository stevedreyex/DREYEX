#include <fstream>
#include "Student.h"
#include "StudentFactory.h"

Student::Student(string n):_name(n), _studentType("Student"){}
const string Student::getName() const {return _name;}
Department * Student::getDepartment() const {return _dept;}
void Student::setDepartment(Department *d) {_dept = d;} 
int Student::setGraduationCredits(int gc) {_graduationCredits = gc;}
int Student::getGraduationCredits() const {return _graduationCredits;} 

// Todo
bool Student::checkGraduation() const 
{
     return true;
}

// Todo
int Student::getEarnedCredits() const 
{
	return 0;
}

// Todo
bool Student::checkPass(int score) const
{
	return true;
}

// Todo
double Student::getScoreAverage() const
{
	return 0;
}

// Todo
int Student::getDepRank() const
{
	return 0;
}

string Student::getStudentType() const
{
	return _studentType;
}

void Student::addCourse(CourseOffering* c)
{
	_courses.push_back(c);
}

// Todo
vector<Student *> createStudentsFromFile(const char * fn, vector<Department *> depts)
{
	vector<Student *> s;
	return s;

} 


GraduateStudent::GraduateStudent(string n):Student(n), _thesisApproved(false){ _studentType = "GraduateStudent";}
bool GraduateStudent::isThesisApproved() const {return _thesisApproved;}
void GraduateStudent::setThesisApproved() {_thesisApproved = true;}
bool GraduateStudent::checkGraduation() const {return Student::checkGraduation() && isThesisApproved();}

// Todo
bool GraduateStudent::checkPass(int score) const
{
	return true;
}
