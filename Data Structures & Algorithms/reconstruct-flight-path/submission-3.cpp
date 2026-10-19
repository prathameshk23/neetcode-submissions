class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        for (auto &ticket: tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for (auto &[src, dest] : adj) {
            sort(dest.rbegin(), dest.rend());
        }

        vector<string> res; 
        stack<string> st;
        st.push("JFK");

        while(!st.empty()) {
            string curr = st.top();
            if (adj[curr].empty()) {
                res.push_back(curr);
                st.pop();
            } else {
                string next = adj[curr].back();
                adj[curr].pop_back();
                st.push(next);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};