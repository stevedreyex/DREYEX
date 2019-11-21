#include <string>
#include <iostream>
#include <map>
using namespace std;

TEST(mapping, create_map)
{
  map<string, string> classmate;
  classmate["Tony"] = "stark";
  ASSERT_EQ("stark", classmate["Tony"]);
}

TEST(mapping, find_and_insert)
{
  map<string, string> classmate;
  //insert
  classmate.insert(pair<string, string>("Tony", "apple fan"));
  classmate.insert(pair<string, string>("Jeffrey", "handsome man"));
//find
  auto iter = classmate.find("Jeffrey")->second;
  ASSERT_EQ("handsome man", iter);
}

TEST(mapping, insert_exception)
{
  map<string, string> classmate;
  classmate["Tony"] = "Stark";
  classmate.insert(pair<string, string>("Tony", "apple_fan"));
  //You can't insert when it was initialized.
  ASSERT_NE("apple_fan", classmate["Tony"]);
}

TEST(mapping, delete_1)
{
  map<string, string> classmate;
  classmate["Tony"] = "Stark";
//find
  auto iter = classmate.find("Tony")->second;
  classmate.erase(iter);
  classmate["Tony"] = "apple_fan";
  ASSERT_EQ("apple_fan", classmate["Tony"]);
}

TEST(mapping, delete_2)
{
  map<string, string> classmate;
  classmate["Tony"] = "Stark";
  int n = classmate.erase("Tony");
  ASSERT_EQ(1, n);
}
