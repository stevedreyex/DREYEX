#include "../src/dot.h"
#include "../src/vector.h"
#include <cmath>



TEST(InnerProduct, First) {
  int u[]={1, 0, 2};
  int v[]={1, 1, 3};
  ASSERT_EQ(7, dot(u, v, 3, 3));
}


TEST(InnerProduct, Second) {
  int u[]={1, 0, 2, 4};
  int v[]={1, 1, 3};
  ASSERT_ANY_THROW(dot(u, v, 4, 3));
}

TEST(InnerProduct, Vector) {
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  ASSERT_NEAR(1, x.at(1), epsilon);
  ASSERT_NEAR(0, x.at(2), epsilon);
  ASSERT_NEAR(2, x.at(3), epsilon);
  ASSERT_EQ(3, x.dim());
  ASSERT_EQ(7, dot(x,y));
}


TEST(VectorTest, Subtraction){
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  Vector z = x-y;
  ASSERT_NEAR(0, z.at(1), epsilon);
  ASSERT_NEAR(-1, z.at(2), epsilon);
  ASSERT_NEAR(-1, z.at(3), epsilon);
  ASSERT_EQ(3, z.dim());
}

TEST(VectorTest, Subtract)
{
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  x.subtract(y);
  ASSERT_NEAR(0, x.at(1), epsilon);
  ASSERT_NEAR(-1, x.at(2), epsilon);
  ASSERT_NEAR(-1, x.at(3), epsilon);
}

TEST(VectorTest, CopyAssignment)
    {
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  double c[]={0, 0, 0};
  Vector x(a, 3);
  Vector y(b, 3);
  Vector z(c, 3);
  (z = x = y).subtract(y);
  ASSERT_EQ(0, z.at(1));
  ASSERT_EQ(0, z.at(2));
  ASSERT_EQ(0, z.at(3));
  ASSERT_EQ(1, x.at(1));
  ASSERT_EQ(1, x.at(2));
  ASSERT_EQ(3, x.at(3));
}

TEST(VectorTest, distance)
{
  double a[]={1, 0, 2};
  double b[]={1, 1, 3};
  Vector x(a, 3);
  Vector y(b, 3);
  ASSERT_NEAR(sqrt(2), distance(x,y),epsilon );
}

TEST(VectorTest, TriangleArea)
{
  double a[]={1, 0};
  double b[]={1, 1};
  double c[]={0, 0};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  ASSERT_NEAR(0.5, area(x,y,z),epsilon);
}


TEST(VectorTest, PentagonArea){
  double a[]={0, 0};
  double b[]={2, 0};
  double c[]={2, 2};
  double d[]={1, 3};
  double e[]={0, 2};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector x(c, 2);
  Vector y(d, 2);
  Vector z(e, 2);
  Vector arr[] = {u, v, x, y, z};
  ASSERT_NEAR(5, area(arr, 5), epsilon);
}

TEST(VectorTest, TriangleArea2)
{
  double a[]={1, 0};
  double b[]={1, 1};
  double c[]={0, 0};
  Vector x(a, 2);
  Vector y(b, 2);
  Vector z(c, 2);
  Vector arr[] = {x, y, z};
  ASSERT_NEAR(0.5, area(arr, 3),epsilon);
}

TEST(VectorTest, OutputVector){
  double a[]={1, 0};
  Vector x(a, 2);
  ASSERT_EQ("(1, 0)", x.toString());
}

TEST(VectorTest, InputVector){
  std::string s = "(1, 0)";
  ASSERT_EQ(2, stripDecorators(s));
  ASSERT_EQ("1  0", s);

}

TEST(VectorTest, CreateVectorFromStringOfNumbers){
  std::string s = "(1, 0)";
  Vector v = createVectorFromStringOfNumbers(s);
  ASSERT_EQ(2, v.dim());
  ASSERT_EQ(1, v.at(1));
  ASSERT_EQ(0, v.at(2));
}
TEST(VectorTest, Centroid){
  double a[]={0, 0};
  double b[]={2, 0};
  double c[]={2, 2};
  double d[]={1, 3};
  double e[]={0, 2};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector x(c, 2);
  Vector y(d, 2);
  Vector z(e, 2);
  Vector arr[] = {u, v, x, y, z};
  Vector cent = centroid(arr, 5);
  ASSERT_NEAR(1, cent.at(1), epsilon);
  ASSERT_NEAR(7.0/5.0, cent.at(2), epsilon);
  ASSERT_EQ(2, cent.dim());
}

TEST(VectorTest, angle)
{
  double a[]={1, 0};
  double b[]={1, 1};
  Vector x(a, 2);
  Vector y(b, 2);
  ASSERT_NEAR(M_PI/4, angle(x, y) ,epsilon );
}

// TEST(VectorTest, angle2)
// {
//   double a[]={1, 0};
//   double b[]={1, 1};
//   Vector x(a, 2);
//   Vector y(b, 2);
//   ASSERT_NEAR(3*M_PI/4, angle(y, x) ,epsilon );
// }
