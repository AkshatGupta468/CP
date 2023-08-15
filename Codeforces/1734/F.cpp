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
#define int unsigned long long
int msb(int n) {
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    return (n + 1ll) >> 1;
}

int lsb(int n) {
    return n & -n;
}

bool solve()
{
    int n, m;
    cin >> n >> m;
    debug(n, m);
    int ans = 0;
    for (int p = 1;p < (1ull << 63);p <<= 1) {
        if (p & n) {
            if (p > m) {
                debug(p, m, n, (__builtin_popcountll(n) & 1) * m, "p>m");
                ans += (__builtin_popcountll(n) & 1) * m;
                break;
            }
            else {
                debug(p, m, n, (__builtin_popcountll(n) & 1) * p, "p<=m");
                ans += (__builtin_popcountll(n) & 1) * p;
                m -= p;
                n += p;
            }
        }
    }
    cout << ans nl;
    cerr nl;
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
