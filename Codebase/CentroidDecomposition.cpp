vector<int> sz(n + 1, 1);
function<void(int, int)> getsz = [&](int u, int p) {
    for (auto& v : adj[u])
        if (v != p) {
            getsz(v, u);
            sz[u] += sz[v];
        }
};
getsz(1, 0);
vector<bool> removed(n + 1, false);
function<int(int, int)> getcentroid = [&](int u, int n)->int {
    for (auto& v : adj[u]) {
        if (sz[v] > n / 2) {
            sz[u] -= sz[v];
            sz[v] += sz[u];
            return getcentroid(v, n);
        }
    }
    return u;
};
vector<char> ans(n + 1);
function<void(int, int)> dfs = [&](int u, char c) {
    u = getcentroid(u, sz[u]);
    removed[u] = true;
    sz[u] = 0;
    ans[u] = c;
    for (auto& v : adj[u]) {
        if (!removed[v])
            dfs(v, c + 1);
    }
};