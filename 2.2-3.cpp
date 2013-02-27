/**
 * This file include:
 * careercup 2.2 2.3
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

/**
 * careercup 2.2
 * Implement an algorithm to find the kth 
 * to last element of a singly linked list.
 *
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

/**
 * careercup 2.3
 * Implement an algorithm to delete a node in the middle 
 * of a singly linked list, given only access to that node.
 * EXAMPLE
 * Input: the node c from the linked list a->b->c->d->e
 * Result: nothing is returned, but the new linked list looks 
 * like a->b->d->e
 *
 * Method: Use three pointers to travel through the list such that
 * when the most prior pointer reaches the tail, the middle pointer
 * points to middle node, followed by the last pointer for deleting
 * the middle.
 */
void delete_mid(node* &head, node* &tail)
{
    int mid_step = 0;   // # of steps the middle pointer moves
    node *prior, *middle, *posterior;
    prior = middle = posterior = head;
    
    // empty linked list
    if ( head->next == tail ) {
        cerr << "Empty linked list!" << endl;
        return;
    }
    
    // now move the three pointers accordingly
    do {
        prior = prior->next;
        middle = middle->next;
        mid_step++;
        if ( mid_step > 1 ) // now the posterior can move
            posterior = posterior->next;
        if ( prior != tail ) // in case of moving beyond tail
            prior = prior->next;
    } while ( prior != tail );
    
    // delete the middle node pointed by posterior
#if 0
    cout << "prior: " << prior->data << " "
         << "middle: " << middle->data << " " 
         << "posterior: " << posterior->data << endl;
#endif
    posterior->next = middle->next;
}
 
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    node *head, *tail;
    
    array_to_list(arr, 5, head, tail);
    show_list(head, tail);
    
    // for 2.2: expect 3, 1->2->(3)->4->5
    cout << "----2.2 results----" << endl;
    cout << kth_to_last(2, head, tail)->data << endl;
    
    // for 2.3
    cout << "----2.3 results----" << endl;
    delete_mid(head, tail);
    show_list(head, tail);
    return 0;
}