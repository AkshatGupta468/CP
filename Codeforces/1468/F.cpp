#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nl << "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

bool solve() {
    int n;
    cin >> n;
    map<pair<int, int>, int> m;
    for (int i = 0;i < n;i++) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        u -= x, v -= y;
        int g = __gcd(abs(v), abs(u));
        u /= g;
        v /= g;
        m[{u, v}]++;
    }
    int ans = 0;
    for (auto& [p, x] : m) {
        ans += x * m[{-p.first, -p.second}];
    }
    cout << ans / 2 nl;
    return true;
}

signed main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
    }
}
