class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<set<int>> components;

        for (auto &edge : edges) {
            int a = edge[0], b = edge[1];
            int firstSet = -1, secondSet = -1;

            // find if a or b already exist in any set
            for (int i = 0; i < components.size(); i++) {
                if (components[i].count(a)) firstSet = i;
                if (components[i].count(b)) secondSet = i;
            }

            if (firstSet == -1 && secondSet == -1) {
                // neither exists → create new set
                components.push_back({a, b});
            } else if (firstSet != -1 && secondSet != -1 && firstSet != secondSet) {
                // both exist in different sets → merge
                components[firstSet].insert(components[secondSet].begin(), components[secondSet].end());
                components.erase(components.begin() + secondSet);
            } else if (firstSet != -1) {
                // only a exists → add b
                components[firstSet].insert(b);
            } else {
                // only b exists → add a
                components[secondSet].insert(a);
            }
        }

        // calculate total nodes in all sets
        int populatedNodes = 0;
        for (auto &s : components) populatedNodes += s.size();

        // number of components + isolated nodes
        return components.size() + (n - populatedNodes);
    }
};
