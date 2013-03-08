/**
 * careercup 3.5
 * Implement a MyQueue class which implements 
 * a queue using two stacks.
 */

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/*
 * data structure: queue implemented by two stacks.
 */
template <class T>
class myqueue {
private:
    stack<T> stk[2];
public:
    myqueue() { 
        // stk[0] used to push
        // stk[1] used to pop
    }
    ~myqueue() { }
    
    void enqueue(T val);
    T deque();
    bool empty();
};

template <class T>
void myqueue<T>::enqueue(T val)
{
    stk[0].push(val);
}

template <class T>
T myqueue<T>::deque()
{
    T retval;
    
    assert(stk[0].size() != 0 || stk[1].size() != 0);
    if ( stk[1].size() == 0 ) {
        // pop all stk[0] elements to stk[1]
        // then pop the top element of stk[1]
        while ( stk[0].size() != 0 ) {
            T tmp = stk[0].top();
            stk[0].pop();
            stk[1].push(tmp);
        }
    }
    retval = stk[1].top();
    stk[1].pop();
    
    return retval;
}

template <class T>
bool myqueue<T>::empty() 
{
    return stk[0].size() == 0 && stk[1].size() == 0;
}

int main()
{
    myqueue<int> mq;
    
    for (int i = 0; i < 5; i++)
        mq.enqueue(i);
    while ( !mq.empty() ) {
        int ret = mq.deque();
        cout << "Now " << ret << " popped!" << endl; 
    }
    return 0;
}
