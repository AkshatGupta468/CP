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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<bitset<sz>> dp(n + 1);
    vector<bool> vis(n + 1, false);
    function<void(int)> dfs = [&](int x) {
        vis[x] = true;
        dp[x].set(x);
        for (auto& v : adj[x]) {
            if (!vis[v])
                dfs(v);
            dp[x] = dp[x] | dp[v];
        }
    };
    for (int i = 1;i <= n;i++) {
        if (!vis[i])
            dfs(i);
    }
    for (int i = 1;i <= n;i++) {
        cout << dp[i].count() << " ";
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
    // cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
