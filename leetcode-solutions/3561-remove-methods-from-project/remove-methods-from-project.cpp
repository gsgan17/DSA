class Solution {
private:
    vector<vector<int>> get_adjacency_list(int& n, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < invocations.size(); i++) {
            vector<int> call = invocations[i];
            adj[call[0]].push_back(call[1]);
        }

        return adj;
    }

    vector<int> get_remaining_methods(int& n, int& k, vector<vector<int>>& adj) {
        set<int> s;

        vector<bool> visited(n, false);
        dfs(k, adj, s, visited);
        if (no_non_sus_call(adj, s)) {
            return formed_vector(n, s);
        } else {
            return default_vector(n);
        }
        
    }

    vector<int> formed_vector(int& n, set<int>& s) {
        vector<int> v;

        for (int i=0; i<n; i++) {
            if (s.count(i)) {
                continue;
            }
            v.push_back(i);
        }

        return v;
    }

    void dfs(int k, vector<vector<int>>& adj, set<int>& s, vector<bool>& visited) {
        if (visited[k]) {
            return;
        }

        visited[k] = true;
        s.insert(k);
        for(int successor : adj[k]) {
            dfs(successor, adj, s, visited);
        }
    }

    vector<int> default_vector(int& n) {
        vector<int> def_vec(n);
        for(int i=0; i<n; i++) {
            def_vec[i] = i;
        }
        return def_vec;
    }

    bool no_non_sus_call(vector<vector<int>>& adj, set<int>& s) {
        for (int i = 0; i<adj.size(); i++) {
            for(int j : adj[i]) {
                if (s.count(i) == 0 && s.count(j) != 0) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj = get_adjacency_list(n, invocations);
        vector<int> remaining_methods = get_remaining_methods(n, k, adj);
        return remaining_methods;
    }
};