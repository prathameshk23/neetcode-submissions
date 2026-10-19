class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].emplace_back(dist, j);
                adj[j].emplace_back(dist, i);
            }
        }

        int res = 0;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.emplace(0, 0);
        while (visited.size() < n) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr.first;
            int i = curr.second;
            if (visited.count(i)) {
                continue;
            }
            res += cost;
            visited.insert(i);
            for (auto &[nc, ni] : adj[i]) {
                if (!visited.count(ni)) {
                    pq.emplace(nc, ni);
                }
            }
        }

        return res;
    }
};
