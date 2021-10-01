
struct SCC{
    vector<int> tin, low, id;
    int n, timer, numSCC;
    stack<int> s;
    void init(int _n) {
        n = _n;
        timer = 0, numSCC = 0;
        tin.assign(n, -1), low.assign(n, -1), id.resize(n);
    }
    //Uses dfs low-linking to build the strongly connected components
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
    //Call this function to build the strongly connected components
    void createStronglyConnectedComponents(vector<vector<int>> &g) {
        //Standard depth first search to find the components
        for (int i = 0; i < n; ++i) {
            if (tin[i] == -1) {
                dfs(i, g);
            }
        }
    }
    //This function returns the strongly connected components, with component 
    //belonging to same ID in a single vector
    vector<vector<int>> getStronglyConnectedComponents() {
        //numSCC is the count of number of strongly connected components
        vector<vector<int>> comps(numSCC);
        //So we iterate over all vertices and add it to the id[vertex] vector.
        for (int i = 0; i < n; ++i) {
            comps[id[i]].push_back(i);
        }
        return comps;
    }
    // Creates the meta graph of SCC in 0-based indexing
    vector<vector<int>> createMetaGraph(const vector<vector<int>> &g) {
        vector<vector<int>> meta(numSCC);
        //We will iterate over all edges and if they don't belong to same component
        //i.e, their ID'S are different, then we will add and edge between them in meta graph
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
