/**
 * careercup 3.2
 * How would you design a stack which, in addition to push and pop, 
 * also has a function min which returns the minimum element? 
 * Push, pop and min should all operate in O(1) time.
 */
#include <iostream>
#include <list>
#include <cassert>

using namespace std;

/*
 * stack class
 */
template<class T>
class stack {
private:
    struct node {
        T val;
        T min_sofar;
    };
    list<struct node> li;
public:
    // constructor
    stack() {}
    // method: get minimum value in stack
    T min() { return li.back().min_sofar; }
    // method: push an element into stack
    void push(T n) {
        struct node nd;
        T minval = li.back().min_sofar;
        
        minval = minval > n ? n : minval;
        nd.val = n;
        nd.min_sofar = minval;
        li.push_back(nd);
    }
    // method: pop an element out of stack
    T pop() {
        assert(li.size() > 0);
        T retval = li.back().val;
        li.pop_back();
        return retval;
    }
};

int main()
{
    int t;
    stack<int> mystack;
    
    for (int i = 0; i < 10; i++)
        mystack.push(i);
    mystack.push(-1);
    cout << "after pushing -1, min: " << mystack.min() << endl;
    t = mystack.pop();
    cout << "after popping " << t << " ,min: " << mystack.min() << endl;
    
    return 0;
}