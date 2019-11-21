#include <fstream>
#include <sstream>
#include "CourseOffering.h"

CourseOffering::CourseOffering(Department* dep, Course* course, string semester)
{
	dep->addCourse(this);
	_dep = dep;
	_course = course;
	_semester = semester;
}

void CourseOffering::addStudent(Student* student)
{
	student->addCourse(this);
	_students.push_back(student);
}

// get the number of in-department students
int CourseOffering::numberOfInDeptStudent() const {
	int count = 0;
	// Count the number of in department students
	for (int i = 0; i < _students.size(); i++)
	{
		Department* dep = _students[i]->getDepartment();
		if (dep == _dep)
			count ++;
	}
	return count;
}

vector<CourseOffering *> createCourseOfferingsFromFile(const char * fn, vector<Department *> depts, vector<Course *> courses, vector<Student *> students)
{
	ifstream ifs(fn);
    vector<CourseOffering *> courseOfferings;
    
    string s;
    Department* dep;
    Course* course;
	string semester = "";
	 

    while (!ifs.eof())
    {
		// get department
		getline(ifs, s, ',');
        for (int i=0; i< depts.size(); ++i)
        {
			if (depts[i]->getName() == s)
			{
				dep = depts[i];
				break;		
			}
		}
		// get course
        getline(ifs, s, ',');
        for (int i=0; i< courses.size(); ++i)
        {
			if (courses[i]->getName() == s)
			{
				course = courses[i];
				break;
			}
		}
		// get semester
        getline(ifs, s, ',');
        semester = s;
        
        CourseOffering* co = new CourseOffering(dep, course, semester);
        
        // get students names and add into courseoffering
        getline(ifs, s, ':');
        getline(ifs, s);
        // split student name by ','
        stringstream stream(s);
        string name;
		while( getline(stream, name, ',') )
		{
			// add student
			for (int i=0; i< students.size(); ++i)
	        {
				if (students[i]->getName() == name)
				{
					co->addStudent(students[i]);
					break;		
				}
			}
		}
        
        courseOfferings.push_back(co);  
    }
    ifs.close();
    
    return courseOfferings;
}

// Todo
int CourseOffering::getScore(string name)
{
	return 0;
}

// Todo
void CourseOffering::setScore(string name, int score)
{
	
}

// Todo
void setScoreFromFile(const char *fn, vector<CourseOffering *> courses)
{

}

