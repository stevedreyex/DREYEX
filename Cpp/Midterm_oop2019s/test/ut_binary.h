#include<gtest/gtest.h>
#include"../src/binary.h"
#define EPSILON 0.0001
using namespace std;

TEST(Binary, CreateBinary1)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  ASSERT_EQ(u.at(1), 1);
  ASSERT_EQ(u.at(2), 0);
  ASSERT_EQ(u.at(3), 1);
  ASSERT_EQ(u.at(4), 1);
}

TEST(Binary, CreateBinary2)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  Binary v(u);
  ASSERT_EQ(v.at(1), 1);
  ASSERT_EQ(v.at(2), 0);
  ASSERT_EQ(v.at(3), 1);
  ASSERT_EQ(v.at(4), 1);
}

TEST(Binary, ToInt)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  ASSERT_EQ(u.toInt(), 13);
}

TEST(Binary, ToInt_throw)
{
  Binary u;
  ASSERT_ANY_THROW(u.toInt());
}

TEST(Binary, add)
{
  int a[] = {1,1,0,1};
  int b[] = {1};
  Binary u(a, 4);
  Binary v(b, 1);
  Binary x;
  x = u + v;
  string str = "1110";
  ASSERT_EQ(x.toString(), str);
  // ASSERT_EQ(x.at(1), 0);
  // ASSERT_EQ(x.at(2), 1);
  // ASSERT_EQ(x.at(3), 1);
  // ASSERT_EQ(x.at(4), 1);
}

TEST(Binary, add_throw1)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  Binary v;
  ASSERT_ANY_THROW(v+u);
}

TEST(Binary, add_throw2)
{
  int a[] = {1,1,0,1};
  Binary v(a, 4);
  Binary u;
  ASSERT_ANY_THROW(v+u);
}

TEST(Binary, subtract)
{
  int a[] = {1,1,0,1};
  int b[] = {1};
  Binary u(a, 4);
  Binary v(b, 1);
  Binary x;
  x = (u - v);
  string str = "1100";
  ASSERT_EQ(x.toString(), str);
  // ASSERT_EQ(x.at(1), 0);
  // ASSERT_EQ(x.at(2), 0);
  // ASSERT_EQ(x.at(3), 1);
  // ASSERT_EQ(x.at(4), 1);
}

TEST(Binary, subtract_throw1)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  Binary v;
  ASSERT_ANY_THROW(v-u);
}

TEST(Binary, subtract_throw2)
{
  int a[] = {1,1,0,1};
  Binary v(a, 4);
  Binary u;
  ASSERT_ANY_THROW(v-u);
}

TEST(Binary, subtract_throw3)
{
  int a[] = {1,1,0,1};
  int b[] = {1};
  Binary u(a, 4);
  Binary v(b, 1);
  ASSERT_ANY_THROW((v - u));
  // ASSERT_EQ((v-u).toInt, 0);
  // ASSERT_EQ(x.at(2), 0);
  // ASSERT_EQ(x.at(3), 1);
  // ASSERT_EQ(x.at(4), 1);
}

TEST(Binary, equal)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  Binary v = u;
  ASSERT_EQ(v.at(1), 1);
  ASSERT_EQ(v.at(2), 0);
  ASSERT_EQ(v.at(3), 1);
  ASSERT_EQ(v.at(4), 1);
}

TEST(Binary, equal_throw)
{
  Binary u;
  Binary v;
  ASSERT_ANY_THROW(v=u);
}

TEST(Binary, Tostring)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  string str = "1101";
  ASSERT_EQ(u.toString(), str);
}

TEST(Binary, ToString_throw)
{
  Binary u;
  ASSERT_ANY_THROW(u.toString());
}

TEST(Binary, SetBit)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  u.setBit(2, 1);
  string str = "1111";
  ASSERT_EQ(u.toString(), str);
}

TEST(Binary, SetBit_throw1)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  ASSERT_ANY_THROW(u.setBit(100, 1));
}

TEST(Binary, SetBit_throw2)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  ASSERT_ANY_THROW(u.setBit(2, 5));
}

TEST(Binary, Resize)
{
  int a[] = {1,1,0,1};
  Binary u(a, 4);
  u.resize(8);
  string str = "00001101";
  ASSERT_EQ(u.toString(), str);
}

TEST(Binary, Resize_throw)
{
  Binary u;
  ASSERT_ANY_THROW(u.resize(8));
}

TEST(Binary, move_to_left)
{
  int a[] = {0,0,0,0,1,1,0,1};
  Binary u(a, 8);
  Binary v = u<<4;
  string str = "11010000";
  ASSERT_EQ(v.toString(), str);
}

TEST(Binary, move_to_right)
{
  int a[] = {1,1,0,1,0,0,0,0};
  Binary u(a, 8);
  Binary v = u>>4;
  v.resize(8);
  string str = "00001101";
  ASSERT_EQ(v.toString(), str);
}
