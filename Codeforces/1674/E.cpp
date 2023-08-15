#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cerr<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug2(n1,n2) cerr << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n); 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a) { display(a) };
template<class T>
void _dprint(T a) { cerr << a << "\n"; }
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        b.push_back(a[i]);
        sort(b.begin(), b.end());
        if (b.size() > 2)b.pop_back();
    }
    int ans = (b[0] + 1) / 2 + (b[1] + 1) / 2;
    for (int i = 2;i < n;i++) {
        ans = min(ans, (a[i - 2] + a[i] + 1) / 2);
    }
    for (int i = 1;i < n;i++) {
        int a1 = a[i - 1], a2 = a[i];
        if (a1 < a2)swap(a1, a2);
        if (2 * a2 - a1 >= 0) {
            int x = (2 * a1 - a2) / 3;
            int y = (2 * a2 - a1) / 3;
            for (int dx = 0;dx <= 1;dx++) {
                for (int dy = 0;dy <= 1;dy++) {
                    int tx = x + dx, ty = y + dy;
                    if (2 * tx + ty >= a1 && tx + 2 * ty >= a2 && tx >= 0 && ty >= 0) {
                        ans = min(ans, tx + ty);
                    }
                }
            }
        }
        else ans = min(ans, (a1 + 1) / 2);
    }
    cout << ans nl;
}

int main()
{
    fast_io;
#ifdef __linux__
    string path = "/mnt/3C401CB3401C75BC/CP/";
#elif _WIN32
    string path = "D:/CP/";
#endif
#ifndef ONLINE_JUDGE
    freopen((path + "input.txt").c_str(), "r", stdin);
    freopen((path + "output.txt").c_str(), "w", stdout);
    freopen((path + "error.txt").c_str(), "w", stderr);
#endif
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
