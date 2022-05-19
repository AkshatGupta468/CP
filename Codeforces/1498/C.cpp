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
    int N,K;
    cin>>N>>K;
    vector<vector<ll>> dp(N+1,vector<ll>(K+1,1));
    for(int k=2;k<=K;k++){
        for(int n=1;n<=N;n++){
            dp[n][k]=(dp[N-n][k-1]+dp[n-1][k])%MOD;
        }
    }
    cout<<dp[N][K]<<nl;
}

int main()
{
    fast_io;
    ll t;
    cin>>t;
    cout<<sizeof(t);
    // while(t--)
    //     solve();

}
