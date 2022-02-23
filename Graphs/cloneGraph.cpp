// Clone graph: https://leetcode.com/problems/clone-graph/
//              https://leetcode.com/problems/clone-graph/discuss/1792845/C%2B%2B-oror-DFS-oror-Recursively-oror-HashMap-oror-Easy-To-Understand

/*
Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *clone(Node *node, unordered_map<int, Node *> &visited)
    {
        Node *newNode = new Node(node->val);

        // After creating the node we mark the node as visited
        visited[node->val] = newNode;

        // Looking for all the neighbours of node which are created
        for (Node *n : node->neighbors)
        {
            auto it = visited.find(n->val);

            // If neighbour not visited
            if (it == visited.end())
            {
                // Recusive call
                Node *cn = clone(n, visited);

                // Insert it in neighbour of current node
                newNode->neighbors.push_back(cn);
            }
            // If already visited
            else
                newNode->neighbors.push_back(it->second);
        }

        return newNode;
    }

    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        unordered_map<int, Node *> visited;

        return clone(node, visited);
    }
};

// A simple DFS solution
class Solution2
{
    unordered_map<Node *, Node *> copy;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        
        // If node not visited
        if(copy.find(node) == copy.end())
        {
            copy[node] = new Node(node -> val);

            // Looking for all neighbours of node
            for(Node *n: node -> neighbors)
                copy[node] -> neighbors.push_back(cloneGraph(neighbor));    // Recusively calling and appending the obtained neighbor nodes

            return copy[node];
        }
    }
};