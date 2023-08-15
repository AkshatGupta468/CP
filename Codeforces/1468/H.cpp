#include<bits/stdc++.h>
using namespace std;
#define nl << "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

int inf = 1e9;

bool solve() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<bool> vis(n + 1);
    for (int i = 0;i < m;i++) {
        int x;
        cin >> x;
        vis[x] = true;
    }
    if ((n - m) % (k - 1))return false;
    int ans = false;
    for (int i = 1, cnt = 0;i <= n;i++) {
        if (!vis[i])cnt++;
        else if (cnt >= (k - 1) / 2 && (n - m - cnt) >= (k - 1) / 2) return true;
    }
    return false;
}
int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        // solve();
        cout << (solve() ? "YES\n" : "NO\n");
    }
}
