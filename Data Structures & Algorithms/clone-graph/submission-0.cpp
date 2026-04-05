/*
// Definition for a Node.
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

class Solution {
public:
    Node* cloneGraph(Node* node) {

        // maintain a hashmap for old to new node mapping
        unordered_map<Node*,Node*> nodes;

        // make a queue of node to visit
        queue<Node*> tovisit;

        // make a set of visited nodes
        unordered_set<Node*> visited;

        //initial population of the queue
        if (node){
            tovisit.push(node);
        }
        else{
            return nullptr; //the graph is empty
        }

        // for each node in the queue
        while (tovisit.size()>=1){
            // check if the node is visited in the set, if yes continue the loop else proceed 
            Node* curr_node = tovisit.front();
            tovisit.pop();

            if (visited.count(curr_node)){
                continue;
            }
            else{
                visited.insert(curr_node);
            }

            // check if it already has a copy made in the hashmap, if not make, update and procced below
            Node* new_node;
            if (!nodes.count(curr_node)){
                new_node = new Node(curr_node->val);
                nodes[curr_node] = new_node;
            }
            else{
                new_node = nodes[curr_node];
            }
            // add its neighbours in the queue too
            // make a new node for each neighbour that is not in the hashmap and then fill up the neighbour array for the looping node
            for (Node* node_:curr_node->neighbors){
                tovisit.push(node_);
                if (!nodes.count(node_)){
                    Node* newnode = new Node(node_->val);
                    nodes[node_] = newnode;
                }
                new_node->neighbors.push_back(nodes[node_]);
            }

        }
        return nodes[node];
    }
};
