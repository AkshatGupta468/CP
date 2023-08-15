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
bool compBySecond(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
int getmask(string s) {
    int mask = 0;
    for (auto& j : s) {
        mask |= 1 << (j - 'a');
    }
    return mask;
}

bool solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "#" + s + "#";
    vector<string> p(k);
    vector<int> maskp(k);
    const int alphabetLim = 20;
    vector<int> vis(1 << alphabetLim, -1);
    for (int i = 0;i < k;i++) {
        cin >> p[i];
        maskp[i] = getmask(p[i]);
        vis[maskp[i]] = i;
    }
    for (int i = vis.size() - 1;i >= 0;i--) {
        if (vis[i] == -1)continue;
        for (int p = 1 << (alphabetLim - 1);p > 0;p >>= 1) {
            vis[~p & i] = vis[i];
        }
    }
    vector<pair<int, int>> dp(n + 1, { 1e9,-1 });
    dp[0].first = 0;
    vector<pair<int, int>> lastpos(alphabetLim);
    for (int i = 0;i < lastpos.size();i++)
        lastpos[i].second = i;
    for (int i = 1;i <= n;i++) {
        lastpos[s[i] - 'a'].first = i;
        sort(lastpos.begin(), lastpos.end(), greater<pair<int, int>>());
        int mask = 0;
        for (int j = 0;j < lastpos.size() - 1;j++) {
            mask |= 1 << lastpos[j].second;
            if (vis[mask] != -1 && dp[i].first > dp[lastpos[j + 1].first].first + 1) {
                dp[i].first = dp[lastpos[j + 1].first].first + 1;
                dp[i].second = vis[mask];
            }
        }
        mask |= 1 << lastpos.back().second;
        if (vis[mask] != -1)
            dp[i].second = vis[mask];
        sort(lastpos.begin(), lastpos.end(), compBySecond);
    }
    int mask = 0;
    vector<int> ans;
    for (int i = n;i >= 1;i--) {
        if (!(mask & (1 << (s[i] - 'a')))) {
            mask = maskp[dp[i].second];
        }
        ans.push_back(vis[mask] + 1);
    }
    reverse(ans.begin(), ans.end());
    display_vec(ans);
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
