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

bitset<32> next_largest(bitset<32> nr)
{
    int i, one_cnt = 0, one_buf;
    
    /* Find the first 0 after having passed 1(s)
       once from right to left */
    for (i = 0; i < 32; i++) {
        if (nr[i]) 
            one_cnt++;
        if (!nr[i] && one_cnt) 
            break;
    }
    one_buf = one_cnt;
    
    if (i == 32)
        return nr;  // no 1 or 0 ever found
    
    nr.set(i, true);    // find this bit 0 and toggle on it
    for (i = i - 1; i >= 0 && one_cnt > 0; i--) {
        nr.set(i, false);
        one_cnt--;
    }
    
    /* Rearrange 1s as far right as possible */
    for (i = 0; i < one_buf - 1; i++) {
        nr.set(i, true);
    }
    
    return nr;
}

bitset<32> next_smallest(bitset<32> nr)
{
    int i, zero_cnt = 0, one_cnt = 0;
    
    /* Find the first 1 after having passed 0(s)
       once from right to left */
    for (i = 0; i < 32; i++) {
        if (!nr[i])
            zero_cnt++;
        if (nr[i]) {
            one_cnt++;
            if (zero_cnt)   // already met 0
                break;
        }
    }
    
    if (i == 32)
        return nr;  // no 1 or 0 ever found
    cout << i << endl;
    cout << one_cnt << endl;
    nr.set(i, false);   // flip this bit

    /* Rearrange 1s as far left as possible */
    for (i = i - 1; i >= 0 && one_cnt > 0; i--) {
        nr.set(i, true);
        one_cnt--;
    }

    for (; i >= 0; i--) {
        nr.set(i, false);
    }

    return nr;
}

int main()
{
    bitset<32> mybit1(string("011100"));
    bitset<32> mybit2(string("100011"));
    cout << next_largest(mybit1) << endl;
    cout << next_smallest(mybit2) << endl; 
    
    return 0;
}
