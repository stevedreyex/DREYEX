#include <gtest/gtest.h>
#include "../src/test_string.h"
int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}
///string::length
TEST(String, Length) 
{
  string s = "This is an apple";
  ASSERT_EQ(16, string_length(s));
}
///string::empty
TEST(String, Empty)
{
string s = "This is also an apple";
ASSERT_EQ(0, string_empty(s));
}
///string::clear
TEST(String, Clear)
{
  string s = "This is still an apple";
  ASSERT_EQ("", string_clear(s));
}
///string::insert
TEST(String, Insert)
{
  std::string str="to be question";
  std::string str2="the ";
  std::string str3="or not to be";
  std::string::iterator it;

  // used in the same order as described above:
  string str_v1 = string_insert(str, 6,str2);                 // to be (the )question
  string str_v2 = string_insert(str_v1, 6,str3,3,4);             // to be (not )the question
  string str_v3 = string_insert(str_v2,10,"that is cool",8);    // to be not (that is )the question
  string str_v4 = string_insert(str_v3,10,"to be ");            // to be not (to be )that is the question
  string str_v5 = string_insert(str_v4,15,1,':');               // to be not to be(:) that is the question
  ASSERT_EQ("to be not to be: that is the question", str_v5);
}
//string::copy
TEST(String, Copy)
{
  string str = "Apfel ist sehr lecker.";
  char ch[20] = "/0";
  ASSERT_EQ("Apfel",string_copy(str,ch, 5, 0));
}
///string::compare
TEST(String, Compare_1)
{
  string str1 = ("green apple");
  string str2 = ("red apple");
  int result = string_compare(str1,str2);
  ASSERT_NE(0, result);
}

TEST(String, Compare_2)
{
  string str1 = ("green apple");
  string str2 = ("red apple");
  int result = string_compare(str1,6, 5,"apple");
  ASSERT_EQ(0, result);
}
///string::swap
TEST(String, Swap)
{
  string a = "Apple";
  string b = "Banana";
  ASSERT_EQ("Banana", string_swap(a,b));
}
// ///string::find_1
TEST(String, Find_1)
{
  string a = "This is an apple";
  ASSERT_EQ(8, string_find(a,"an"));
}
// ///string::find_2
TEST(String, Find_2)
{
  string a = "This is an apple";
  ASSERT_ANY_THROW(string_find(a,"not"));
}