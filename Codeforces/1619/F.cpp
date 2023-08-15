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
    ll n, m, k;
    cin >> n >> m >> k;
    ll p = n / m;
    ll y = n % m;
    ll x = m - y;
    int st = 1;
    while (k--) {
        int s = st;
        for (int i = 0;i < x;i++) {
            cout << p << ' ';
            for (int j = 0;j < p;j++) {
                cout << s << ' ';
                s = 1 + s % n;
                st = 1 + st % n;
            }
            cout nl;
        }
        for (int i = 0;i < y;i++) {
            cout<<p+1<< ' ';
            for (int j = 0;j < p + 1;j++) {
                cout << s << ' ';
                s = 1 + s % n;
            }
            cout nl;
        }
    }
    cout nl;
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
