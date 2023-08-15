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
    vector<int> radj[n + 1];
    vector<int> outdeg(n + 1);
    vector<int> ans(n + 1, 1);
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        outdeg[u]++;
        radj[v].push_back(u);
    }

    queue<int> q;
    for (int i = 1;i <= n;i++) {
        if (outdeg[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto& u : radj[x]) {
            outdeg[u]--;
            ans[u] += ans[x];
            if (outdeg[u] == 0)q.push(u);
        }
    }
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
