#include<gtest/gtest.h>
#include"../src/vector.h"
double EPSILON = 0.0001;

TEST(Vector, at_throw_1)
{
    double a[] = {1,2, 3};
    Vector x(a, 2);
    ASSERT_ANY_THROW(x.at(4));
}
TEST(Vector, at_throw_2)
{
    double a[] = {1,2, 3};
    Vector x(a, 2);
    ASSERT_ANY_THROW(x.at(-1));
}
TEST(Vector, minus_operator)
{
    double a[] = {1,2, 3};
    double b[] = {3,4, 5};
    Vector x(a, 3);
    Vector y(b, 3);
    Vector z = (x - y);
    ASSERT_EQ(z.at(1), -2);
    ASSERT_EQ(z.at(2), -2);
    ASSERT_EQ(z.at(3), -2);
}
TEST(Vector, minus_operator_throw)
{
    double a[] = {1,2, 3};
    double b[] = {3,4};
    Vector x(a, 3);
    Vector y(b, 2);
    ASSERT_ANY_THROW(x - y);
}
TEST(Vector, plus_operator)
{
    double a[] = {1,2, 3};
    double b[] = {3,4, 5};
    Vector x(a, 3);
    Vector y(b, 3);
    Vector z = (x + y);
    ASSERT_EQ(z.at(1), 4);
    ASSERT_EQ(z.at(2), 6);
    ASSERT_EQ(z.at(3), 8);
}
TEST(Vector, plus_operator_throw)
{
    double a[] = {1,2, 3};
    double b[] = {3,4};
    Vector x(a, 3);
    Vector y(b, 2);
    ASSERT_ANY_THROW(x + y);
}
TEST(Vector, equal_operator)
{
    double a[] = {1,2, 3};
    Vector x(a, 3);
    Vector y = x;
    ASSERT_EQ(y.at(1), 1);
    ASSERT_EQ(y.at(2), 2);
    ASSERT_EQ(y.at(3), 3);
}
TEST(Vector, subtract)
{
    double a[] = {1,2, 3};
    double b[] = {3,4, 5};
    Vector x(a, 3);
    Vector y(b, 3);
    x.subtract(y);
    ASSERT_EQ(x.at(1), -2);
    ASSERT_EQ(x.at(2), -2);
    ASSERT_EQ(x.at(3), -2);
}
TEST(Vector, subtrct_throw)
{
    double a[] = {1,2, 3};
    double b[] = {3,4};
    Vector x(a, 3);
    Vector y(b, 2);
    ASSERT_ANY_THROW(x.subtract(y));
}
TEST(Vector, add)
{
    double a[] = {1,2, 3};
    double b[] = {3,4, 5};
    Vector x(a, 3);
    Vector y(b, 3);
    x.add(y);
    ASSERT_EQ(x.at(1), 4);
    ASSERT_EQ(x.at(2), 6);
    ASSERT_EQ(x.at(3), 8);
}
TEST(Vector, add_throw)
{
    double a[] = {1,2, 3};
    double b[] = {3,4};
    Vector x(a, 3);
    Vector y(b, 2);
    ASSERT_ANY_THROW(x.add(y));
}
TEST(Vector, distance)
{
    double a[] = {1,2, 3};
    double b[] = {3,4, 5};
    Vector x(a, 3);
    Vector y(b, 3);
    ASSERT_NEAR(distance(x,y), sqrt(12), EPSILON);
}
TEST(Vector, triangle_area)
{
    double a[] = {0, 0};
    double b[] = {0, 2};
    double c[] = {2, 0};
    Vector x(a, 2);
    Vector y(b, 2);
    Vector z(c, 2);
    ASSERT_NEAR(2, area(x, y, z), EPSILON);
}
TEST(Vector, triangle_area2)
{
    double a[] = {0, 0};
    double b[] = {0, 2};
    double c[] = {2, 0};
    Vector x(a, 2);
    Vector y(b, 2);
    Vector z(c, 2);
    Vector arr[] = {x, y, z};
    ASSERT_NEAR(2, area(arr, 3), EPSILON);
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
