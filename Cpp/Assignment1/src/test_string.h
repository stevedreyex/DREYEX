#include <iostream>
#include <string.h>
using namespace std;
///string::length
unsigned int string_length(string a)
{
    return a.length();
}
///string::empty
bool string_empty(string a)
{
    return a.empty();
}
///string::clear
string string_clear(string a)
{
    a.clear();
    return a;
}
///string::insert
string& string_insert (string str, int pos, const string& str1)
 {
     return str.insert(pos,str1);
 }
 string& string_insert (string str, int pos, const string& str1, int subpos, int sublen)
{
     return str.insert(pos,str1, subpos, sublen);
} 
 string& string_insert (string str, int pos, const char* s)
 {
     return str.insert(pos,s);
 }
 string& string_insert (string str, int pos, const char* s, int n)
 {
     return str.insert(pos,s, n);
 }
 string& string_insert (string str, int pos, int n, char c)
 {
     return str.insert(pos,n,c);
 }
//string::copy
string string_copy (string str, char str1[],int len, int pos)
{
    str.copy(str1,len,pos);
    return str1;
}
///string::compare
int string_compare (string str, const string& str1)
{
    return str.compare(str1);
}
int string_compare (string str, int pos, int len, const string& str1)
{
    return str.compare(pos, len, str1);
}
// int compare (int pos, int len, const string& str,int subpos, int sublen) const
// {

// }
// int compare (const char* s) const
// {

// }
// int string_compare (string str, int pos, int len, char* s)
// {
//     return str.compare(pos,len,s);
// }
// int compare (int pos, int len, const char* s, int n) const
// {

// }
// ///string::swap
string string_swap (string str, string& str1)
{
    str.swap(str1);
    return str;
}
// ///string::find
int string_find (string& str, string str1)
{
    if(str.find(str1) != std::string::npos)
        return str.find(str1);
    else
        throw string("can't find");
}
// int find (const char* s, int pos = 0) const
// {

// }
// int find (const char* s, int pos, int n) const
// {

// }
// int find (char c, int pos = 0) const
// {
    
// }
