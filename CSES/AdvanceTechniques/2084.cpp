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


class convexhull {
    deque<int> q;
public:
    int n;
    vector<int> p, l, c;
    vector < vector<int>> dp;
    convexhull(vector<int> c, int K):n(c.size() - 1), c(c) {
        p.resize(c.size());
        l.resize(c.size());
        dp.resize(c.size(), vector<int>(c.size()));
        for (int r = 1;r <= n;r++) {
            l[r] = l[r - 1] + r * c[r];
            p[r] = p[r - 1] + c[r];
        }
        for (int i = 1;i <= n;i++) {
            dp[i][1] = rangecostutil(i, 0);
        }
        for (int k = 2;k <= K;k++) {
            q.clear();
            for (int i = 1;i <= n;i++) {
                dp[i][k]=
            }
        }
    }

    int rangecostutil(int j, int i) {
        if (j < i) return (l[i] - l[j]) - j * (p[i] - p[j]);
        swap(j, i);
        return i * (p[i] - p[j]) - (l[i] - l[j]);
    }
    int rangecost(int j, int i) {
        int m = (i + j) / 2;
        return rangecostutil(j, m) + rangecostutil(i, m);
    }

    int intersectionX(int j1, int j2, int k) {
        int l = j2, r = n + 1;
        while (l + 1 != r) {
            int mid = (l + r) / 2;
            if (dp[j1][k - 1] + rangecost(j1, mid) > dp[j2][k - 1] + rangecost(j2, mid)) l = mid;
            else r = mid;
        }
        return r;
    }

    void add(int i, int k) {
        while (q.size() >= 2 && intersectionX(q[q.size() - 2], q[q.size() - 1], k) <= intersectionX(q[q.size() - 1], i, k))
            q.pop_back();
        q.push_back(i);
    }
};

bool solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
    }

    convexhull A(c, k);

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
