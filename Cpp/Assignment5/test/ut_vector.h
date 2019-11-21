#include<gtest/gtest.h>
#include"../src/vector.h"
#include"../src/dot.h"
#define EPSILON 0.0001
TEST(OutputVector, Add)
{
    double a[] = {1, 2};
    double b[] = {3, 4};
    Vector u(a, 2);
    Vector v(b, 2);
    string str = addAns(u, v);
    ASSERT_EQ("(4,6)", str);
}

TEST(OutputVector, AddException)
{
    double a[] = {1, 2, 3};
    double b[] = {3, 4};
    Vector u(a, 3);
    Vector v(b, 2);
    ASSERT_ANY_THROW(addAns(u, v));
}

TEST(OutputVector, Subtract)
{
    double a[] = {1, 2};
    double b[] = {3, 4};
    Vector u(a, 2);
    Vector v(b, 2);
    string str = subtractAns(u, v);
    ASSERT_EQ("(-2,-2)", str);
}

TEST(OutputVector, SubtractException)
{
    double a[] = {1, 2, 3};
    double b[] = {3, 4};
    Vector u(a, 3);
    Vector v(b, 2);
    ASSERT_ANY_THROW(subtractAns(u, v));
}

TEST(OutputVector, dot)
{
    double a[] = {1, 2};
    double b[] = {3, 4};
    Vector u(a, 2);
    Vector v(b, 2);
    double temp = dot(u, v);
    ASSERT_NEAR(11, temp, EPSILON);
}

TEST(OutputVector, dotAnswer)
{
    double a[] = {1, 2};
    double b[] = {3, 4};
    Vector u(a, 2);
    Vector v(b, 2);
    string str = dotAns(u, v, 2);
    ASSERT_EQ("11", str);
}

TEST(OutputVector, dotAnswerException)
{
    double a[] = {1, 2, 3};
    double b[] = {3, 4};
    Vector u(a, 3);
    Vector v(b, 2);
    ASSERT_ANY_THROW(dotAns(u, v, u.dim()));
}

TEST(VectorIO, CreateVectorFromStringOfNumbers1)
{
    string str = "(1,2)";
    Vector vec = createVectorFromStringOfNumbers(str, 2);
    ASSERT_EQ(vec.dim(), 2);
    ASSERT_EQ(vec.at(1), 1);
    ASSERT_EQ(vec.at(2), 2);
}

TEST(VectorIO, CreateVectorFromStringOfNumbers2)
{
    string str = "(2.4,3.6)";
    Vector vec = createVectorFromStringOfNumbers(str, 2);
    ASSERT_EQ(vec.dim(), 2);
    ASSERT_EQ(vec.at(1), 2.4);
    ASSERT_EQ(vec.at(2), 3.6);
}

TEST(VectorIO, CreateVectorFromStringOfNumbers3)
{
    string str = "(1.23 ,4.56 )";
    Vector vec = createVectorFromStringOfNumbers(str, 2);
    ASSERT_EQ(vec.dim(), 2);
    ASSERT_EQ(vec.at(1), 1.23);
    ASSERT_EQ(vec.at(2), 4.56);
}

TEST(VectorIO, InputException1)
{
    string str = "(1,2";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException2)
{
    string str = "1,2)";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException3)
{
    string str = "(,1,2)";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException4)
{
    string str = "(1,2,)";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException5)
{
    string str = "(1,2]";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException6)
{
    string str = "[1,2)";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException7)
{
    string str = "(a,2)";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException8)
{
    string str = "(,,)";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException9)
{
    string str = "(1.2,2.)";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException10)
{
    string str = "(1., 2.4)";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException11)
{
    string str = "(.31, 2.4)";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

TEST(VectorIO, InputException12)
{
    string str = ")1,2(";
    ASSERT_ANY_THROW(createVectorFromStringOfNumbers(str, 2));
}

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