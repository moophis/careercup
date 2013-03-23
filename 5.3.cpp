/**
 * careercup 5.3
 * Given a positive integer, print the next smallest and 
 * the next largest number that have the same number of 
 * 1 bits in their binary representation.
 */
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

bitset<32> next_smallest(bitset<32> nr)
{
    int i, one_cnt = 0, one_buf;
    
    /* Find the first 0 after meeting 1 
       from right to left */
    for (i = 0; i < 32; i++) {
        if (nr[i]) 
            one_cnt++;
        if (!nr[i] && one_cnt) 
            break;
    }
    one_buf = one_cnt;
    
    if (i == 32)
        return nr;  // no 1 or 0 ever found
    
    for (i = i - 1; i >= 0 && one_cnt >= 1; i--) {
        nr.set(i, false);
        one_cnt--;
    }
    
    /* Rearrange 1's as far right as possible */
    for (i = 0; i < one_buf; i++) {
        nr.set(i, true);
    }
    
    return nr;
}

int main()
{
    bitset<32> mybit(string("101100"));
    cout << next_smallest(mybit) << endl;
    
    return 0;
}
