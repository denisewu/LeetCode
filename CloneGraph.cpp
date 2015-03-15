/**
lone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
         
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return node;
            
        unordered_map<int, UndirectedGraphNode *> nodes;
       
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while(!q.empty())
        {
            UndirectedGraphNode *p = q.front();
            q.pop();
            if(nodes.find(p->label) == nodes.end())
            {
                UndirectedGraphNode * newp = new UndirectedGraphNode(p->label);
                nodes.insert(pair<int, UndirectedGraphNode*>(newp->label, newp));
                vector<UndirectedGraphNode *>:: iterator it = p->neighbors.begin();
                for(; it != p->neighbors.end(); it++)
                {
                    q.push((*it));
                }
            }
        }
        q.push(node);
        while(!q.empty())
        {
            UndirectedGraphNode *p = q.front();
            q.pop();
            UndirectedGraphNode *existp = nodes[p->label];
            if(existp->neighbors.empty() && !p->neighbors.empty())
            {
                vector<UndirectedGraphNode *> newNeighbors;
                for(int i = 0; i < p->neighbors.size(); i++)
                {
                    newNeighbors.push_back(nodes[p->neighbors[i]->label]);
                    q.push(p->neighbors[i]);
                }
                existp->neighbors = newNeighbors;
            }
        }
        return nodes[node->label];
    }
};
