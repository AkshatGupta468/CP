#include<bits/stdc++.h>
using namespace std;
#define nl <<'\n'
#define sp <<" "<<
int query(int i, int j) {
    cout << "?" sp i sp j << endl;
    int g;
    cin >> g;
    if (g == -1)exit(0);
    return g;
}
void printans(int x, int y) {
    cout << "!" sp x sp y << endl;
}

bool solve()
{
    int n;
    cin >> n;
    if (n == 2) {
        printans(1, 2);
        return true;
    }

    vector<int> a(n + 1);
    set<int> s;
    for (int i = 2;i <= n;i++) {
        a[i] = query(1, i);
        s.insert(a[i]);
    }

    if (s.size() == n - 1) {
        printans(1, 1);
        return true;
    }
    set<int> s2;
    int x = *max_element(a.begin(), a.end());
    // debug(x);
    int sz = (n + x - 1) / x - 1;
    int last = -1;
    for (int i = 2;i <= n;i++) {
        if (a[i] == x) {
            if (last != -1) {
                int q = query(last, i);
                if (q > x) {
                    printans(last, i);
                    return true;
                }
            }
            last = i;
        }
    }

    printans(last, 1);
    return true;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        int res;
        cin >> res;
        if (res == -1)exit(0);
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
