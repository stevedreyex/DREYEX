#include "../src/student.h"
#include <string>
using namespace std;

// class StudentTest: public ::testing::Test
// {
// protected:
//   // fixture setup
//   void SetUp()
//   {
//     s1 = new Undergrad(id_1, name_1);
//     s2 = new Undergrad(id_2, name_2);
//   }
//
//   // fixture teardown
//   void TearDown()
//   {
//     delete s1;
//     delete s2;
//   }
//   // test data in fixture
//   string id_1 = "107820005";
//   string name_1 = "Stefan";
//   string id_2 = "107820016";
//   string name_2 = "Tony";
//
//   Student * s1;
//   Student * s2;
// };


TEST(StudentTest, Undergrad)
{
  string id_1 = "107820005";
  string name_1 = "Stefan";
  Undergrad s1(id_1, name_1);
  ASSERT_EQ(s1.id(), "107820005");
  ASSERT_EQ(s1.name(), "Stefan");
}


TEST(StudentTest, Grad)
{
  string id_2 = "107820016";
  string name_2 = "Tony";
  Grad s2(id_2, name_2);
  ASSERT_EQ(s2.id(), "107820016");
  ASSERT_EQ(s2.name(), "Tony");
}

TEST(StudentTest, Students)
{
  string id_1 = "107820005";
  string name_1 = "Stefan";
  // string id_2 = "107820016";
  // string name_2 = "Tony";
  // Grad s2(id_2, name_2);
  // Student * _s1 = new Undergrad(id_1, name_1);
  Student * _s1 = new Undergrad(id_1, name_1);
  ASSERT_EQ(_s1->id(), "107820005");
  ASSERT_EQ(_s1->name(), "Stefan");
}

// TEST(Student, Cant_be_same)
// {
//
// }
//
TEST(CourseTest, Course)
{
  string crs_id_1 = "1223";
  string crs_name_1 = "OOPS";
  Course a(crs_id_1, crs_name_1);
  ASSERT_EQ(a.id(), "1223");
  ASSERT_EQ(a.name(), "OOPS");
}

TEST(CourseTest, Members_and_size)
{
  //course
  string crs_id_1 = "1223";
  string crs_name_1 = "OOPS";
  Course a(crs_id_1, crs_name_1);
  //member
  string id_1 = "107820005";
  string name_1 = "Stefan";
  Student * s1 = new Undergrad(id_1, name_1);
  //add
  a.add(s1);
  ASSERT_EQ(a.size(), 1);
}

TEST(CourseTest, Add_more_than_1_students)
{
  string crs_id_1 = "1223";
  string crs_name_1 = "OOPS";
  Course a(crs_id_1, crs_name_1);
  //member
  string id_1 = "107820005";
  string name_1 = "Stefan";
  Student * s1 = new Undergrad(id_1, name_1);

  string id_2 = "107820016";
  string name_2 = "Tony";
  Student * s2 = new Undergrad(id_2, name_2);
  Student * _s[] = {s1, s2};
  a.add(_s, _s+2);
  ASSERT_EQ(a.size(), 2);

}

TEST(CourseTest, Get_students_by_name_inc)
{
    string crs_id_1 = "1223";
    string crs_name_1 = "OOPS";
    Course a(crs_id_1, crs_name_1);
    //member
    string id_1 = "107820005";
    string name_1 = "Stefan";
    Student * s1 = new Undergrad(id_1, name_1);

    string id_2 = "107820016";
    string name_2 = "Tony";
    Student * s2 = new Undergrad(id_2, name_2);

    string id_3 = "107820007";
    string name_3 = "Jeffrey";
    Student * s3 = new Undergrad(id_3, name_3);
    Student * _s[] = {s1, s2, s3};
    a.add(_s, _s+3);
    a.getStudentsByNameInc();
    ASSERT_EQ(a.mem_at(0), "Jeffrey");
    ASSERT_EQ(a.mem_at(1), "Stefan");
    ASSERT_EQ(a.mem_at(2), "Tony");
}

TEST(CourseTest, at_exception)
{
    string crs_id_1 = "1223";
    string crs_name_1 = "OOPS";
    Course a(crs_id_1, crs_name_1);
    //member
    string id_1 = "107820005";
    string name_1 = "Stefan";
    Student * s1 = new Undergrad(id_1, name_1);

    string id_2 = "107820016";
    string name_2 = "Tony";
    Student * s2 = new Undergrad(id_2, name_2);

    string id_3 = "107820007";
    string name_3 = "Jeffrey";
    Student * s3 = new Undergrad(id_3, name_3);
    Student * _s[] = {s1, s2, s3};
    a.add(_s, _s+3);
    ASSERT_ANY_THROW(a.mem_at(4));
}

TEST(CourseTest, set_score)
{
    string crs_id_1 = "1223";
    string crs_name_1 = "OOPS";
    Course a(crs_id_1, crs_name_1);
    //member
    string id_1 = "107820005";
    string name_1 = "Stefan";
    Student * s1 = new Undergrad(id_1, name_1);

    string id_2 = "107820016";
    string name_2 = "Tony";
    Student * s2 = new Undergrad(id_2, name_2);

    string id_3 = "107820007";
    string name_3 = "Jeffrey";
    Student * s3 = new Undergrad(id_3, name_3);
    vector<int> score;
    vector<string> ids;
    Student * _s[] = {s1, s2, s3};
    a.add(_s, _s+3);
    score.push_back(99);
    score.push_back(88);
    score.push_back(77);
    ids.push_back(s2->id());
    ids.push_back(s1->id());
    ids.push_back(s3->id());
    a.setScores(ids, score);
    // ASSERT_EQ(99, a.get_student().getScore());
}
