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
#define int long long
#pragma GCC target("popcnt")

vector<int> spf;
vector<int> sieve(int size)
{
    vector<int> fac(size);
    int n = fac.size();
    for (int i = 0;i < n;i++) fac[i] = i;
    for (int i = 2;i * i <= n;i++)
    {
        for (int j = i * i;fac[i] == i && j < n;j += i)
            fac[j] = min(i, fac[j]);
    }
    return fac;
}


int binaryExp(int a, int b, int M)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

bool solve()
{
    int x, q, M;
    cin >> x >> q >> M;
    map<int, int> xPF; // Prime Factorization 
    for (int i = 2;i * i <= x;i++) {
        while (x % i == 0) {
            x /= i;
            xPF[i]++;
        }
    }
    if (x > 1)xPF[x]++;
    int ans = 1;
    for (auto [pf, freq] : xPF) {
        if (pf == 2)continue;
        ans = (ans * (freq + 1)) % M;
    }

    int zero = 0;
    while (q--) {
        cin >> x;
        map<int, int> currxPF;
        while (x > 1) {
            currxPF[spf[x]]++;
            x /= spf[x];
        }
        for (auto [pf, freq] : currxPF) {
            if (pf == 2)continue;
            if ((xPF[pf] + 1) % M != 0)
                ans = ans * binaryExp((xPF[pf] + 1) % M, M - 2, M) % M;
            else
                zero--;

            xPF[pf] = (xPF[pf] + freq);
            if ((xPF[pf] + 1) % M != 0)
                ans = ans * (xPF[pf] + 1) % M;
            else
                zero++;
        }

        cout << ((zero > 0) ? 0 : ans) << " ";
    }
    cout nl;
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
    spf = sieve(1e6 + 1);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
