int n, q;
cin >> n >> q;
vector<pair<int, int>> adj[n + 1];

for (int i = 0;i < n - 1;i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({ v,w });
    adj[v].push_back({ u,w });
}

vector<int> subtreesize(n + 1, 1), torootXor(n + 1, 0), dscn[n + 1];
unordered_map<int, int> cnt;
function<void(int, int)> calToRootXor = [&](int u, int p) {
    for (auto& [v, w] : adj[u]) {
        if (v == p)continue;
        torootXor[v] = torootXor[u] ^ w;
        calToRootXor(v, u);
        subtreesize[u] += subtreesize[v];
    }
};

calToRootXor(1, 0);
for (auto& i : torootXor)
cnt[i] = 0;
vector<long> ans(n + 1);
function<void(int, int, bool)> dfs = [&](int u, int p, bool keep) {
    int bigchild = -1;
    for (auto& [v, w] : adj[u]) {
        if (v == p)continue;
        if (bigchild == -1 || subtreesize[bigchild] < subtreesize[v])
            bigchild = v;
    }

    for (auto& [v, w] : adj[u]) {
        if (v == p)continue;
        if (v != bigchild)
            dfs(v, u, false);
    }

    if (bigchild != -1) {
        dfs(bigchild, u, true);
        swap(dscn[u], dscn[bigchild]);
        ans[u] += ans[bigchild];
    }

    dscn[u].push_back(u);
    ans[u] += cnt[torootXor[u]];
    cnt[torootXor[u]]++;
    for (auto& [v, w] : adj[u]) {
        if (v == p || v == bigchild)continue;
        for (auto& i : dscn[v]) {
            ans[u] += cnt[torootXor[i]];
            cnt[torootXor[i]]++;
            dscn[u].push_back(i);
        }
    }
    if (!keep) {
        for (auto& v : dscn[u]) {
            cnt[torootXor[v]]--;
        }
    }
};

dfs(1, 0, true);
debug(ans);
while (q--) {
    int u;
    cin >> u;
    cout << ans[u] nl;
}