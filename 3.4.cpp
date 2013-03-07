/**
 * careercup 3.4
 * In the classic problem of the Towers of Hanoi, you have 3 towers 
 * and N disks of different sizes which can slide onto any tower. 
 * The puzzle starts with disks sorted in ascending order of size 
 * from top to bottom (i.e., each disk sits on top of an even larger one). 
 * You have the following constraints:
 * (1) Only one disk can be moved at a time.
 * (2) A disk is slid off the top of one tower onto the next tower.
 * (3) A disk can only be placed on top of a larger disk.
 * Write a program to move the disks from the first tower to 
 * the last using stacks.
 */
#include <iostream>
#include <stack>

using namespace std;

/**
 * This method is borrowed from Wikipedia...
 *
 * Alternating between the smallest and the next-smallest disks, 
 * follow the steps for the appropriate case:
 *
 * For an even number of disks:
 *
 * make the legal move between pegs A and B
 * make the legal move between pegs A and C
 * make the legal move between pegs B and C
 * repeat until complete
 * For an odd number of disks:
 *
 * make the legal move between pegs A and C
 * make the legal move between pegs A and B
 * make the legal move between pegs C and B
 * repeat until complete
 * In each case, a total of 2^n-1 moves are made.
 */
 
void hanoi_tower(stack<int> peg[])
{
    int disk_num;
    
    if ( !peg[1].empty() || !peg[2].empty() ) {
        cerr << "Not a legal tower!" << endl;
        return;
    }
    
    if ( peg[0].empty() ) {
        cerr << "Empty tower!" << endl;
        return;
    }
    
    disk_num = peg[0].size();
    if ( disk_num % 2 == 0 ) {
        for (int i = 0; peg[2].size() != disk_num; i++) {
            switch (i % 3) {
            case 0: // A and B
                if ( peg[1].empty() || 
                       !peg[0].empty() && peg[0].top() < peg[1].top() ) {
                    // A to B
                    peg[1].push(peg[0].top());
                    peg[0].pop();
                } else if ( peg[0].empty() ||
                               peg[0].top() > peg[1].top() ) {
                    // B to A
                    peg[0].push(peg[1].top());
                    peg[1].pop();
                } 
                break;
            case 1: // A and C
                if ( peg[2].empty() || 
                       !peg[0].empty() && peg[0].top() < peg[2].top() ) {
                    // A to C
                    peg[2].push(peg[0].top());
                    peg[0].pop();
                } else if ( peg[0].empty() ||
                               peg[0].top() > peg[2].top() ) {
                    // C to A
                    peg[0].push(peg[2].top());
                    peg[2].pop();
                } 
                break;
            case 2: // B and C
                if ( peg[2].empty() || 
                       !peg[1].empty() && peg[1].top() < peg[2].top() ) {
                    // B to C
                    peg[2].push(peg[1].top());
                    peg[1].pop();
                } else if ( peg[1].empty() ||
                               peg[1].top() > peg[2].top() ) {
                    // C to B
                    peg[1].push(peg[2].top());
                    peg[2].pop();
                } 
                break;
            default:
                break;
            }
        }
    } else {
        // forgive my laziness...
    }
}

int main()
{
    stack<int> peg[3];
    
    for (int i = 4; i > 0; i--) 
        peg[0].push(i);
    hanoi_tower(peg);
    for (int i = 4; i > 0; i--) {
        cout << peg[2].top() << " ";
        peg[2].pop();
    }
    
    return 0;
}

