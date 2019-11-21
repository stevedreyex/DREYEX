#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
#include <vector>

class Student;
class CourseOffering;

using namespace std;

class Department {
public:
	Department(string n);
	const string getName() const;
	void addStudent(Student * s); 
	Student * getStudent(); 
	Student * getStudentByName(string name); 
	int numberOfStudents() const {return _students.size();}
	void addCourse(CourseOffering* courseOffering); 
	// get the number of courses offered by this department
	int numberOfCourses() const {return _courseOfferings.size();}
private:
	string _name;
	vector<Student *> _students;
	vector<CourseOffering *> _courseOfferings;
};

vector<Department *> createDepartmentsFromFile(const char *);

#endif
