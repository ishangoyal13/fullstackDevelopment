
struct SCC{
    vector<int> tin, low, id;
    int n, timer, numSCC;
    stack<int> s;
    void init(int _n) {
        n = _n;
        timer = 0, numSCC = 0;
        tin.assign(n, -1), low.assign(n, -1), id.resize(n);
    }
    void dfs(int i, const vector<vector<int>> &g) {
        s.push(i);
        tin[i] = low[i] = timer++;
        for (int j: g[i]) {
            if (tin[j] == -1) {
                dfs(j, g);
            }
            low[i] = min(low[i], low[j]);
        }
        if (low[i] == tin[i]) {
            while (true) {
                int x = s.top();
                s.pop();
                id[x] = numSCC;
                low[x] = n;
                if (x == i) break;
            }
            numSCC++;
        }
    }
    void createStronglyConnectedComponents(vector<vector<int>> &g) {
        for (int i = 0; i < n; ++i) {
            if (tin[i] == -1) {
                dfs(i, g);
            }
        }
    }
    vector<vector<int>> getStronglyConnectedComponents() {
        vector<vector<int>> comps(numSCC);
        for (int i = 0; i < n; ++i) {
            comps[id[i]].push_back(i);
        }
        return comps;
    }
    // Creates the meta graph of SCC in 0-based indexing
    vector<vector<int>> createMetaGraph(const vector<vector<int>> &g) {
        vector<vector<int>> meta(numSCC);
        for (int i = 0; i < n; ++i) {
            for (int j: g[i]) {
                if (id[i] != id[j]) {
                    meta[id[i]].push_back(id[j]);
                }
            }
        }
        return meta;
    }
};
