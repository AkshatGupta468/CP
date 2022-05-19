#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
void solve()
{
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll ans=INT_MIN;
    for(ll i=max(1ll,n-2*k);i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            ans=max(ans,i*j-k*(a[i]|a[j]));
        }
    }
    cout<<ans<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
