#include<gtest/gtest.h>
#include"../src/vector.h"
#include"../src/dot.h"
#define EPSILON 0.0001

TEST(Vector, set_centroid)
{
  double a[] = {0, 0};
  double b[] = {2, 0};
  double c[] = {2, 4};
  double d[] = {1, 8};
  double e[] = {0, 4};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector x(c, 2);
  Vector y(d, 2);
  Vector z(e, 2);
  Vector arr[] = {u, v, x, y, z};
  Vector center = centroid(arr, 5);
  ASSERT_NEAR(1, center.at(1), EPSILON);
  ASSERT_NEAR(16.0/5.0, center.at(2), EPSILON);
}

TEST(Vector, polygon_area)
{
    double a[] = {0, 0};
    double b[] = {2, 0};
    double c[] = {2, 4};
    double d[] = {1, 8};
    double e[] = {0, 4};
    Vector u(a, 2);
    Vector v(b, 2);
    Vector x(c, 2);
    Vector y(d, 2);
    Vector z(e, 2);
    Vector arr[] = {u, v, x, y, z};
    ASSERT_NEAR(12, area(arr, 5), EPSILON);
}

TEST(Vector, perimeter)
{
    double a[] = {0, 0, 0};
    double b[] = {0, 2, 0};
    double c[] = {2, 2, 0};
    double d[] = {2, 0, 0};
    Vector w(a, 3);
    Vector x(b, 3);
    Vector y(c, 3);
    Vector z(d, 3);
    Vector arr[] = {w, x, y, z};
    ASSERT_NEAR(8, perimeter(arr, 4), EPSILON);
}

TEST(Dot, cross)
{
  double a[] = {3, 0};
  double b[] = {0, 3};
  Vector u(a, 2);
  Vector v(b, 2);
  ASSERT_NEAR(9, dim2_cross(u, v), EPSILON);
}

TEST(Vector, dot) {
  double a[] = {3, 0};
  double b[] = {3, 3};
  Vector u(a, 2);
  Vector v(b, 2);
  ASSERT_EQ(9, dot(u, v));
}

TEST(Vector, dot_exception) {
  double a[] = {3, 0, 2};
  double b[] = {3, 3};
  Vector u(a, 3);
  Vector v(b, 2);
  ASSERT_ANY_THROW(dot(u, v));
}

TEST(dot, Angle1) {
  double a[] = {3, 0};
  double b[] = {3, 3};
  Vector u(a, 2);
  Vector v(b, 2);
  ASSERT_NEAR(M_PI/4, angle(u, v), EPSILON);
}

TEST(dot, Angle2) {
  double a[] = {3, 0};
  double b[] = {3, -3};
  Vector u(a, 2);
  Vector v(b, 2);
  ASSERT_NEAR(-7*M_PI/4, angle(u, v), EPSILON);
}

TEST(dot, Angle_exception) {
  double a[] = {0, 0};
  double b[] = {3, -3};
  Vector u(a, 2);
  Vector v(b, 2);
  ASSERT_ANY_THROW(angle(u, v));
}

TEST(dot, move_centroid_to_zero)
{
  double a[] = {0, 0};
  double b[] = {2, 0};
  double c[] = {2, 4};
  double d[] = {1, 8};
  double e[] = {0, 4};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector x(c, 2);
  Vector y(d, 2);
  Vector z(e, 2);
  Vector arr[] = {u, v, x, y, z};
  move_centroid_to_zero(arr, 5);
//centroid = (1.0, 3.2)
  ASSERT_NEAR(-1.0, arr[0].at(1), EPSILON);
  ASSERT_NEAR(1, arr[1].at(1), EPSILON);
  ASSERT_NEAR(1, arr[2].at(1), EPSILON);
  ASSERT_NEAR(0, arr[3].at(1), EPSILON);
  ASSERT_NEAR(-1, arr[4].at(1), EPSILON);
  ASSERT_NEAR(-3.2, arr[0].at(2), EPSILON);
  ASSERT_NEAR(-3.2, arr[1].at(2), EPSILON);
  ASSERT_NEAR(0.8, arr[2].at(2), EPSILON);
  ASSERT_NEAR(4.8, arr[3].at(2), EPSILON);
  ASSERT_NEAR(0.8, arr[4].at(2), EPSILON);
}

TEST(dot, convex_polygon_area)
{
    double a[] = {0, 0};
    double b[] = {2, 0};
    double c[] = {2, 4};
    double d[] = {1, 8};
    double e[] = {0, 4};
    Vector u(a, 2);
    Vector v(c, 2);
    Vector x(d, 2);
    Vector y(b, 2);
    Vector z(e, 2);
    Vector arr[] = {u, v, x, y, z};
    ASSERT_NEAR(12, convexPolygonArea(arr, 5), EPSILON);
}
