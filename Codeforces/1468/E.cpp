#include<bits/stdc++.h>
using namespace std;
#define nl << "\n"
void solve() {
    int n = 4;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[0] * a[2] nl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}