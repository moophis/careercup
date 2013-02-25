/**
 * Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
 */
#include <iostream>
#include <list>
#include <map>

using namespace std;

/*
 * Method 1: remove duplicates with buffer
 */
void remove_dup(list<int> &li)
{
    map<int, bool> occur;
    list<int>::iterator it;
    
    for (it = li.begin(); it != li.end(); ) {
        if ( occur.find(*it) == occur.end() ) {
            //cout << "append new: " << *it << endl;
            occur[*it] = true;
            it++;
        }
        else {
            //cout << "remove duplicat: " << *it << endl;
            it = li.erase(it);
        }
    }
}

/*
 * Method 2: remove duplicates without buffer:
 *  - use two loops to travel through the list
 */
void remove_dup_nobuf(list<int> &li)
{
    list<int>::iterator it1, it2;
    
    for (it1 = li.begin(); it1 != li.end(); it1++) {
        it2 = it1;
        advance(it2, 1);
        while ( it2 != li.end() ) {
            if ( *it1 == *it2 ) 
                it2 = li.erase(it2);
            else 
                it2++;
        }
    }
}

int main()
{
    int testint[] = {5, 2, 3, 4, 3, 4, 1, 2};
    list<int> mylist(testint, testint + sizeof(testint) / sizeof(int));
    list<int>::iterator it;

    remove_dup_nobuf(mylist);
    
    for (it = mylist.begin(); it != mylist.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    return 0;
}