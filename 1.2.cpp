/*
 * Implement a function void reverse(char* str) in C or C++ 
 * which reverses a null-terminated string.
 */
 
#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

void reverse(char *str)
{
    int len = strlen(str);
    
    if (len == 0)
        return;
        
    for (int i = 0; i <= len / 2; i++) 
        swap(str[i], str[len - i - 1]); 
}

int main()
{
    char test[] = "hello world!!!";
    reverse(test);
    cout << test << endl;
    
    return 0;
}

