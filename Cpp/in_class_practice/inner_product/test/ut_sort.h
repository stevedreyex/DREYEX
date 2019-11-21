#include <gtest/gtest.h>
#include <algorithm>
#include <cmath>
#include "../src/bubble_sort.h"
#include <vector>
#include <string>


using std::vector;
using std::string;

TEST(SortTest, Increasing){
  int a[] = {5, 4, 1, 3, 2};

  std::sort(a, a+5);
  ASSERT_EQ(1, a[0]);
  ASSERT_EQ(2, a[1]);
  ASSERT_EQ(3, a[2]);
  ASSERT_EQ(4, a[3]);
  ASSERT_EQ(5, a[4]);
}

TEST(SortTest, DecreasingWithLambda){
  int a[] = {5, 4, 1, 3, 2};

  std::sort(a, a+5, [] (int a, int b) {return a > b;});
  ASSERT_EQ(5, a[0]);
  ASSERT_EQ(4, a[1]);
  ASSERT_EQ(3, a[2]);
  ASSERT_EQ(2, a[3]);
  ASSERT_EQ(1, a[4]);
}

bool greaterThan(int a, int b){
    return a > b;
}

typedef bool (*COM) (int, int);

TEST(SortTest, DecreasingWithFunction){
  int a[] = {5, 4, 1, 3, 2};
  std::sort(a, a+5, greaterThan);
  ASSERT_EQ(5, a[0]);
  ASSERT_EQ(4, a[1]);
  ASSERT_EQ(3, a[2]);
  ASSERT_EQ(2, a[3]);
  ASSERT_EQ(1, a[4]);
}

class GreaterThan{
public:
  GreaterThan(int n=0) { _n = n; }
  // GreaterThan(){ _n = 0; }
  // overloadig function call operator
  bool operator ()(int a, int b) {return abs(a-_n) > abs(b-_n);}
private:
  int _n;
};

TEST(SortTest, DecreasingWithObject){
  int a[] = {5, 4, 1, 3, 2};
  GreaterThan gt;
  std::sort(a, a+5, gt);
  ASSERT_EQ(5, a[0]);
  ASSERT_EQ(4, a[1]);
  ASSERT_EQ(3, a[2]);
  ASSERT_EQ(2, a[3]);
  ASSERT_EQ(1, a[4]);
}

TEST(SortTest, DecreasingDistTo5WithObject){
  int a[] = {5, 4, 1, 3, 2};
  GreaterThan gt(5);
  std::sort(a, a+5, gt);
  ASSERT_EQ(1, a[0]);
  ASSERT_EQ(2, a[1]);
  ASSERT_EQ(3, a[2]);
  ASSERT_EQ(4, a[3]);
  ASSERT_EQ(5, a[4]);
}

TEST(SortTest, IncreasingDistanceTo4){
  int a[] = {5, 4, 1, 3, 2};
  int n = 4;
  std::stable_sort(a, a+5, [n] (int a, int b) {return abs(a-n) < abs(b-n);});
  ASSERT_EQ(4, a[0]);
  ASSERT_EQ(5, a[1]);
  ASSERT_EQ(3, a[2]);
  ASSERT_EQ(2, a[3]);
  ASSERT_EQ(1, a[4]);
}

TEST(SortTest, IncreasingDistanceTo4Double){
  double a[] = {5.1, 4.1, 1.1, 3.1, 2.1};
  int n = 4;
  std::sort(a, a+5, [n] (double a, double b) {return abs(a-n) < abs(b-n);});
  ASSERT_EQ(4.1, a[0]);
  ASSERT_EQ(3.1, a[1]);
  ASSERT_EQ(5.1, a[2]);
  ASSERT_EQ(2.1, a[3]);
  ASSERT_EQ(1.1, a[4]);
}
TEST(BubbleSort, Increasing){
  int a[] = {5, 4, 1, 3, 2};

  bubbleSort(a, a+5, [](int a, int b){return a < b;});
  ASSERT_EQ(1, a[0]);
  ASSERT_EQ(2, a[1]);
  ASSERT_EQ(3, a[2]);
  ASSERT_EQ(4, a[3]);
  ASSERT_EQ(5, a[4]);
}

TEST(BubbleSort, Swap)
{
  int a[] = {0,1};
  bswap(*a, *(a+1));
  ASSERT_EQ(1, a[0]);
  ASSERT_EQ(0, a[1]);
}

TEST(BubbleSort, Decreasing){
  int a[] = {5, 4, 1, 3, 2};

  bubbleSort(a, a+5, [](int a, int b){return a > b;});
  ASSERT_EQ(5, a[0]);
  ASSERT_EQ(4, a[1]);
  ASSERT_EQ(3, a[2]);
  ASSERT_EQ(2, a[3]);
  ASSERT_EQ(1, a[4]);
}

TEST(BubbleSort, String){
  std::string a[] = {"banana","apple", "papaya", "guava", "kiwi"};
  bubbleSort(a, a+5, [](std::string a, std::string b){return a < b;});
  ASSERT_EQ("apple", a[0]);
  ASSERT_EQ("banana", a[1]);
  ASSERT_EQ("guava", a[2]);
  ASSERT_EQ("kiwi", a[3]);
  ASSERT_EQ("papaya", a[4]);
}

TEST (BubbleSort, VectorOfStrings)
{
  std::string a[] = {"banana","apple", "papaya", "guava", "kiwi"};
  vector<string> v(a,a+5);
  bubbleSort(v.begin(), v.end(), [](std::string a, std::string b){return a < b;});
  ASSERT_EQ("apple", v[0]);
  ASSERT_EQ("banana", v[1]);
  ASSERT_EQ("guava", v[2]);
  ASSERT_EQ("kiwi", v[3]);
  ASSERT_EQ("papaya", v[4]);
}
