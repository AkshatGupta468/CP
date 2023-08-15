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
// struct Ap
// {
//     ll a, d, n;
//     void get() {
//         cin >> a >> d >> n;
//     }
// };
bool check(ll x, ll a, ll d, ll n) {
    // x = c + r * (k - 1);
    if (x < a)return false;
    if ((x - a) % d != 0)return false;
    // debug2(x, a);
    // debug2(d, n);
    // cerr << ((x - a) / d < n) nl;

    return ((x - a) / d < n);
}
ll solve() {
    ll b, q, y, c, r, z;
    cin >> b >> q >> y >> c >> r >> z;
    cerr << check(c + r * (z - 1), b, q, y) nl;
    if (!check(c, b, q, y) || r % q != 0 || !check(c + r * (z - 1), b, q, y))return 0;
    if (!check(c - r, b, q, y) || !check(c + r * z, b, q, y))return -1;
    ll ans = 0;
    for (ll p = 1;p * p <= r;p++) {
        if (r % p == 0) {
            if ((p * q) / __gcd(p, q) == r) {
                ll a = (r / p) * (r / p) % MOD;
                ans = (ans + a) % MOD;
            }
            if (p * p != r && lcm(r / p, q) == r) {
                ll a = (p * p) % MOD;
                ans = (ans + a) % MOD;
            }
        }
    }
    return ans;
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
        cout << solve() nl;
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
