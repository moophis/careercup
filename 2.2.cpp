/**
 * Implement an algorithm to find the kth 
 * to last element of a singly linked list.
 */
#include <iostream>
#include <cassert>

using namespace std;

/*
 * data structure: linked list
 */
typedef struct _node {
    int data;
    struct _node *next;
}node;

/* 
 * initialize a linked list: add a header
 */
void init_list(node* &head, node* &tail)
{
    tail = new node; 
    tail->data = -2;
    tail->next = tail;
    
    head = new node;
    head->data = -1;
    head->next = tail; 
}

/*
 * add a node to a linked list
 */
node* add_node(int val, node* &head, node* &tail)
{
    node *current = head, *toadd;
    
    while ( current->next != tail ) 
        current = current->next;

    toadd = new node;
    toadd->data = val;
    toadd->next = tail;
    current->next = toadd;
    
    return toadd;
}

/* 
 * remove a node from a linked list
 * (note: only remove the node with data = val 
 * nearest to the header)
 * return -1 when no data matches
 */
int remove_node(int val, node* &head, node* &tail)
{
    node *current = head;
    
    if ( val == -1 && val == -2 ) 
        return -1;
    
    while ( current->next != tail ) {
        if ( current->next->data == val ) {
            current->next = current->next->next;
            return current->next->data;
        }
        current = current->next;
    }
    return -1;
}

/*
 * make a linked list from an array
 */
void array_to_list(int arr[], int size, node* &head, node* &tail)
{
    init_list(head, tail);
    
    for (int i = 0; i < size; i++) 
        add_node(arr[i], head, tail);
}

/*
 * yield a visual linked list
 */
void show_list(node* &head, node* &tail)
{
    node *current = head->next;
    
    cout << "head->";
    while ( current != tail ) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "tail" << endl; 
}

/*
 * Method: Use two pointers to nodes with k node(s)
 * between them. When prior pointer moves to tail,
 * posterior pointer points to the right place. 
 */
node* kth_to_last(int k, node* &head, node* &tail)
{
    int interval = -1;  // # of nodes between two pointers
    node *prior = head, *posterior = head;

    assert(k >= 0);
    
    // first, put two pointers in the right places
    while ( interval != k ) {
        prior = prior->next;
        interval++;
    }
    
    // then move the two pointers in the same speed
    while ( prior != tail ) {
        prior = prior->next;
        posterior = posterior->next;
    }
    
    return posterior;
}
 
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    node *head, *tail;
    
    array_to_list(arr, 5, head, tail);
    show_list(head, tail);
    
    // expect 3, 1->2->(3)->4->5
    cout << kth_to_last(2, head, tail)->data << endl;
    
    return 0;
}