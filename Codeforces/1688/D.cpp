#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cerr<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug2(n1,n2) cerr << #n1 << " : "; _dprint(n1);cerr << "  " << #n2 << " : "; _dprint(n2) ;cerr<< '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n);cerr <<'\n'; 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a) { display(a) };
template<class T>
void _dprint(T a) { cerr << a; }
bool solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] + k - 1 nl;
        return true;
    }
    ll ans = -1;
    if (k <= n) {
        ll c = 0;
        ll sum = 0;
        for (ll i = 0;i < k;i++) {
            c += i;
            sum += a[i];
        }
        ans = sum + c;
        for (ll i = k;i < n;i++) {
            sum += a[i] - a[k - i];
            ans = max(ans, sum + c);
        }
    }
    else {
        ans = k * (k - 1) / 2 - (k - n) * (k - n - 1) / 2 + accumulate(a.begin(), a.end(), 0ll);
    }
    cout << ans nl;
    return true;
}

int main()
{
    // fast_io;
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
    cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
