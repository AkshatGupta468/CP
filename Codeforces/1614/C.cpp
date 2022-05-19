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
    ll n,m;
    cin>>n>>m;
    ll q=0;
    for(ll i=0;i<m;i++){
        int l,r,x;
        cin>>l>>r>>x;
        q=(q|x);
    }
    q=q%MOD;
    ll p=2;
    ll ans=1;
    n--;
    while(n>0){
        if(n & 1){
            ans=(ans*1ll*p)%MOD;
        }
        p=(p*1ll*p)%MOD;
        n>>=1;
    }
    ans=(ans*q)%MOD;
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
