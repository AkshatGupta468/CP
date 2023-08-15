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

bool solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    vector <int> s(n + 2), x(n + 2);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    vector<int> lnz(n + 2), rnz(n + 2);
    int nonzero = 0;
    for (int i = 1;i <= n;i++) {
        s[i] = s[i - 1] + a[i];
        x[i] = x[i - 1] ^ a[i];
        lnz[i] = nonzero;
        if (a[i] != 0)
            nonzero = i;
    }
    nonzero = n + 1;
    for (int i = n;i >= 1;i--) {
        rnz[i] = nonzero;
        if (a[i] != 0)nonzero = i;
    }
    debug(a, s, x);

    while (q--) {
        int L, R;
        cin >> L >> R;
        L--;
        cerr nl;
        debug(L, R);
        if (s[R] - s[L] - (x[R] ^ x[L]) == 0) {
            cout << R sp R nl;
            continue;
        }
        int ansl = L, ansr = R;
        int l = L, r = R;
        for (int i = 0;rnz[l + 1] <= r && i < 35;i++) {
            l = rnz[l + 1] - 1;
        }
        while (1) {
            debug(l, r);
            if (s[R] - s[L] - (x[R] ^ x[L]) == s[r] - s[l] - (x[r] ^ x[l]) && l < lnz[r]) {
                if (r - l < ansr - ansl)ansr = r, ansl = l;
                debug("eq");
                r = lnz[r];
            }
            else if (lnz[l + 1] - 1 < L)break;
            else l = lnz[l + 1] - 1;
        }
        cout << ansl + 1  sp ansr nl;
    }
    cerr nl nl nl nl;
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