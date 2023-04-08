#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
bool solve()
{
    int n;

    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
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
    cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
