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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,1));
    dp[0]=vector<int>(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    int ans=0;
    for(int x=1;x<=n;x++){
        ans=(ans+dp[x][m-1]*1ll*dp[n-x+1][m]%MOD)%MOD;
    }
    cout<<ans<<nl;

}

int main()
{
    fast_io;

    // int t;
    // cin>>t;
    // while(t--)
        solve();

}
