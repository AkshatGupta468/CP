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
    vector<ll> a(n);
    for (ll i = 0;i < n;i++) {
        cin >> a[i];
    }
    map<ll, ll> m;
    int sz = 0;
    ll x = 0;
    for (int i = 0;i < n;i++) {
        x ^= a[i];
        m[x]++;
        if (m[x] == 1)sz++;
    }
    int ans = sz;
    ll y = 0;
    for (int i = 0;i < n;i++) {
        y ^= a[i];
        x ^= a[i];
        m[y]--;
        if (m[y] == 0)sz--;
        m[x]++;
        if (m[x] == 1)sz++;
        ans = max(ans, sz);
    }
    cout << ans nl;
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
    cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
