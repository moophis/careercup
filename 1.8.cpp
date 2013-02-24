/**
 * Assume you have a method isSubstring which checks 
 * if one word is a substring of another. Given two strings, 
 * s1 and s2, write code to check if s2 is a rotation of s1 
 * using only one call to isSubstring 
 * (e.g., "waterbottle" is a rotation of "erbottlewat").
 */
#include <iostream>
#include <string>

using namespace std;

/*
 * To find if s2 is a substring of s1
 */
bool is_substr(string s1, string s2)
{
    return s1.find(s2) != string::npos;
}

/*
 * Method: find whether s2 is a substring
 * of s1 + s1.
 * Note: length of s1 and s2 should be the same
 */
bool is_rotation(string s1, string s2)
{
    string cat;
    // check length
    if ( s1.length() != s2.length() )
        return false;
    
    cat = s1 + s1;
    return is_substr(cat, s2); 
}

int main()
{
    string s1("waterbottle");
    string s2("erbottlewat");
    
    cout << is_rotation(s1, s2) << endl;
    return 0;
}
