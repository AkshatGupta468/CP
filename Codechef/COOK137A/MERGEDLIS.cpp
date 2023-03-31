#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
vector<int> fac;
vector<int> sieve(int size)
{
    vector<int> fac(size);
    int n = fac.size();
    for (int i = 0;i < n;i++) fac[i] = i;
    for (int i = 2;i * i <= n;i++)
    {
        for (int j = i * i;fac[i] == i && j < n;j += i)
            fac[j] = min(i, fac[j]);
    }
    return fac;
}
void solve()
{
    int n;
    cin >> n;

    for (int i = n - 1;i >= 2;i--) {
        if (fac[i] == i)
        {
            cout << (i * 1ll * (n - n % 2)) / 2 + n % 2 << nl;
            return;
        }
    }
}

int main()
{
    fast_io;
    fac = sieve(1e5 + 1);
    int t;
    cin >> t;
    while (t--)
        solve();

}
