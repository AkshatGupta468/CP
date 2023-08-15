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
    // int n,m;
    // cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=i;
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s[i-1]!=t[j-1]));
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<nl;
    // }
    cout<<dp[n][m]<<nl;
}

int main()
{
    fast_io;
    // cout<<5000*5000/256/1024;
        solve();

}
