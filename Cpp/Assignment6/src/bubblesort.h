#ifndef BUBBLESORT_H
#define BUBBLESORT_H
template <class T>
void bswap (T & a, T & b) {
  T temp = a;
  a = b;
  b = temp;
}

template <class RAI, class COMPARE>
void bubbleSort(RAI begin, RAI end, COMPARE comp)
{
  for (RAI i = end - 1; i != begin; i--) {
    for(RAI j = begin; j != i; j++)
      if (comp(*(j+1), *j))
      {
        bswap(*(j+1), *j);
      }
    }
}

#endif
