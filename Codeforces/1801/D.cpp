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
#define int long long int
#pragma GCC target("popcnt")
const int inf = 1e14;
bool solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> w(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
    }

    w[n] = 1e9 + 1;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0;i < m;i++) {
        int a, b, s;
        cin >> a >> b >> s;
        adj[a].push_back({ b,s });
    }

    vector<int> travOrder(n);
    for (int i = 1;i <= n;i++) {
        travOrder[i - 1] = i;
    }
    sort(travOrder.begin(), travOrder.end(), [&](auto l, auto r) {return w[l] < w[r];});
    vector<int> mindays(n + 1, -1);
    vector<int> maxBudget(n + 1, 0);
    mindays[1] = 0;
    maxBudget[1] = p;
    for (int i = 0;i < travOrder.size();i++) {
        auto u = travOrder[i];
        if (mindays[u] == -1)continue;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n + 1, -1);
        dis[u] = 0;
        pq.push({ dis[u],u });
        while (!pq.empty()) {
            auto [wx, x] = pq.top();
            pq.pop();
            if (wx > dis[x])continue;
            for (auto& [v, sxv] : adj[x]) {
                if (dis[v] == -1 || dis[v] > dis[x] + sxv) {
                    dis[v] = dis[x] + sxv;
                    pq.push({ dis[v],v });
                }
            }
        }
        for (int j = 0;j < travOrder.size();j++) {
            auto v = travOrder[j];
            if (w[v] <= w[u])continue;
            if (dis[v] == -1)continue;
            int tdays = mindays[u] + (dis[v] - maxBudget[u] + w[u] - 1) / w[u];
            if (dis[v] < maxBudget[u]) tdays = mindays[u];
            int tBudget = maxBudget[u] + (tdays - mindays[u]) * w[u] - dis[v];
            if (mindays[v] == -1 || tdays < mindays[v]) {
                mindays[v] = tdays;
                maxBudget[v] = tBudget;
            }
            else if (tdays == mindays[v]) {
                maxBudget[v] = max(maxBudget[v], tBudget);
            }
        }
    }

    cout << mindays[n] nl;
    return true;
}

signed main()
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
