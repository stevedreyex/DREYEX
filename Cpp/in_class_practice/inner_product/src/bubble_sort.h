#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
template <class T>
void bswap (T & a, T & b) {
  T temp = a;
  a = b;
  b = temp;
}

typedef bool (*COMP) (int, int);

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


#endif
