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
#define MOD 998244353
#define nl <<'\n'
#define display_vec(a) for(auto i:a)cout<<i<<" "; cout <<"\n";
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long int
#pragma GCC target("popcnt")
vector<int> fac;
int binaryExp(int a, int b, int M)
{
    // base a
    //power b
    //modular M
    //(a^b)%M

    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1ll * a) % M;
        }
        a = (a * 1ll * a) % M;
        b >>= 1;
    }
    return ans;
}


bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> d[i];
    }
    for (int i = 1;i <= n;i++) {
        d[i] += d[i - 1];
    }

    int p = 0, s = 0;
    for (int i = 0;i < n && d[n] % 2 == 0;i++) {
        if (binary_search(d.begin(), d.end(), d[i] - d[n] / 2)) {
            s--;p++;
        }
        else s++;
    }

    fac.resize(1 + max(p, m), 1);
    for (int i = 2;i < fac.size();i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    function<int(int, int)> ncr = [&](int n, int r)->int {
        return fac[n] * binaryExp((fac[r] * fac[n - r]) % MOD, MOD - 2, MOD) % MOD;
        };

    int ans = 0;
    for (int r = 0;r <= p && r <= m;r++) {
        ans = (ans + ncr(p, r) * ncr(m, r) % MOD * binaryExp((m - r) * (m - r - 1) % MOD, p - r, MOD) % MOD * binaryExp(m - r, s, MOD) % MOD) % MOD;
    }
    cout << ans nl;
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
    // cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}