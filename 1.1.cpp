/* 
 * Implement an algorithm to determine if a str has all unique characters. 
 * What if you cannot use additional data structures?
 */
#include <iostream>
#include <string>

using namespace std;

bool unique(string str)
{
    for (int i = 0; i < str.size() - 1; i++) {
        for (int j = i + 1; j < str.size() - 1; j++) {
            if ( str[i] == str[j] )
                return false;
        }
    }
    
    return true;
}

int main()
{
    cout << unique("1234dd") << endl;
    return 0;
}