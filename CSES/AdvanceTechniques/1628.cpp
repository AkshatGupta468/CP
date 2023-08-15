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
vector<pair<ll, ll>> getsums(vector<ll> a) {
    ll n = a.size();
    vector<ll> sums;
    for (ll i = 0;i < (1ll << n);i++) {
        ll x = i;
        ll currsum = 0;
        for (ll j = 0;j < n;j++, x >>= 1) {
            if (x & 1)
                currsum += a[j];
        }
        sums.push_back(currsum);
    }
    sort(sums.begin(), sums.end());
    vector<pair<ll, ll>> sm;
    sm.push_back({ sums[0],1 });
    for (int i = 1;i < sums.size();i++) {
        if (sums[i] != sums[i - 1])
            sm.push_back({ sums[i],1 });
        else sm.back().second++;
    }
    return sm;
}

bool solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> t(n);
    for (ll i = 0;i < n;i++) {
        cin >> t[i];
    }
    ll ans = 0;
    vector<ll> a(t.begin(), t.begin() + n / 2), b(t.begin() + n / 2, t.end());
    auto ma = getsums(a), mb = getsums(b);
    reverse(mb.begin(), mb.end());
    for (int i = 0, j = 0;i < ma.size() && j < mb.size();) {
        if (ma[i].first + mb[j].first < x) i++;
        else {
            if (ma[i].first + mb[j].first == x)ans += ma[i].second * mb[j].second;
            j++;
        }
    }
    cout << ans nl;
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
