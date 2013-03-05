/**
 * careercup 3.3
 * Imagine a (literal) stack of plates. If the stack gets too high, 
 * it might topple. Therefore, in real life, we would likely start 
 * a new stack when the previous stack exceeds some threshold. 
 *
 * Implement a data structure SetOfStacks that mimics this. SetOfStacks 
 * should be composed of several stacks and should create a new stack 
 * once the previous one exceeds capacity.SetOfStacks.push() and 
 * SetOfStacks.pop() should behave identically to a single stack 
 * (that is, pop() should return the same values as it would 
 * if there were just a single stack).
 *
 * FOLLOW UP
 * Implement a function popAt(int index) which performs a pop 
 * operation on a specific sub-stack.
 */
#include <iostream>
#include <list>
#include <cassert>

using namespace std;

/*
 * class SetOfStacks: using a resized array to store the 
 * pointers by which linked lists pointed to mimic this 
 * functionality.
 */
template <class T>
class set_of_stacks {
private:
    list<T> *ptr_storage;   // store stacks
    int ptr_size;           // # of stacks
    int list_size;          // capacity of each stack
    int current_ptr;        // store in which stack top pointer resides
    int empty_stack_num;    // # of empty stack
public:
    /* 
     * constructor
     */
    set_of_stacks(int init_ptr_num, int max_list_size) 
        : ptr_size(init_ptr_num), list_size(max_list_size) {
        assert(ptr_size >= 1 && list_size >= 1);
        cout << "In constructor..." << endl;
        // build pointers table
        ptr_storage = new list<T> [ptr_size];
        // assemble the first linked list as a initialized stack
        current_ptr = 0;
        empty_stack_num = ptr_size;
    }
    
    /* 
     * destructor
     */
    ~set_of_stacks() {
        assert(current_ptr >= 0);
        cout << "In destructor..." << endl;
        delete[] ptr_storage;
    }
    
    /* 
     * method: push
     */
    void push(T val) {
        // check whether we need to push element in a new stack
        if ( ptr_storage[current_ptr].size() == list_size )
            current_ptr++;
        // check whether the pointer table is full 
        if ( current_ptr == ptr_size ) {
            // if so, double size the table
            list<T> *tmp_storage = new list<T> [ptr_size * 2];
            
            empty_stack_num += ptr_size;
            for (int i = 0; i < ptr_size; i++)
                tmp_storage[i] = ptr_storage[i];
            delete[] ptr_storage;
            ptr_storage = tmp_storage;
            ptr_size += ptr_size;
        }
        // now we can push element as usual
        if ( ptr_storage[current_ptr].size() == 0 )
            empty_stack_num--;
        ptr_storage[current_ptr].push_back(val);
    }
    
    /* 
     *method: pop
     */
    T pop() {
        T retval;
        // check whether current stack is empty
        // be careful about the impact pop_at() may bring.
        while ( ptr_storage[current_ptr].size() == 0 ) {
            assert(current_ptr > 0);
            current_ptr--;
        } 
        retval = ptr_storage[current_ptr].back();
        ptr_storage[current_ptr].pop_back();
        
        if ( ptr_storage[current_ptr].size() == 0 )
            empty_stack_num++;
        return retval;
    }
    
    /*
     * method: pop_at
     * index should be [0, ptr_size)
     */
    T pop_at(int index) {
        T retval; 
        
        assert(index >= 0 && index < ptr_size);
        assert(ptr_storage[index].size() > 0);
        retval = ptr_storage[index].back();
        ptr_storage[index].pop_back();
        
        if ( ptr_storage[index].size() == 0 )
            empty_stack_num++;
        
        return retval;
    }
    
    /*
     * method: query whether certain stack is empty
     */
    bool empty(int index) {
        assert(index >= 0 && index < ptr_size);
        
        return ptr_storage[index].size() == 0;
    }
    
    /*
     * method: query whether stack set is empty
     */
    bool all_empty() {
        return empty_stack_num == ptr_size;
    }
    
    /*
     * method: get stack number
     */
    int stack_num() {
        return ptr_size;
    }
    
    /*
     * method: get capacity of each stack
     */
    int stack_capacity() {
        return list_size;
    }
};

/*
 * test case
 */
int main()
{
    set_of_stacks<int> ss(3, 2);
    
    cout << "This stack set has " << ss.stack_num() << " stack(s), " 
         << "each of which has capacity: " << ss.stack_capacity() << endl; 
    cout << "Pushing 1, 2, ..., 7 accordingly..." << endl;
    for (int i = 1; i <= 7; i++) 
        ss.push(i);
    cout << "Now this stack set has " << ss.stack_num() << " stack(s)" << endl; 
    cout << "Popping all elements out of the 2nd stack" << endl;
    while ( !ss.empty(1) )
        cout << "-->now popping: " << ss.pop_at(1) << " "; 
    cout << endl;
    cout << "Now pushing all elements..." << endl;
    for (int i = 1; i <= 7; i++) {
        if ( ss.all_empty() )
            cout << "Now stack set is empty!!!" << endl;
        else
            cout << ss.pop() << " ";
    }
    cout << endl;
        
    return 0;
}