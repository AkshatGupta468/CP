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
    vector<int> a(n + 1);
    vector<int> pos = { 0 };
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        pos.push_back(a[i]);
    }
    int m = pos.size() - 1;
    vector<vector<pair<int, int>>> dp(m + 1, vector < pair<int, int>>(n + 3, {}));
    // [ballno][pos]{min_moves,no_of_ways}
    dp[0][0] = { 0,1 };
    for (int i = 1;i < m;i++) {
        for (int j = 1;j <= n;j++) {
            dp[i][j] = dp[i - 1][j - 1]
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
    cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
