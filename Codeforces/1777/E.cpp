#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#ifdef __linux__
#include "/media/gakshat468/New Volume/CP/algo/debug.h"
#elif _WIN32
#include "D:/CP/algo/debug.h"
#endif
#else
#define debug(...) 42
#endif
#define MOD 1000000007
#define nl <<'\n'
#define display_vec(a) for(auto i:a)cout<<i<<" "; cout <<"\n";
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#pragma GCC target("popcnt")

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({ w, u, v });
    }
    int l = -1, r = 1e9 + 1;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        vector<int> adj[n + 1];
        for (int i = 0;i < m;i++) {
            auto [w, u, v] = edges[i];
            adj[u].push_back(v);
            if (w <= mid)
                adj[v].push_back(u);
        }
        vector<bool> vis(n + 1);
        int lastDfsOn = 0;
        function<void(int)> dfs = [&](int x) {
            vis[x] = true;
            for (auto& v : adj[x])
                if (!vis[v])
                    dfs(v);
            };

        for (int i = 1;i <= n;i++)
            if (!vis[i]) {
                lastDfsOn = i;
                dfs(i);
            }
        fill(vis.begin(), vis.end(), false);
        dfs(lastDfsOn);
        if (n == accumulate(vis.begin(), vis.end(), 0ll))
            r = mid;
        else
            l = mid;
    }
    if (r == 1e9 + 1)cout << -1 nl;
    else cout << r nl;
    return true;
}

int main()
{
    fast_io;
#ifdef __linux__
    string path = "/media/gakshat468/New Volume/CP/";
#elif _WIN32
    string path = "D:/CP/";
#endif
#ifndef ONLINE_JUDGE
    freopen((path + "input.txt").c_str(), "r", stdin);
    freopen((path + "output.txt").c_str(), "w", stdout);
    freopen((path + "error.txt").c_str(), "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
