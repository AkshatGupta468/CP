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
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    s = "#" + s + '#';
    vector<pair<int, int>> tRange(m + 1);
    vector<int> upd[n + 2];
    for (int i = 1;i <= m;i++) {
        cin >> tRange[i].first >> tRange[i].second;
        upd[tRange[i].first].push_back(i);
        upd[tRange[i].second + 1].push_back(-i);
    }
    set<int> active;
    vector<pair<int, int>> snew(n + 1, { m + 1,0 });
    snew[0] = { -1,0 };
    int onecnt = 0;
    for (int i = 1;i <= n;i++) {
        onecnt += s[i] == '1';
        snew[i].second = i;
        for (auto& u : upd[i]) {
            if (u > 0)
                active.insert(u);
            else
                active.erase(-u);
        }
        if (active.empty())continue;
        snew[i].first = *active.begin();
    }
    sort(snew.begin(), snew.end());
    vector<int> posmap(n + 1, n + 1);
    for (int i = 1;i <= n && snew[i].first < m + 1;i++) {
        posmap[snew[i].second] = i;
    }

    int movesRequired = 0;
    for (int i = 1;i <= onecnt && snew[i].first < m + 1;i++) {
        movesRequired += s[snew[i].second] == '0';
    }
    while (q--) {
        int x;
        cin >> x;
        if (s[x] == '1') {
            if (snew[onecnt].first < m + 1)
                movesRequired -= s[snew[onecnt].second] == '0';
            onecnt--;
            if (posmap[x] <= onecnt)movesRequired++;
            s[x] = '0';
        }
        else {
            onecnt++;
            if (snew[onecnt].first < m + 1)
                movesRequired += s[snew[onecnt].second] == '0';
            if (posmap[x] <= onecnt)movesRequired--;
            s[x] = '1';
        }
        cout << movesRequired nl;
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
