#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nl << "\n"
void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a > b) {
        a = n - a + 1, b = n - b + 1;
    }
    vector<int> arr(m);
    for (int i = 0;i < m;i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int l = 1, r = m;
    auto func = [&](int mid) {
        int gap = b - a - 1;
        for (int i = mid - 1;i >= 0;i--) {
            if (arr[i] > a - 1 + gap || gap <= 0) {
                return false;
            }
            gap--;
        }
        return true;
    };
    while (l <= r) {
        int mid = (l + r) / 2;
        if (func(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}