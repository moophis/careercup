/*
 * Given two strings, write a method to decide 
 * if one is a permutation of the other.
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_perm(string s1, string s2)
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

int main()
{
	string s1, s2;
	
	// some test cases
	s1 = "abcde";
	s2 = "edcab";
	cout << "test case 1: " << is_perm(s1, s2) << endl;
	s1 = "abcde";
	s2 = "abccd";
	cout << "test case 2: " << is_perm(s1, s2) << endl;
	
	return 0;
}

