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
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> vis(m + 1);
    int ans = 1e9;
    for (int l = 0, r = 0, windowCnt = 0;;) {
        if (windowCnt < m) {
            if (r == n)break;
            int x = a[r];
            for (int i = 1;i * i <= x;i++) {
                if (x % i)continue;
                if (i <= m) {
                    windowCnt += !vis[i];
                    vis[i]++;
                }
                if (i != x / i && x / i <= m) {
                    windowCnt += !vis[x / i];
                    vis[x / i]++;
                }
            }
            r++;
        }
        else {
            ans = min(ans, a[r - 1] - a[l]);
            int x = a[l];
            for (int i = 1;i * i <= x;i++) {
                if (x % i)continue;
                if (i <= m) {
                    vis[i]--;
                    windowCnt -= !vis[i];
                }
                if (i != x / i && x / i <= m) {
                    vis[x / i]--;
                    windowCnt -= !vis[x / i];
                }
            }
            l++;
        }
    }
    if (ans < 1e9)cout << ans nl;
    else cout << -1 nl;

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
