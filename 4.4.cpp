/**
 * careercup 4.4
 * Given a binary tree, design an algorithm which creates a
 * linked list of all the nodes at each depth (e.g., if you 
 * have a tree with depth D, you¡¯ll have D linked lists).
 */
#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

typedef struct _treenode {
    int key;
    int depth;
    _treenode *left, *right;
}treenode;

/* Use BFS to travel through nodes of all depths */
void create_depth_list(treenode* root, vector<list<treenode*> > &vec)
{
    int cur_depth = 0, thisdepth_num = 1, nextdepth_num = 0;
    treenode *cur_node = root;
    list<treenode *> cur_list;
    queue<treenode *> buf;
    
    if ( !root ) {
        cerr << "This tree is empty!" << endl;
        return;
    }
    
    buf.push(root);
    while ( !buf.empty() ) {
        buf.front()->depth = cur_depth;
        cur_node = buf.front();
        buf.pop();
        
        cur_list.push_back(cur_node);
        
        if ( cur_node->left ) {
            nextdepth_num++;
            buf.push(cur_node->left);
        }
        if ( cur_node->right ) {
            nextdepth_num++;
            buf.push(cur_node->right);
        }
            
        thisdepth_num--;
        if ( thisdepth_num == 0 ) {
            /* assmble the list of this depth into the vector,
               and prepare the data structure for next depth. */
            vec.push_back(cur_list);
            cur_list.resize(0); // remove all nodes for next use
            cur_depth++;
            thisdepth_num = nextdepth_num;
            nextdepth_num = 0;
        }
    }
}

/* Show some stats */
void show_depth_list(vector<list<treenode*> > &vec)
{
    int depth = 0;
    vector<list<treenode*> >::iterator it;
    
    cout << "----------stats----------" << endl;
    for (it = vec.begin(); it != vec.end(); it++) {
        list<treenode*>::iterator lit;
        cout << "At depth " << depth++ << " there are/is: ";
        for (lit = (*it).begin(); lit != (*it).end(); lit++) {
            cout << (*lit)->key << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<list<treenode*> > vec;
#if 0   
    const int node_num = 7;
    treenode mytree[node_num];

    for (int i = 0; i < node_num; i++) 
        mytree[i].key = i;
    mytree[0].left = &mytree[1];
    mytree[0].right = &mytree[2];
    mytree[1].left = &mytree[3];
    mytree[1].right = &mytree[4];
    mytree[2].left = &mytree[5];
    mytree[2].right = &mytree[6];
    for (int i = 3; i <= 6; i++) {
        mytree[i].left = NULL;
        mytree[i].right = NULL;
    }
    
    create_depth_list(&mytree[0], vec);
    show_depth_list(vec);
#endif
    treenode tree[6];
    
    /*
     * test case:
     *     0
          / \
         1   2
            / \
           3  4
               \
                5
     */
    for (int i = 0; i < 6; i++) 
        tree[i].key = i;
    tree[0].left  = &tree[1];
    tree[0].right = &tree[2];
    tree[1].left  = tree[1].right = NULL;
    tree[2].left  = &tree[3];
    tree[2].right = &tree[4];
    tree[3].left  = tree[3].right = NULL;
    tree[4].left  = NULL;
    tree[4].right = &tree[5];;
    tree[5].left  = tree[5].right = NULL;
    
    create_depth_list(&tree[0], vec);
    show_depth_list(vec);
    
    return 0;
}

