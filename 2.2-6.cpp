/**
 * This file includes:
 * careercup 2.2 2.3 2.4 2.5
 */
#include <iostream>
#include <cassert>
#include <stack>

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

/**
 * careercup 2.4
 * Write code to partition a linked list around a value x, 
 * such that all nodes less than x come before all nodes 
 * greater than or equal to x.
 *
 * Method: Use a pointer called middle to divide the list
 * into three parts: (<x) nodes, (=x) nodes and (>x) nodes.
 * For each iteration, move current nodes to the right place.
 * (Should be careful about edge conditions.)
 */
void list_partition(int x, node* &head, node* &tail)
{
    node *current, *temp, *middle;
    /* to make sure that middle always points to 
       the rightmost (<x) node for the most recent
       iteration */
    bool swapped_less_once = false; 
    
    current = middle = head;
    
    assert(x >= 0);
    if ( head->next == tail ) {
        cerr << "Empty linked list!" << endl;
        return;
    }
    
    while ( current->next != tail ) {
        if ( current->next->data < x ) { 
            // put (<x) node right after the head           
            if ( current == head ) {
                swapped_less_once = true;
                middle = current->next;
                current = current->next;
                continue;
            }
            temp = current->next;
            current->next = temp->next;
            temp->next = head->next;
            head->next = temp;
            if ( !swapped_less_once ) {
                swapped_less_once = true;
                middle = temp; // rightmost (<x) node so far
            }
        } else if ( current->next->data == x ) { 
            // put (=x) node right before the last (<x) node so far
            if ( current == head ) {
                current = current->next;
                continue;
            }
            if ( current == middle ) {  // no need to swap
                current = current->next;
                continue;
            }
            temp = current->next;
            current->next = temp->next;
            temp->next = middle->next;
            middle->next = temp;
        } else
            current = current->next;
    }
}

/**
 * careercup 2.5
 * You have two numbers represented by a linked list, where each node 
 * contains a single digit. The digits are stored in reverse order, 
 * such that the 1's digit is at the head of the list. Write a function 
 * that adds the two numbers and returns the sum as a linked list.
 * EXAMPLE
 * Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295
 * Output: 2 -> 1 -> 9. That is, 912.
 * FOLLOW UP
 * Suppose the digits are stored in forward order. Repeat the above problem.
 * EXAMPLE
 * Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
 * Output: 9 -> 1 -> 2. That is, 912.
 *
 */
 /**
  * For digits in reverse order: just add each bit from low to high.
  * Should only take care of carry bit.
  */
void reverse_sum(node* &head1, node* &tail1, node* &head2, node* &tail2)
{
    node *current1 = head1->next, *current2 = head2->next;
    node *sum_head, *sum_tail;
    int carry = 0, thisbit = 0;
    
    init_list(sum_head, sum_tail);
    
    // first, deal with the common length parts of two lists
    while ( current1 != tail1 && current2 != tail2 ) {
        thisbit = current1->data + current2->data + carry;
        carry = thisbit / 10;
        thisbit = thisbit % 10;
        add_node(thisbit, sum_head, sum_tail);
        
        current1 = current1->next;
        current2 = current2->next;
    }
    
    // then deal with extra length (if has) of one list
    if ( current1 == tail1 ) {
        while ( current2 != tail2 ) {
            thisbit = current2->data + carry;
            carry = thisbit / 10;
            thisbit = thisbit % 10;
            add_node(thisbit, sum_head, sum_tail);
            
            current2 = current2->next;
        }
    } else if ( current2 == tail2 ) {
        while ( current1 != tail1 ) {
            thisbit = current1->data + carry;
            carry = thisbit / 10;
            thisbit = thisbit % 10;
            add_node(thisbit, sum_head, sum_tail);
            
            current1 = current1->next;
        }
    }
    if ( carry != 0 ) 
        add_node(carry, sum_head, sum_tail);
        
    // show results
    show_list(sum_head, sum_tail);
}

/**
 * For digits in forward order: use two stacks to make digits 
 * in reverse order.
 */
void forward_sum(node* &head1, node* &tail1, node* &head2, node* &tail2)
{
    stack<int> s1, s2, sum;
    node *current1 = head1->next, *current2 = head2->next;
    node *sum_head, *sum_tail;
    int carry = 0, thisbit = 0;
    
    init_list(sum_head, sum_tail);

    for ( ;current1 != tail1; current1 = current1->next) 
        s1.push(current1->data);
    for ( ;current2 != tail2; current2 = current2->next)
        s2.push(current2->data);

    while ( !s1.empty() && !s2.empty() ) {
        thisbit = s1.top() + s2.top() + carry;
        carry = thisbit / 10;
        thisbit = thisbit % 10;
        add_node(thisbit, sum_head, sum_tail);
        
        s1.pop(); 
        s2.pop();
    }
    
    if ( s1.empty() ) {
        while ( !s2.empty() ) {
            thisbit = s2.top() + carry;
            carry = thisbit / 10;
            thisbit = thisbit % 10;
            sum.push(thisbit);
            
            s2.pop();
        }
    } else if ( s2.empty() ) {
        while ( !s1.empty() ) {
            thisbit = s1.top() + carry;
            carry = thisbit / 10;
            thisbit = thisbit % 10;
            sum.push(thisbit);
            
            s1.pop();
        }
    }
    
    if ( carry != 0 ) 
        sum.push(carry);
        
    while ( !sum.empty() ) {
        add_node(sum.top(), sum_head, sum_tail);
        sum.pop();
    }
    show_list(sum_head, sum_tail);
}

/** 
 * careercup 2.6
 * Given a circular linked list, implement an algorithm which 
 * returns the node at the beginning of the loop.
 * DEFINITION
 * Circular linked list: A (corrupt) linked list in which 
 * a node's next pointer points to an earlier node, so as to 
 * make a loop in the linked list.
 * EXAMPLE
 * Input: A -> B -> C -> D -> E -> C [the same C as earlier]
 * Output: C
 * 
 * Method: Use two pointers. One pointer moves 1 slot per iteration,
 * another 2 slots. If there is a loop in the linked list, they must
 * meet somewhere. When meet, move one pointer back to head, then 
 * move two pointers 1 slot per iteration at the same time. When they 
 * meet again, the node in which they reside is the beginning of the loop.
 */
node* detect_circle(node* &head, node* &tail)
{
    node *slow, *fast;
    bool has_met_once = false; // when two pointers first met, set it true.
    
    slow = fast = head;
    if ( head->next == tail || head->next == head )
        return NULL;
        
    while ( fast != tail && fast->next != tail ) {
        slow = slow->next;
        if ( !has_met_once ) {
            fast = fast->next->next;
            if ( slow == fast ) {
                slow = head;
                has_met_once = true;
            }
        } else {
            fast = fast->next;
            if ( slow == fast ) // meet again
                return slow;
        }
    }
    // loop detected
    return NULL;
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 5};
    node *head, *tail, *current;
    
    array_to_list(arr, 5, head, tail);
    //show_list(head, tail);
#if 0    
    // for 2.2: expect 3, 1->2->(3)->4->5
    cout << "----2.2 results----" << endl;
    cout << kth_to_last(2, head, tail)->data << endl;
    
    // for 2.3
    cout << "----2.3 results----" << endl;
    delete_mid(head, tail);
    show_list(head, tail);
  
    // for 2.4
    cout << "----2.4 results----" << endl;
    list_partition(5, head, tail);
    show_list(head, tail);

    // for 2.5
    cout << "----2.5 results----" << endl;
    int fst[5] = {5, 9, 3, 9, 9};
    int sec[3] = {7, 1, 6};
    node *head1, *head2, *tail1, *tail2;
    
    array_to_list(fst, 5, head1, tail1);
    array_to_list(sec, 3, head2, tail2);
    reverse_sum(head1, tail1, head2, tail2);
    forward_sum(head1, tail1, head2, tail2);
#endif
    // for 2.6
    cout << "----2.6 results----" << endl;
    // make a loop
    node *result;
    current = head;
    while ( current->next != tail ) 
        current = current->next;
    current->next = head->next->next;
    
    if ( !(result = detect_circle(head, tail)) )
        cout << "No loop detected!" << endl;
    else
        cout << "The entry of the loop: " << result->data << endl;
   
    return 0;
}