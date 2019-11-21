#ifndef STUDENT_FACTORY_H
#define STUDENT_FACTORY_H
#include <string>
#include "Student.h"

using namespace std;

class StudentFactory {
public:
	// Todo
	Student * createStudent(string type, string name)
	{
		return new Student("");
	}
};

#endif
