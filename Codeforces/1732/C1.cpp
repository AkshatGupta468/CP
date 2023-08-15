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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    vector<int> nzerocnt(n + 2);
    vector <int> s(n + 2), x(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    for (int i = 1;i <= n;i++) {
        s[i] = s[i - 1] + a[i];
        x[i] = x[i - 1] ^ a[i];
        nzerocnt[i] = nzerocnt[i - 1] + (a[i] != 0);
    }


    while (q--) {
        int L, R;
        cin >> L >> R;
        R = lower_bound(nzerocnt.begin(), nzerocnt.begin() + R, nzerocnt[R]) - nzerocnt.begin();
        L = lower_bound(nzerocnt.begin(), nzerocnt.begin() + L, nzerocnt[L] - 1) - nzerocnt.begin();
        int ansl = L, ansr = R;
        ll r = R;
        ll l = lower_bound(nzerocnt.begin(), nzerocnt.begin() + R, nzerocnt[L] + 32) - nzerocnt.begin();
        while (1) {
            debug(l, r);
            if (s[R] - s[L] - x[R] + x[L] == s[r] - s[l] - x[r] + x[l] && r - l >= 1) {
                if (r - l < ansr - ansl)ansr = r, ansl = l;
                r = lower_bound(nzerocnt.begin(), nzerocnt.begin() + r, nzerocnt[r] - 1) - nzerocnt.begin();
            }
            else if (l <= L)break;
            else l = lower_bound(nzerocnt.begin(), nzerocnt.begin() + l, nzerocnt[l] - 1) - nzerocnt.begin();
        }
        debug(s[R] - s[L] - x[R] + x[L], s[ansr] - s[ansl] - x[ansr] + x[ansl]);
        ansl = lower_bound(nzerocnt.begin(), nzerocnt.end(), nzerocnt[ansl] + 1) - nzerocnt.begin();
        cout << ansl  sp ansr nl;
        cerr nl;
    }
    cerr nl nl nl;
    cout nl;
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
