#ifndef COURSE_OFFERING_H
#define COURSE_OFFERING_H
#include <string>
#include <vector>
#include "Department.h"
#include "Student.h"
#include "Course.h"
#include <map>

using namespace std;

class CourseOffering {
public:
	CourseOffering(Department* dep, Course* course, string semester);
	void addStudent(Student* student);
	int numberOfStudent() const {return _students.size();}
	// get the number of in-department students
	int numberOfInDeptStudent() const;
	vector<Student*> getStudents() const {return _students;}
	Department* getDepartment() const {return _dep;}
	Course* getCourse() const {return _course;}
	string getSemester() const {return _semester;}
	
	int getScore(string name);
	void setScore(string name, int score);
	
private:
	Department* _dep;
	Course* _course;
	string _semester;
	vector<Student*> _students;
	map<Student*, int> _scores; // 可自行修改以其他資料結構儲存學生成績 
};

vector<CourseOffering *> createCourseOfferingsFromFile(const char * fn, vector<Department *> depts, vector<Course *> courses, vector<Student *> students);
void setScoreFromFile(const char *fn, vector<CourseOffering *>);
#endif
