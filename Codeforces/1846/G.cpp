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
    string initialSymptoms;
    cin >> initialSymptoms;
    vector<bool> vis(1 << n);
    vector<int> dis(1 << n, 1e9);
    vector<tuple<int, int, int>> medicines;
    for (int i = 0;i < m;i++) {
        int d;
        string removeSymptom, sideEffects;
        cin >> d >> removeSymptom >> sideEffects;
        medicines.push_back({ d,stoi(removeSymptom,0,2),stoi(sideEffects,0,2) });
    }

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int start = stoi(initialSymptoms, 0, 2);
    dis[start] = 0;
    pq.push({ dis[start], start });
    while (!pq.empty() && !vis[0]) {
        auto [d, x] = pq.top();
        pq.pop();
        if (vis[x])continue;
        vis[x] = true;
        for (auto& [dw, u, v] : medicines) {
            int y = (x ^ (x & u)) | v;
            if (dis[x] + dw < dis[y]) {
                dis[y] = dis[x] + dw;
                pq.push({ dis[y],y });
            }
        }
    }
    if (!vis[0])return false;
    cout << dis[0] nl;
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
        // cout << (solve() ? "YES\n" : "NO\n");
        cout << (solve() ? "" : "-1\n");
    }
}
