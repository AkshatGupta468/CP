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
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    for (int i = 0;i < k;i++) {
        cin >> x[i];
    }
    vector<int> adj[n + 1];
    for (int i = 0;i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> frnd;
    vector<int> vis(n + 1);
    for (int i = 0;i < k;i++) {
        frnd.push(x[i]);
        vis[x[i]] = 2;
    }
    queue<int> vlad;
    vlad.push(1);
    vis[1] = 1;
    int frndsreq = 0;
    while (!vlad.empty()) {
        int szfrnd = frnd.size();
        for (int i = 0;i < szfrnd;i++) {
            int u = frnd.front();
            frnd.pop();
            for (auto& v : adj[u]) {
                if (vis[v])continue;
                vis[v] = 2;
                frnd.push(v);
            }
        }
        int szvlad = vlad.size();
        for (int i = 0;i < szvlad;i++) {
            int u = vlad.front();
            vlad.pop();
            bool leaf = true;
            for (auto& v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    vlad.push(v);
                    leaf = false;
                }
                else if (vis[v] == 2) {
                    frndsreq++;
                    leaf = false;
                }
            }
            if (leaf)
                return false;
        }
    }
    cout << frndsreq nl;
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
