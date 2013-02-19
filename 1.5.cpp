/* 
 * Implement a method to perform basic string compression 
 * using the counts of repeated characters. For example, 
 * the string aabcccccaaa would become a2b1c5a3. 
 * If the "compressed" string would not become smaller 
 * than the original string, your method should return 
 * the original string.
 */
#include <iostream>
#include <cstring>

using namespace std;

void strcmpr(char *str)
{
    int len = strlen(str), newlen;
    int count = 1, cur = 0;
    char cpy[len * 2], buf[BUFSIZ];
    char now;
    
    if ( !str ) {
        cerr << "Invalid input!" << endl;
        return;
    }
    
    memset(cpy, 0, len * 2);
    
    for (int i = 0; i < len; i += count) {
        count = 1;
        cpy[cur++] = str[i];
        
        // loop until another kind of character 
        for (int j = i + 1; str[j] == str[i]; j++) 
            count++;
        
        // concatenate counting string
        sprintf(buf, "%d", count);
        newlen = strlen(buf);
        strncat(cpy + cur, buf, newlen);
        
        cur += newlen;
    }
    cpy[cur] = '\0';
    
    if ( cur >= len )
        return;
    strncpy(str, cpy, cur + 1);
}

int main()
{
    char test[] = "abbbcf";
    strcmpr(test);
    cout << test << endl;
    
    return 0;
}