#include <fstream>
#include "Department.h"
#include "Student.h"
#include "CourseOffering.h"

Department::Department(string n):_name(n){}

const string Department::getName() const {return _name;} 

void Department::addStudent(Student * s) 
{
     _students.push_back(s);
     s->setDepartment(this);
}

Student * Department::getStudent() {return _students.back();}

Student * Department::getStudentByName(string name)
{
        for (int i=0; i< _students.size(); ++i)
            if (_students[i]->getName() == name)
               return _students[i];
        return NULL;
}

void Department::addCourse(CourseOffering* courseOffering) 
{
     _courseOfferings.push_back(courseOffering);
}

vector<Department *> createDepartmentsFromFile(const char * fn)
{
    vector<Department *> depts;
    ifstream ifs(fn);
    string s;
    while (!ifs.eof())
    {
        getline(ifs,s);
        depts.push_back(new Department(s));
    }
    ifs.close();
    return depts;
}
