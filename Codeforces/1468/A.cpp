#include<bits/stdc++.h>
using namespace std;
#define nl << "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> lis;

    lis.push_back({ a[0], inf });

    for (int i = 1; i < n; i++) {
        int l = 0, r = lis.size() - 1;

        int ptr = 0;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (min(a[i], lis[mid].first) >= min(lis[mid].second, lis[mid].first)) {
                l = mid + 1;
                ptr = mid;
            }
            else {
                r = mid - 1;
            }
        }
        
        ptr++;
        if (ptr == lis.size()) lis.push_back({ a[i], lis[ptr - 1].first });
        else {
            lis[ptr].first = min(lis[ptr].first, a[i]);
        }
    }
    cout << lis.size() nl;
}
int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
