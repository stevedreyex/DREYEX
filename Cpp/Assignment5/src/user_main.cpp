#include<iostream>
#include<string>
#include "vector.h"
#include "dot.h"
using namespace std;
int main(void)
{
    int dim;
    string str1;
    string str2;
    cout <<"Please enter two vectors you want to calculate:" << endl;
    cout <<"Dimensions:";
    cin >> dim;
    cin.get();
    cout << "Vector 1:";
    getline(cin, str1);
    cout << "Vector 2:";
    getline(cin, str2);
    try
    {
        Vector vec1 = createVectorFromStringOfNumbers(str1, dim);
        Vector vec2 = createVectorFromStringOfNumbers(str2, dim);
        sameDim(vec1, vec2);
        cout << "Sum of these two Vectors: " << addAns(vec1, vec2) << endl;
        cout << "Difference between these two Vecotrs: " << subtractAns(vec1, vec2) << endl;
        cout << "Inner product of these two Vectors: " << dotAns(vec1, vec2, dim) << endl;
    }
    catch(const char* e)
    {
        cerr << e << endl;
    }
    
    return 0;
}