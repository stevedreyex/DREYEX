#include <fstream>
#include "Course.h"

Course::Course(string name, int credit, string description) {
	_name = name;
	_credit = credit;
	_description = description;
}

const string Course::getName() const { return _name;}
int Course::getNumOfCredits() const {return _credit;}
string Course::getDescription() const {return _description;}

vector<Course *> createCoursesFromFile(const char * fn)
{
    ifstream ifs(fn);
    vector<Course *> courses;
    
    string s;
    string name = "";
    int credit = 0;
    string des = "";

    while (!ifs.eof())
    {
		// get name
        getline(ifs, s, ',');
        name = s;
		// get credit
        getline(ifs, s, ',');
        credit = atoi(s.c_str()); 
		// get description
        getline(ifs, s);
        des = s;
          
        Course* c = new Course(name, credit, des);
        courses.push_back(c);    
    }
    ifs.close();
    
    return courses;
}
