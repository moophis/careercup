/**
 * careercup 4.2
 * Given a directed graph, design an algorithm to find out
 * whether there is a route between two nodes.
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * Data structure: graph node
 */
typedef struct _gnode {
    int index;
    vector<_gnode *> adj;
}gnode;

/*
 * Method: using breadth-first search.
 * Input: @src: pointer to source node;
 *        @dst: pointer to destination node.
 * Output: whether there is a route between 
 *         two nodes.
 */
bool bfs(gnode* &src, gnode* &dst)
{
    queue<gnode *> buf;
    
    buf.push(src);
    
    while ( !buf.empty() ) {
        gnode *next = buf.front();
        buf.pop();
        
        for (int i = 0; i < next->adj.size(); i++) {
            if ( next->adj[i] == dst )
                return true;
            buf.push(next->adj[i]);
        }
    }
    
    return false;
}

int main()
{
    gnode **mygraph;
    
    mygraph = new gnode* [5];
    for (int i = 0; i < 5; i++) {
        mygraph[i] = new gnode;
        mygraph[i]->index = i;
    }
    mygraph[0]->adj.push_back(mygraph[1]);
    mygraph[0]->adj.push_back(mygraph[2]);
    mygraph[1]->adj.push_back(mygraph[3]);
    //mygraph[3]->adj.push_back(mygraph[4]);
    
    cout << bfs(mygraph[0], mygraph[4]) << endl;
    
    return 0;
}

