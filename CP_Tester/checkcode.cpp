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

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

bool solve()
{
    int n;
    cin >> n;
    vector<vector<int>> p(n + 1, vector<int>(n + 1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++)
            cin >> p[i][j];
    }
    adj.resize(n + 1);
    adj_rev.resize(n + 1);
    for (int i = 1;i <= n;i++) {
        int j;
        for (j = 1;p[i][j] != i;j++);
        for (int k = 1;k < j;k++) {
            adj[i].push_back(p[i][k]);
            adj_rev[p[i][k]].push_back(i);
        }
    }
    debug(adj);
    debug(adj_rev);
    used.assign(n + 1, false);

    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> compof(n + 1);
    for (auto v : order)
        if (!used[v]) {
            dfs2(v);
            for (auto& i : component)
                compof[i] = v;
            component.clear();
        }

    for (int i = 1;i <= n;i++) {
        int j;
        for (j = 1;j <= n;j++) {
            if (compof[p[i][j]] == compof[i])break;
        }
        cout << p[i][j] nl;
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
