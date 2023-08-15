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
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0;i < n;i++) {
        cin >> c[i];
    }
    vector<int> adj[n + 1];
    for (int i = 0;i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1e9;
    vector<bool> black(n + 1, false);
    vector<int> dis(n + 1, 1e9);
    function<void(int)> bfs = [&](int x) {
        queue<pair<int, int>> q;
        q.push({ x,0 });
        for (int dist = 0;!q.empty() && dist < ans;dist++) {
            int sz = q.size();
            for (int i = 0;i < sz;i++) {
                auto [u, p] = q.front();
                q.pop();
                if (black[u]) {
                    ans = dist;
                    break;
                }
                for (auto& v : adj[u]) {
                    if (v == p)continue;
                    q.push({ v,u });
                }
            }
        }
    };
    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto& v : adj[u]) {
            if (v == p)continue;
            if (dis[u] + 1 < dis[v] && dis[u] + 1 < ans) {
                dis[v] = dis[u] + 1;
                dfs(v, u);
            }
            else {
                ans = min(ans, dis[u] + dis[v] + 1);
            }
        }
    };

    dis[c[0]] = 0;
    for (int i = 1;i < n;i++) {
        dis[c[i]] = 0;
        dfs(c[i], 0);
        cout << ans << " ";
    }
    cout nl;
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
