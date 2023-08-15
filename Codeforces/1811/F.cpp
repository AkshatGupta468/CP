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
    vector<int> adj[n + 1];
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> deg4;
    for (int i = 1;i <= n;i++) {
        if (adj[i].size() != 4 && adj[i].size() != 2)return false;
        if (adj[i].size() == 4)deg4.push_back(i);
    }
    if (deg4.empty())return false;
    vector<bool> vis(n + 1);
    int k = 0, p = deg4[0];
    for (;!vis[p];k++) {
        vis[p] = true;
        for (auto& v : adj[p]) {
            if (!vis[v] && adj[v].size() == 4) {
                p = v;
                break;
            }
        }
    }

    for (auto& v : deg4)if (!vis[v])return false;
    if (deg4.size() != k)return false;
    for (auto& v : deg4) {
        int i = 0, x = v;
        vis[v] = false;
        for (;i < k;i++) {
            if (vis[x])break;
            vis[x] = true;
            for (auto& y : adj[x]) {
                if (!vis[y] && adj[y].size() == 2) {
                    x = y;
                    break;
                }
            }
        }
        bool isbesideV = false;
        for (auto& y : adj[x]) {
            if (v == y)isbesideV = true;
        }
        if (i != k || !isbesideV)return false;
    }

    for (int i = 1;i <= n;i++)if (!vis[i])return false;

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
        // solve();
        cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}