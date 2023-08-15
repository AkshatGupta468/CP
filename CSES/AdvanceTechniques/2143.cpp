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
const int sz = 5e4 + 1;

bool solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> adj[n + 1], radj[n + 1];
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vector<int> dfsorder;
    {
        vector<int> vis(n + 1);
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            for (auto& v : adj[u]) {
                if (vis[v])continue;
                dfs(v);
            }
            dfsorder.push_back(u);
        };
        for (int i = 1;i <= n;i++) {
            if (!vis[i])dfs(i);
        }
    }
    reverse(dfsorder.begin(), dfsorder.end());
    debug(dfsorder);
    vector<int> comp(n + 1);
    {
        vector<int> vis(n + 1);
        function<void(int, int)> dfs = [&](int u, int compno) {
            vis[u] = true;
            comp[u] = compno;
            for (auto& v : radj[u]) {
                if (vis[v])continue;
                dfs(v, compno);
            }
        };
        for (auto i : dfsorder) {
            if (!vis[i]) {
                dfs(i, i);
            }
        }
    }
    debug(comp);
    vector<bitset<sz>> dp(n + 1);
    {
        vector<bool> vis(n + 1, false);
        function<void(int)> dfs = [&](int x) {
            vis[x] = true;
            dp[comp[x]].set(x);
            for (auto& v : adj[x]) {
                if (!vis[v])
                    dfs(v);
                dp[comp[x]] = dp[comp[x]] | dp[comp[v]];
            }
        };
        for (int i = 1;i <= n;i++) {
            if (!vis[i])
                dfs(i);
        }
    }
    debug(dp);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (dp[comp[u]][v]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

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
    // cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
