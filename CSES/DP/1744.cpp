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
    int n=500,m=500;
    int dp[n+1][m+1]{};
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        for(int j=i+1;j<=m;j++){
            dp[i][j]=INT_MAX;
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
            dp[j][i]=dp[i][j];
        }
    }
    // for(int i=0;i<=5;i++){
    //     for(int j=0;j<=5;j++)cout<<dp[i][j]<<" ";
    //     cout<<nl;
    // }
    // cout<<nl;
    // int t;
    // cin>>t;
    // while(t--)
        {
            int a,b;cin>>a>>b;
            cout<<dp[a][b]<<nl;
        }

}
