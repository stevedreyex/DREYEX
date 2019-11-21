#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Department.h"
#include "CourseOffering.h"

#define STUDENT_SCOPE 60
#define GRADUATE_STUDENT_SCOPE 70

using namespace std;

class Student {
public:
	Student(string n);
	const string getName() const; 
	Department* getDepartment() const; 
	void setDepartment(Department *d);
	void addCourse(CourseOffering *c);
	vector<CourseOffering*> getCourses() const {return _courses;}
	
	int getGraduationCredits() const;  
	int setGraduationCredits(int gc);  
	int getEarnedCredits() const;
	double getScoreAverage() const;
	int getDepRank() const;
	string getStudentType() const;
	
	virtual bool checkPass(int score) const;
	virtual bool checkGraduation() const;  

protected:
	string _studentType;

private:
	string _name;
	Department * _dept;
	vector<CourseOffering*> _courses;
	int _graduationCredits;

	
};

class GraduateStudent : public Student {
public:
       GraduateStudent(string n="");
       bool isThesisApproved() const;
       void setThesisApproved();
       bool checkGraduation() const; 
       bool checkPass(int score) const;
private: 
       bool _thesisApproved;       
};

vector<Student *> createStudentsFromFile(const char * fn, vector<Department *> depts);

#endif
