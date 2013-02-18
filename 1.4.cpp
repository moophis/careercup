/**
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
#include <cstring>

using namespace std;

/**
 * Method: basic string manipulations by 
 * building a new array.
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

/**
 * Method: change the string in place.
 */
void replace_string(char *str)
{
    // nlen = length of the extended string
    int len, nlen; 
    int space_num = 0;
    bool endstr = false;
    
    len = strlen(str);
    /* 
     * scan # of spaces (drop redundant spaces
     * at the end of the string before that).
     */
    for (int i = 0; i < len; i++)
        if ( str[i] == ' ' )
            for (int j = i + 1; str[j] == ' '; j++)
                if ( j == len - 1) {
                    len = i + 1;
                    break;
                }
    str[len - 1] = '\0';        
    for (int i = 0; i < len; i++) 
        if ( str[i] == ' ' ) 
                space_num++;

    /*
     * now move the string and insert new strings.
     */
    nlen = len + space_num * 2;
    for (int i = len - 1, j = nlen - 1; i >= 0; i--) {
        if ( str[i] != ' ' ) 
            str[j--] = str[i];
        else {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
    }
}

int main()
{
    char str[] = "Mr John Smith    ";
    //strinsert(str);
    replace_string(str);
    cout << str << endl;
} 