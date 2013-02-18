/* 
 * Write a method to replace all spaces in a string with '%20'. 
 * You may assume that the string has sufficient space at the 
 * end of the string to hold the additional characters, and 
 * that you are given the "true" length of the string. 
 * (Note: if implementing in Java, please use a character array 
 * so you can perform this operation in place.)
 *
 * EXAMPLE
 * Input  : "Mr John Smith    "
 * Output: "Mr%20John%20Smith"
 *
 */
 
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

/**
 * Method: basic string manipulations.
 */
void strinsert(char *str)
{
    int len = strlen(str);
    char *cp = str;
    char buf[BUFSIZ];
    
    for (int i = 0; i < len; i++, cp++) 
        if ( str[i] == ' ' ) 
            strncat(buf, "%20", 4);
        else
            strncat(buf, cp, 1);

    strncat(buf, "\0", 1);
    strncpy(str, buf, BUFSIZ);
}


int main()
{
    char str[BUFSIZ] = "Hello my dear!!!";
    strinsert_v1(str);
    cout << str1 << endl;
} 