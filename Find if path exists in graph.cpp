class Solution2 {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        return bfs(adj, start, end) >= 0;
    }

private:
    int bfs(const unordered_map<int, vector<int>>& adj,
               const int start,
               const int target) {
        vector<int> q = {start};
        unordered_set<int> lookup;
        int steps = 0;
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& pos : q) {
                if (pos == target) {
                    return steps;
                }
                if (!adj.count(pos)) {
                    continue;
                }
                for (const auto& nei : adj.at(pos)) {
                    if (lookup.count(nei)) {
                        continue;
                    }
                    lookup.emplace(nei);
                    new_q.emplace_back(nei);
                }
            }
            q = move(new_q);
            ++steps;
        }
        return -1;
    }
};
