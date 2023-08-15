#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';

int main()
{
    fast_io;
    int n=1e6+1;
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    dp[1][0]=1;dp[1][1]=1;
    for(int i=2;i<=n;i++){
        dp[i][1]=(2*1ll*dp[i-1][1]+dp[i-1][0])%MOD;
        dp[i][0]=(4*1ll*dp[i-1][0]+dp[i-1][1])%MOD;
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])%MOD<<nl;
    }
}
