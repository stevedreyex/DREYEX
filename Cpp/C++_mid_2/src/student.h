#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
using namespace std;





class Student{
public:
  Student()
  {

  }

  virtual string id() const = 0;

  virtual string name() const = 0;
  //
  void setScore(std::string courseName, int score)
  {
    vector<string> a_sub;
    a_sub.push_back(courseName);
    a_sub.push_back(to_string(score));
    _subject.push_back(a_sub);
  }
  //
  int getScore(string courseName) const
  {
      string::size_type sz;   // alias of size_t
      for(int i = 0; i < _subject.size(); i++)
      {
        if(_subject[i][0] == courseName)
        return std::stoi(_subject[i][1], &sz);
      }
  }

  // virtual bool isFail(std::string course) = 0;

private:
  vector<vector<string>> _subject;
};


void no_same_student(vector<Student *> s)
{
  vector<Student *> t = s;
  for(int i = 0; i<s.size(); i++)
  {
    if(s[i]->name() == t[i]->name())
    {
      throw "can't be happen";
    }
  }
}


template <class T>
void bswap (T & a, T & b) {
  T temp = a;
  a = b;
  b = temp;
}

template <class RandomAccessIterator, class COMPARE>
void bubbleSort(RandomAccessIterator begin, RandomAccessIterator end, COMPARE comp)
{
  for (RandomAccessIterator i = end - 1; i != begin; i--) {
    for(RandomAccessIterator j = begin; j != i; j++)
      if (comp(*(j+1), *j))
      {
        bswap(*(j+1), *j);
      }
    }
}








class Undergrad : public Student{
public:
  Undergrad(string id, string name)
  {
    _id = id;
    _name = name;
  }

string id() const
{
  return _id;
}

string name() const
{
  return _name;
}

  // bool isFail(std::string course){...}

private:
  string _id;
  string _name;
};





class Grad : public Student{
public:
  Grad(string id, string name)
  {
    _id = id;
    _name = name;
  }

string id() const
{
  return _id;
}

string name() const
{
  return _name;
}

  // bool isFail(std::string course)
  // {
  //
  // }

private:
  string _id;
  string _name;
};





class Course{
public:
  Course(std::string id, std::string name):_size(-1)
  {
    _course_id = id;
    _course_name = name;
  }

  std::string id() const
  {
    return _course_id;
  }

  std::string name() const
  {
    return _course_name;
  }

  int size() const
  {
    return _s.size();
  }

  void add(Student * s)
  {
    _s.push_back(s);
    no_same_student((*this)._s);
  }

  void add(Student ** begin, Student ** end)
  {
    for (auto iterator = begin; iterator != end; iterator++)
    {
      (*this).add((*iterator));
    }
    no_same_student((*this)._s);
  }

  vector<Student *> getStudentsByNameInc()
  {
    no_same_student((*this)._s);
    ::bubbleSort(_s.begin(), _s.end(), [](Student * a, Student * b){return a->name().at(0) < b->name().at(0);});
    return _s;
  }

  void setScores(vector<string> ids, vector<int> scores)
  {
    no_same_student((*this)._s);
    if(ids.size() != scores.size())
    {
      throw "can't set";
    }
    if(ids.size() != (*this)._s.size())
    {
      throw "can't set";
    }
    for(int i = 0; i <ids.size(); i++)
    {
      for(int j = 0; j < ids.size(); j++)
      {
        if(ids[i] == (*this)._s[j]->id())
          (*this)._s[j]->setScore(_course_name, scores[i]);
      }
    }
  }

  // std::vector<Student *> failedStudents(){...}

  string mem_at(int num)
  {
    if(num > _s.size())
    {
      throw "out of range";
    }
    return _s[num]->name();
  }

  Student * get_student(int i)
  {
    return _s[i];
  }

private:
  string _course_id;
  string _course_name;
  int _size;
  vector<Student *> _s;
};















#endif
