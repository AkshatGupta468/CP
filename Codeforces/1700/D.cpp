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
    ll n;
    cin >> n;
    vector<ll> a(n + 2);
    ll totvol = 0;
    for (ll i = 1;i <= n;i++) {
        cin >> a[i];
        totvol += a[i];
    }

    vector<ll> timereq(n + 2);
    timereq[0] = 1e18;
    ll leftfilltime = 0;
    ll sumleft = 0;
    for (ll i = 1;i <= n;i++) {
        timereq[i] = max(leftfilltime, (totvol + i - 1) / i);
        sumleft += a[i];
        leftfilltime = max(leftfilltime, (sumleft + i - 1) / i);
    }
    debug(timereq);
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        int pos = lower_bound(timereq.begin(), timereq.end(), t, greater<ll>()) - timereq.begin();
        if (pos > n)cout << "-1\n";
        else cout << pos nl;
    }
    return true;
}

int main()
{
    fast_io;
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
    // cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
