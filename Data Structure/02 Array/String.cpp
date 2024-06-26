#include<iostream>
#include<cstring>
using namespace std;
class String
{
private:
    char *str;
    int len;
public:
    String(const char *init,int m):len(m)
    {
        str = new char[m + 1];
        strncpy(str, init, m);
        str[m] = '\0';
    }
    bool operator==(String t)
    {
        if (len != t.len) return false;
        return strcmp(str, t.str) == 0;
    }// if equl return true
    bool operator!(){return len = 0;}; // if empty return true
    int Length() {return len;};//return characters ªºªø«×
    String Concat(String t);
    // return a string whose elements are those of *this followed by those of t.
    String Substr(int i,int j);
    /* return a string containing the characters of *this at positions
    i, i+1, ..., i+j-1 if these are valid positions of *this;
    otherwise, return the empty string. */
    int Find(String pat);
};

int String::Find(String pat)
{
  char *p = pat.str, *s = str;
  int i = 0;  
  if (*p && *s)
      while ( i <= Length() - pat.Length())
	 if (*p++ == *s++) { 
	     if (!*p) return i; // match found
	 }
	 else { // no match
	     i++; s = str + i; p = pat.str;
	 }
  return -1;
}

String String::Concat(String t)
{
    int newLen = len + t.len;
    char *newStr = new char[newLen + 1];
    strcpy(newStr, str);
    strcat(newStr, t.str);
    return String(newStr, newLen);
}

String String::Substr(int i ,int j)
{
    if (i < 0 || i >= len || j <= 0 || i + j > len) 
        return String("", 0);
    char *subStr = new char[j + 1];
    strncpy(subStr, str + i, j);
    subStr[j] = '\0';
    return String(subStr, j);
}

int main()
{
   String s("abcabcdefg",10);
   String pat1("cde", 3);
   String pat2("abd", 3);
   String Pat3("abc", 3);
   String pat4("abcabcacab", 10);

   cout << s.Find(pat1) << endl;
   cout << s.Find(pat2) << endl;
   cout << s.Find(Pat3) << endl;
   cout << s.Find(pat4) << endl;

    return 0;
}