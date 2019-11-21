#include<gtest/gtest.h>
#include"../src/binary.h"
#include"../src/bin_calc.h"
#define EPSILON 0.0001
TEST(Binary, CreateBinary)
{
  int a[] = {0,0,0,0,0,0,0,1};
  Binary u(a, 8);
  ASSERT_EQ(u.at(1), 1);
}
TEST(Binary, BinaryToDecimal)
{
  int a[] = {0,1,0,1,1,0,0,1};
  Binary u(a, 8);
  ASSERT_EQ(u.BinaryToDecimal(), 89);
}
TEST(Binary, DecimalToBinary)
{
  int num = 89;
  Binary u = Binary(num);
  ASSERT_EQ(u.output(), "1011001");
}
TEST(Binary, NumberOfBit)
{
  int a[] = {0,1,0,1,1,0,0,1};
  Binary u(a, 8);
  ASSERT_EQ(8, u.numbersOfBit());
}
// TEST(Binary, add)
// {
//   Binary v(20);
//   Binary u(89);
//   ASSERT_EQ(109, u.add(v));
// }
// TEST(Binary, subtract)
// {
//   Binary v(20);
//   Binary u(89);
//   ASSERT_EQ(69, u.subtract(v));
// }
// TEST(Binary, plus1)
// {
//   Binary v(20);
//   Binary u(89);
//   Binary x = u + v;
//   ASSERT_EQ(x.BinaryToDecimal(), 109);
// }
TEST(Binary, plus2)
{
  Binary v(20);
  Binary u(89);
  Binary x = u + v;
  ASSERT_EQ(x.output(), "1101101");
}
// TEST(Binary, minus1)
// {
//   Binary v(20);
//   Binary u(89);
//   Binary x = u - v;
//   ASSERT_EQ(x.BinaryToDecimal(), 69);
// }
TEST(Binary, minus2)
{
  Binary v(20);
  Binary u(89);
  Binary x = u - v;
  ASSERT_EQ(x.output(), "1000101");
}
