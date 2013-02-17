/*
 * Given two strings, write a method to decide 
 * if one is a permutation of the other.
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/* 
 * First method: sort two strings then compare.
 * Time complexity: O(nlogn).
 */
bool is_perm_v1(string s1, string s2)
{
    // check whether two strings have same length
    if ( s1.size() != s2.size() )
        return false;
        
    // first, sort two strings
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    // then compare two strings afterwards
    for (int i = 0; i < s1.size(); i++)
        if ( s1[i] != s2[i] )
            return false;
    return true;
}

/*
 * Second method: use bitmap.
 * Time complexity: O(n).
 */
bool is_perm_v2(string s1, string s2)
{
    static int charmap[2][256];  // bitmap
    
    // check whether two strings have same length
    if ( s1.size() != s2.size() )
        return false;
    
    /* first, analyze each string by counting the # of 
     * each characters among a string.
     */
    for (int i = 0; i < s1.size(); i++) {
        charmap[0][int(s1[i])]++;
        charmap[1][int(s2[i])]++;
    }
    /*
     * then, compare two bitmaps
     */
    for (int i = 0; i < 255; i++) 
        if ( charmap[0][i] != charmap[1][i] )
            return false;
    return true;
}

int main()
{
    string s1, s2;
    
    // some test cases
    s1 = "abcdefg";
    s2 = "edcabgf";
    cout << "test case 1: " << is_perm_v2(s1, s2) << endl;
    s1 = "abcdeadfa";
    s2 = "abccdee3r";
    cout << "test case 2: " << is_perm_v2(s1, s2) << endl;
    
    return 0;
}

