#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
ll msb(ll n){
    n|=n>>1;
    n|=n>>2;
    n|=n>>4;
    n|=n>>8;
    n|=n>>16;
    n|=n>>32;

    return (n+1)>>1;
}
ll fun(ll n){
    int m=msb(n);

    // cout<<n<<" ";
    if(n==0)return 0;
    if(n==(m<<1)-1){
        // cout<<"sf"<<(m-1)*(n)*2<<nl;
        return (m-1)*(n)*2;
    }
    else{
        ll ans=0;
        ans=((m<<1)-1)*(n-m+1)*2;
        ans+=fun((m-1)-(n-m)-1);
        return ans;
    }
}
void solve()
{
    ll n;
    cin>>n;
    cout<<fun(n)<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
