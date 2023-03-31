#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353 
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
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
long long binaryMultiply(long long, long long, long long);

int binaryExp(int a, int b, int M)
{
    // base a
    //power b
    //modular M
    //(a^b)%M

    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1ll * a) % M;
        }
        a = (a * 1ll * a) % M;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    ll oddcntsym = 0;
    if (n % 2) {
        oddcntsym = ((binaryExp(2, (n + 1) / 2 + 1, MOD) - 2) % MOD - binaryExp(2, (n + 1) / 2 - 1, MOD)) % MOD;
    }
    else {
        oddcntsym = (binaryExp(2, n / 2 + 1, MOD) - 2) % MOD;
    }
    ll odds = (binaryExp(2, n - 1, MOD)) % MOD;
    ll evens = (odds - 1) % MOD;
    ll oddsasym = (odds - oddcntsym + MOD) % MOD;
    debug(n);
    debug(oddcntsym);
    debug(odds);
    debug(evens);
    debug(oddsasym);
    cout << (oddcntsym + 2ll * evens + 3ll * oddsasym) % MOD << nl;
}
int main()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("D:/CP/input.txt", "r", stdin);
    freopen("D:/CP/output.txt", "w", stdout);
    freopen("D:/CP/error.txt", "w", stderr);
#endif
    int t;
    cin >> t;
    while (t--)
        solve();
}
