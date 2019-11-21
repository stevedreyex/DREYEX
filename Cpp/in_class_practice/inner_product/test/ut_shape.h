#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <cmath>
#include "../src/circle.h"
#include "../src/polygon.h"
#include "../src/triangle.h"

class ShapeTest: public ::testing::Test
{
protected:

  // fixture setup
  void SetUp()
  {
    c1 = new Circle(100);
    c2 = new Circle(10);
    c3 = new Circle(1);
    x = new Vector(a,2);
    y = new Vector(b,2);
    z = new Vector(c,2);
    w = new Vector(d,2);
    Vector square[] = {*w, *x, *y, *z};
    Vector triangle[] = {*w, *x, *z};
    p1 = new Polygon(square, 4);
    p2 = new Polygon(triangle, 3);
  }

  // fixture teardown
  void TearDown()
  {
    delete c1;
    delete c2;
    delete c3;
    delete p1;
    delete p2;
    delete x;
    delete y;
    delete z;
    delete w;
  }
  // test data in fixture
  double a[2] = {0,0};
  double b[2] = {1,0};
  double c[2] = {1,1};
  double d[2] = {0,1};
  Vector * w;
  Vector * x;
  Vector * y;
  Vector * z;

  Shape * c1;
  Shape * c2;
  Shape * c3;
  Shape * p1;
  Shape * p2;
};

TEST_F(ShapeTest, Circle){
  Shape * s[] ={c1, c2, c3};
  std::sort(s, s+3, [](Shape *s, Shape *t){return s->area() < t->area();});
  ASSERT_NEAR(M_PI, s[0]->area(), epsilon);
  ASSERT_NEAR(100 * M_PI, s[1]->area(), epsilon);
  ASSERT_NEAR(10000 * M_PI, s[2]->area(), epsilon);
}

TEST_F(ShapeTest, MultipleShapes){
  Shape * s[] = {c3, p1, p2};
  std::sort(s, s+3, [](Shape *s, Shape *t){return s->area() < t->area();});
  ASSERT_NEAR(0.5, s[0]->area(), epsilon);
  ASSERT_NEAR(1.0, s[1]->area(), epsilon);
  ASSERT_NEAR(M_PI, s[2]->area(), epsilon);
}

TEST_F(ShapeTest, Name)
{
  //static binding
  ASSERT_EQ("Circle", c3->name());
  //dynamic binding(runtime binding)
  ASSERT_NEAR(M_PI, c3->area(), epsilon);

}

TEST_F(ShapeTest, Triangle)
{
  Vector triangle[] = {*w, *x, *z};
  Triangle * t = Triangle::createTriangle(triangle, 3);
}

TEST_F(ShapeTest, TriangleException)
{
  Vector triangle[] = {*w, *x, *x};
  try{
    Triangle::createTriangle(triangle, 3);
    FAIL();
  } catch(int i){
      FAIL();
  }
  catch(std::string s){
    ASSERT_EQ("on the same line", s);
  }

}
