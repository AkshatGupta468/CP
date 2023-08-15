#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nl << "\n"
bool solve() {
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    int a1, a2, a3, a4, a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    if (a1 > c1 || a2 > c2 || a3 > c3) return false;
    c1 -= a1, c2 -= a2, c3 -= a3;
    a4 -= min(a4, c1), a5 -= min(a5, c2);
    a4 = max(a4, 0ll), a5 = max(a5, 0ll);
    if (a4 + a5 > c3) return false;
    return true;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}
