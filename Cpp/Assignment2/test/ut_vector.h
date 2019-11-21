#include "../src/vector.h"
#include "../src/dot.h"
#include <cmath>
TEST(InnerProduct, Dot1) {
  int u[]={1, 0, 2};
  int v[]={1, 1, 3};

  ASSERT_EQ(7, dot(u, v, 3, 3));
}
TEST(InnerProduct, Dot2) {
  int u[]={1, 0, 2, 4};
  int v[]={1, 1, 3, 6};

  ASSERT_EQ(31, dot(u, v, 4, 4));
}

TEST(InnerProduct, Exception1) {
  int u[]={1, 0, 2, 4};
  int v[]={1, 1, 3};

  ASSERT_ANY_THROW(dot(u, v, 4, 3));
}
TEST(InnerProduct, Exception2) {
  int u[]={1, 0, 2};
  int v[]={1, 1, 3, 4};

  ASSERT_ANY_THROW(dot(u, v, 3, 4));
}

TEST(VectorTest, GetDim1){
    double data[3] = {2, 3, 4};
    Vector vector(data, 3);

    ASSERT_EQ(3, getDim(vector));
}
TEST(VectorTest, GetDim2){
    double data[4] = {2, 3, 4, 5};
    Vector vector(data, 4);

    ASSERT_EQ(4, getDim(vector));
}

TEST(VectorTest, IsZero1){
    double data[3] = {2.5, 3.4, 4.2};
    Vector vector(data, 3);

    ASSERT_FALSE(isZero(vector));
}
TEST(VectorTest, IsZero2){
    double data[3] = {2.5, 0, 4.2};
    Vector vector(data, 3);

    ASSERT_TRUE(isZero(vector));
}

TEST(VectorTest, Length1){
    double data[3] = {3, 4, 5};
    Vector vector(data, 3);

    ASSERT_NEAR(sqrt(50), length(vector), 0.001);
}
TEST(VectorTest, Length2){
    double data[4] = {2, 4, 6, 8};
    Vector vector(data, 4);

    ASSERT_NEAR(sqrt(120), length(vector), 0.001);
}

// //and your test for each function
