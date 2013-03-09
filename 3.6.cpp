/**
 * careercup 3.6
 * Write a program to sort a stack in ascending order 
 * (with biggest items on top). You may use additional 
 * stacks to hold items, but you may not copy the elements 
 * into any other data structure (such as an array).
 * The stack supports the following operations: 
 * push, pop, peek, and isEmpty.
 */

#include <iostream>
#include <stack>

using namespace std;

/*
 * Method: using insertion sort with one additional stack
 */
template <class T>
void stksort(stack<T> &orgstk)
{
    T maxval;
    stack<T> addstk;
    
    while ( !orgstk.empty() ) {
        maxval = orgstk.top();
        orgstk.pop();
        
        if ( addstk.empty() || addstk.top() >= maxval ) {
            addstk.push(maxval);
        } else {
            while ( !addstk.empty() ) {
                if ( addstk.top() < maxval ) {
                    orgstk.push(addstk.top());
                    addstk.pop();
                } else 
                    break;
            }
            addstk.push(maxval);
        }
    }
    
    while ( !addstk.empty() ) {
        orgstk.push(addstk.top());
        addstk.pop();
    }
} 

int main() 
{
    stack<int> mystk;
    
    mystk.push(3);
    mystk.push(1);
    mystk.push(2);
    mystk.push(3);
    mystk.push(4);
    
    stksort(mystk);
    
    while ( !mystk.empty() ) {
        cout << mystk.top() << " ";
        mystk.pop();
    }
    cout << endl;
    
    return 0;
}