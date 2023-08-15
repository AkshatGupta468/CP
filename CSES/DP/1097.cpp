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
    int n;
    cin>>n;

    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    //length,start

    vector<vector<ll>> dp(n+1,vector<ll>(n+2,LONG_LONG_MIN));
    dp[0].assign(n+2,0);
    for(int l=1;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            dp[l][i]=max(-a[i-1]+a[l+i-1]-dp[l-1][i+1],a[i+l-1]-a[i-1]-dp[l-1][i]);
        }
    }
    cout<<dp[n][1]<<nl;
}

int main()
{
    fast_io;
        solve();

}
