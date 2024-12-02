#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#ifdef __linux__
#include "/media/gakshat468/New Volume/CP/algo/debug.h"
#elif _WIN32
#include "D:/CP/algo/debug.h"
#elif __APPLE__
#include "debug.h"
#endif
#else
#define debug(...) 468
#endif
#define MOD 1000000007
#define nl <<'\n'
#define sp <<" "<<
#define spe <<" "
#define display_vec(a) for(auto i:a)cout<<i<<" "; cout <<"\n";
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
bool solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < a.size();i++) {
        cin >> a[i];
    }
    return true;
}

int32_t main()
{
    fast_io;
#ifdef __linux__
    string path = "/media/gakshat468/New Volume/CP/";
#elif _WIN32
    string path = "D:/CP/";
#elif __APPLE__
    string path = "~/CP/";
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
