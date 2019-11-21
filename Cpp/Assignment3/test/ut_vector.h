#include "../src/vector.h"
#include <cmath>
TEST(VectorTest, IsZero1)
{
    double data[3] = {2.5, 3.4, 4.2};
    Vector vector(data, 3);

    ASSERT_FALSE(vector.isZero());
}
TEST(VectorTest, IsZero2)
{
    double data[3] = {2.5, 0, 4.2};
    Vector vector(data, 3);

    ASSERT_TRUE(vector.isZero());
}

TEST(VectorTest, Length1)
{
    double data[3] = {3, 4, 5};
    Vector vector(data, 3);

    ASSERT_NEAR(sqrt(50), vector.length(), 0.001);
}
TEST(VectorTest, Length2)
{
    double data[4] = {2, 4, 6, 8};
    Vector vector(data, 4);

    ASSERT_NEAR(sqrt(120), vector.length(), 0.001);
}
TEST(VectroTest, At)
{
    double data[3] = {2.5, 3.4, 4.2};
    Vector vector(data, 3);

    ASSERT_EQ(vector.at(2), 3.4);
}
TEST(VectroTest, Dim)
{
    double data[3] = {2.5, 3.4, 4.2};
    Vector vector(data, 3);

    ASSERT_EQ(vector.dim(), 3);
}
// //and your test for each function
