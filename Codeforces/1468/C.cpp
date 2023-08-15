#include<bits/stdc++.h>
using namespace std;
#define nl << "\n"
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)

void solve() {
    int q; cin >> q;
    priority_queue<pair<int, int>> pq;
    queue<pair<int, int>> a;
    vector<bool> bit(1);
    int c = 0;

    for (int i = 1; i <= q; i++) {
        int t; cin >> t;
        if (t == 1) {
            c++;
            int m; cin >> m;
            a.push({ m, c });
            pq.push({ m, -c });
            bit.push_back(false);
        }
        else if (t == 2) {
            while (bit[a.front().second])
                a.pop();
            cout << a.front().second << " ";
            bit[a.front().second] = true;
            a.pop();
        }
        else {
            while (bit[-pq.top().second])
                pq.pop();

            bit[-(pq.top().second)] = true;
            cout << -(pq.top().second) << ' ';
            pq.pop();
        }
    }
    cout nl;
}
int main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
