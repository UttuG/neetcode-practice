class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        // clone the starting node
        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* nei : curr->neighbors) {
                // if neighbor not cloned yet
                if (!mp.count(nei)) {
                    mp[nei] = new Node(nei->val);
                    q.push(nei);
                }
                // connect clone
                mp[curr]->neighbors.push_back(mp[nei]);
            }
        }

        return mp[node];
    }
};
