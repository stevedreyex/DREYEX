#include "TestHarness.h"
#include <iostream>
#include "Student.h"
#include "Department.h"
#include "Course.h"
#include "CourseOffering.h"


#define CUS_EQUAL(expected,actual) { CHECK_EQUAL(StringFrom((expected)), StringFrom((actual))); }

// ±NstringÂà¬°SimpleString 
SimpleString StringFrom(string s)
{
	return SimpleString(s.c_str());
}


SimpleString StringFrom (int value)
{
	char buffer [256];
	sprintf (buffer, "%d", value);
	return SimpleString(buffer);
}

using namespace std;


TEST( Student, creation )
{
      Student a("Mick Jagger");
      CUS_EQUAL("Mick Jagger", a.getName());
}

TEST( Student, setDept )
{
      Student a("Mick Jagger");
      Department d("Music");
      a.setDepartment(&d);
      CUS_EQUAL("Music", a.getDepartment()->getName());
}

TEST( Department, creation )
{
      Department d("Music");
      CUS_EQUAL("Music", d.getName());
}

TEST( Department, addStudent )
{
      Student a("Mick Jagger");
      Department d("Music");
      d.addStudent(&a);
      
      CUS_EQUAL("Mick Jagger", d.getStudent()->getName());      
      CUS_EQUAL("Music",a.getDepartment()->getName());
      CHECK_EQUAL(&a, d.getStudent());
      CHECK_EQUAL(&d, a.getDepartment());
}

TEST( Department, numberOfStudents )
{
      Student a("Mick Jagger");
      Department d("Music");
      d.addStudent(&a);
      Student b("Jeff Beck");
      d.addStudent(&b);
      CHECK (2 == d.numberOfStudents());
}

TEST( Course, creation )
{
      Course c("OOP",3,"Introduction to object-oriented programming...");
      CHECK (3 == c.getNumOfCredits());     
}

TEST(CourseOffering, addStudent)
{
      Student a("M. Jackson");
      
      Course oop("OOP",3,"Introduction to object-oriented programming...");
      Course ds("Data Structures",3,"Introduction to data structures...");
      Department cs("Computer Science");
      cs.addStudent(&a);

      CourseOffering cs_oop (&cs, &oop, "2009F");
      CourseOffering cs_ds (&cs, &ds, "2009F");
      cs_oop.addStudent(&a);
      cs_ds.addStudent(&a);
      CHECK(1 == cs_oop.numberOfStudent());
      CHECK(1 == cs_ds.numberOfStudent());
      CHECK(2 == cs.numberOfCourses());      
}

TEST(CourseOffering, queryStudent)
{
      Student a("M. Jackson");
      Student b("Mick Jagger");
      Course oop("OOP",3,"Introduction to object-oriented programming...");
      Course ds("Data Structures",3,"Introduction to data structures...");
      Department cs("Computer Science");
      Department m("Music");
      cs.addStudent(&a);
      m.addStudent(&b);

      CourseOffering cs_oop (&cs, &oop, "2009F");
      cs_oop.addStudent(&a);
      cs_oop.addStudent(&b);
      CHECK(2 == cs_oop.numberOfStudent());
      CHECK(1 == cs_oop.numberOfInDeptStudent());
      vector <Student *> students = cs_oop.getStudents();
      CUS_EQUAL("M. Jackson", students[0]->getName() );
      CUS_EQUAL("Mick Jagger", students[1]->getName() );
}

TEST (Department, fileIO)
{
     vector<Department *> depts = createDepartmentsFromFile("department-hw8.txt");
     CHECK(3 == depts.size());
     CUS_EQUAL("Computer Science",depts[0]->getName());
     CUS_EQUAL("Music",depts[1]->getName());
     CUS_EQUAL("History",depts[2]->getName());
}

TEST(Student, fileIO)
{
     vector<Department *> depts = createDepartmentsFromFile("department-hw8.txt");
     vector<Student *> students = createStudentsFromFile("student-hw8.txt", depts);
     
     // check the students data
     CHECK (5 == students.size());
	 CHECK (students[0] == depts[0]->getStudentByName("Michael Jackson"));
	 CHECK (students[1] == depts[0]->getStudentByName("Bon Jovi"));
	 CHECK (students[2] == depts[0]->getStudentByName("Mariah Carey"));
	 CHECK (students[3] == depts[1]->getStudentByName("Mick Jagger"));
	 CHECK (students[4] == depts[2]->getStudentByName("Avril Lavigne"));
	 
     
     // check student data in department
	 CHECK (3 == depts[0]->numberOfStudents());
     CHECK (depts[0] == students[0]->getDepartment());
     CHECK (depts[0] == students[1]->getDepartment());
     CHECK (depts[0] == students[2]->getDepartment());
     
     CHECK (1 == depts[1]->numberOfStudents());     
     CHECK (depts[1] == students[3]->getDepartment());
     
     CHECK (1 == depts[2]->numberOfStudents());     
     CHECK (depts[2] == students[4]->getDepartment());
     
}

TEST(Course, fileIO)
{
     vector<Course *> courses = createCoursesFromFile("course-hw8.txt");
     
     CHECK (5 == courses.size());
     
	 CUS_EQUAL ("OOP", courses[0]->getName());
	 CUS_EQUAL ("Data Structures", courses[1]->getName());
	 CUS_EQUAL ("Voice", courses[2]->getName());
	 CUS_EQUAL ("Opera", courses[3]->getName());
	 CUS_EQUAL ("World History", courses[4]->getName());
     
	 CHECK (3 == courses[0]->getNumOfCredits());
	 CHECK (2 == courses[1]->getNumOfCredits());
	 CHECK (1 == courses[2]->getNumOfCredits());
	 CHECK (3 == courses[3]->getNumOfCredits());
	 CHECK (4 == courses[4]->getNumOfCredits());

	 CUS_EQUAL ("Introduction to object-oriented programming...", courses[0]->getDescription());
	 CUS_EQUAL ("Introduction to data structures...", courses[1]->getDescription());
	 CUS_EQUAL ("Introduction to vocal music...", courses[2]->getDescription());
	 CUS_EQUAL ("Introduction to opera music...", courses[3]->getDescription());
	 CUS_EQUAL ("Introduction to world history...", courses[4]->getDescription());
}

TEST(CourseOffering, fileIO)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw8.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw8.txt");
    vector<Student *> students = createStudentsFromFile("student-hw8.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw8.txt", depts, courses, students);
    
	CHECK (5 == courseOfferings.size());

    CHECK (depts[0] == courseOfferings[0]->getDepartment());
    CHECK (depts[0] == courseOfferings[1]->getDepartment());
    CHECK (depts[1] == courseOfferings[2]->getDepartment());
    CHECK (depts[1] == courseOfferings[3]->getDepartment());
    CHECK (depts[2] == courseOfferings[4]->getDepartment());
    
    CHECK (courses[0] == courseOfferings[0]->getCourse());
    CHECK (courses[1] == courseOfferings[1]->getCourse());
    CHECK (courses[2] == courseOfferings[2]->getCourse());
    CHECK (courses[3] == courseOfferings[3]->getCourse());
    CHECK (courses[4] == courseOfferings[4]->getCourse());

	CUS_EQUAL ("2009F", courseOfferings[0]->getSemester());
	CUS_EQUAL ("2010S", courseOfferings[1]->getSemester());
	CUS_EQUAL ("2009F", courseOfferings[2]->getSemester());
	CUS_EQUAL ("2010S", courseOfferings[3]->getSemester());
	CUS_EQUAL ("2010S", courseOfferings[4]->getSemester());
	
	// Check the student data in course-offering
	vector<Student *> s_in_course = courseOfferings[0]->getStudents();
	CHECK (3 == s_in_course.size());	
    CHECK (students[0] == s_in_course[0]);
    CHECK (students[2] == s_in_course[1]);
    CHECK (students[3] == s_in_course[2]);
    
   	s_in_course = courseOfferings[1]->getStudents();
	CHECK (3 == s_in_course.size());	
	CHECK (students[0] == s_in_course[0]);
    CHECK (students[1] == s_in_course[1]);
    CHECK (students[2] == s_in_course[2]);
    
    s_in_course = courseOfferings[2]->getStudents();
	CHECK (2 == s_in_course.size());	
	CHECK (students[1] == s_in_course[0]);
    CHECK (students[3] == s_in_course[1]);
    
    s_in_course = courseOfferings[3]->getStudents();
	CHECK (2 == s_in_course.size());	
	CHECK (students[1] == s_in_course[0]);
    CHECK (students[3] == s_in_course[1]);
    
    s_in_course = courseOfferings[4]->getStudents();
	CHECK (3 == s_in_course.size());	
	CHECK (students[2] == s_in_course[0]);
    CHECK (students[3] == s_in_course[1]);
    CHECK (students[4] == s_in_course[2]);
}

// Courses offered by Computer Science in the semester 2009F
TEST(CourseOffering, query1)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw8.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw8.txt");
    vector<Student *> students = createStudentsFromFile("student-hw8.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw8.txt", depts, courses, students);
	
	vector<Course *> c_cs_2009f;
	for(int i = 0; i < courseOfferings.size(); i++)
	{
		// course-offerings offered by department of Computer Science
		if (courseOfferings[i]->getDepartment() == depts[0])
		{
			// course-offerings offered in the semester 2009F
			if (courseOfferings[i]->getSemester() == "2009F")
				c_cs_2009f.push_back(courseOfferings[i]->getCourse());
		}
	}
	
	CHECK (1 == c_cs_2009f.size());
	CHECK (courses[0] == c_cs_2009f[0]);

}

// Number of Computer Science students in the OOP class
TEST(CourseOffering, query2)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw8.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw8.txt");
    vector<Student *> students = createStudentsFromFile("student-hw8.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw8.txt", depts, courses, students);
	
	int num_st_oop = 0;
	for(int i = 0; i < courseOfferings.size(); i++)
	{
		// OOP class
		if (courseOfferings[i]->getCourse() == courses[0])
		{
			// number of in-department student
			num_st_oop = courseOfferings[i]->numberOfInDeptStudent();
		}
	}
	
	CHECK (2 == num_st_oop);
}

// Number of Music students in the OOP class
TEST(CourseOffering, query3)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw8.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw8.txt");
    vector<Student *> students = createStudentsFromFile("student-hw8.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw8.txt", depts, courses, students);
	
	int num_music_oop = 0;
	for(int i = 0; i < courseOfferings.size(); i++)
	{
		// OOP class
		if (courseOfferings[i]->getCourse() == courses[0])
		{
			// students in OOP class
			for (int j = 0; j < courseOfferings[i]->getStudents().size(); j++)
			{
				Student* s = courseOfferings[i]->getStudents()[j];
				// count the Music students
				if (s->getDepartment() == depts[1])
					num_music_oop++;
			}
		}
	}
	
	CHECK (1 == num_music_oop);
}

// Number of Out-of-department students in the Data Structures class
TEST(CourseOffering, query4)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw8.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw8.txt");
    vector<Student *> students = createStudentsFromFile("student-hw8.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw8.txt", depts, courses, students);
	
	int num_st_oop = 0;
	for(int i = 0; i < courseOfferings.size(); i++)
	{
		// Data Structures class
		if (courseOfferings[i]->getCourse() == courses[1])
		{
			// caculate the number of Out-of-department students
			num_st_oop = courseOfferings[i]->numberOfStudent() - courseOfferings[i]->numberOfInDeptStudent();
		}
	}
	
	CHECK (0 == num_st_oop);
}

// Number of credits signed up by a particular student
// Mick Jagger
TEST(CourseOffering, query5)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw8.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw8.txt");
    vector<Student *> students = createStudentsFromFile("student-hw8.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw8.txt", depts, courses, students);
	
	int num_cd = 0;
	// courses signed up by Mick Jagger
	vector<CourseOffering*> MJ_courses = students[3]->getCourses();
	
	for(int i = 0; i < MJ_courses.size(); i++)
	{
		// count the credit
		num_cd = num_cd + MJ_courses[i]->getCourse()->getNumOfCredits();
	}
	
	CHECK (11 == num_cd);
}

TEST(CourseOffering, scoreFromFile)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw9.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw9.txt");
    vector<Student *> students = createStudentsFromFile("student-hw9.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw9.txt", depts, courses, students);
	setScoreFromFile("course-scoring-hw9.txt", courseOfferings);

	CUS_EQUAL(60, courseOfferings[0]->getScore("Michael Jackson"));
	CUS_EQUAL(70, courseOfferings[0]->getScore("Mariah Carey"));
	CUS_EQUAL(75, courseOfferings[0]->getScore("Mick Jagger"));

	CUS_EQUAL(80, courseOfferings[1]->getScore("Michael Jackson"));
	CUS_EQUAL(40, courseOfferings[1]->getScore("Bon Jovi"));
	CUS_EQUAL(65, courseOfferings[1]->getScore("Mariah Carey"));
	
	CUS_EQUAL(68, courseOfferings[2]->getScore("Bon Jovi"));
	CUS_EQUAL(74, courseOfferings[2]->getScore("Mick Jagger"));
	
	CUS_EQUAL(86, courseOfferings[3]->getScore("Bon Jovi"));
	CUS_EQUAL(49, courseOfferings[3]->getScore("Mick Jagger"));

	CUS_EQUAL(76, courseOfferings[4]->getScore("Mariah Carey"));
	CUS_EQUAL(64, courseOfferings[4]->getScore("Mick Jagger"));
	CUS_EQUAL(77, courseOfferings[4]->getScore("Avril Lavigne"));
}

TEST(Student, getEarnedCredits)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw9.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw9.txt");
    vector<Student *> students = createStudentsFromFile("student-hw9.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw9.txt", depts, courses, students);
	setScoreFromFile("course-scoring-hw9.txt", courseOfferings);

	CUS_EQUAL(5, students[0]->getEarnedCredits());
	CUS_EQUAL(4, students[1]->getEarnedCredits());
	CUS_EQUAL(7, students[2]->getEarnedCredits());
	CUS_EQUAL(4, students[3]->getEarnedCredits());
	CUS_EQUAL(4, students[4]->getEarnedCredits());
}

TEST(Student, isThesisApproved)
{
	GraduateStudent student1("Michael Jackson");
	GraduateStudent student2("Bon Jovi");
	GraduateStudent student3("Mick Jagger");

	student1.setThesisApproved();
	student3.setThesisApproved();	

	CUS_EQUAL(true, student1.isThesisApproved());
	CUS_EQUAL(false, student2.isThesisApproved());
	CUS_EQUAL(true, student3.isThesisApproved());
}

TEST(Student, checkGraduation)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw9.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw9.txt");
    vector<Student *> students = createStudentsFromFile("student-hw9.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw9.txt", depts, courses, students);
	setScoreFromFile("course-scoring-hw9.txt", courseOfferings);

	students[0]->setGraduationCredits(5);
	students[1]->setGraduationCredits(5);
	students[2]->setGraduationCredits(3);
	students[3]->setGraduationCredits(3);
	students[4]->setGraduationCredits(3);

	((GraduateStudent *)students[2])->setThesisApproved();
	((GraduateStudent *)students[4])->setThesisApproved();	

	CUS_EQUAL(true, students[0]->checkGraduation());
	CUS_EQUAL(false, students[1]->checkGraduation());
	CUS_EQUAL(true, students[2]->checkGraduation());
	CUS_EQUAL(false, students[3]->checkGraduation());
	CUS_EQUAL(true, students[4]->checkGraduation());
}

TEST(Student, getScoreAverage)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw9.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw9.txt");
    vector<Student *> students = createStudentsFromFile("student-hw9.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw9.txt", depts, courses, students);
	setScoreFromFile("course-scoring-hw9.txt", courseOfferings);
	
	DOUBLES_EQUAL(70.0, students[0]->getScoreAverage(), 0.1);
	DOUBLES_EQUAL(64.6, students[1]->getScoreAverage(), 0.1);
	DOUBLES_EQUAL(70.3, students[2]->getScoreAverage(), 0.1);
	DOUBLES_EQUAL(65.5, students[3]->getScoreAverage(), 0.1);
	DOUBLES_EQUAL(77.0, students[4]->getScoreAverage(), 0.1);
	
}

TEST(Student, getDepRank)
{
	vector<Department *> depts = createDepartmentsFromFile("department-hw9.txt");
	vector<Course *> courses = createCoursesFromFile("course-hw9.txt");
    vector<Student *> students = createStudentsFromFile("student-hw9.txt", depts);
	vector<CourseOffering *> courseOfferings = createCourseOfferingsFromFile("course-offering-hw9.txt", depts, courses, students);
	setScoreFromFile("course-scoring-hw9.txt", courseOfferings);
	
	CUS_EQUAL(1, students[0]->getDepRank());
	CUS_EQUAL(2, students[1]->getDepRank());
	CUS_EQUAL(1, students[2]->getDepRank());
	CUS_EQUAL(1, students[3]->getDepRank());
	CUS_EQUAL(1, students[4]->getDepRank());

}
