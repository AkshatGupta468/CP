#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353 
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

    vector<int> dp(2*n+1,0);
    dp[2]=1;
    for(int i=2;i<=2*n;i+=2){
        dp[i]=(dp[i]+dp[i-2])%MOD;
        for(int j=i;j<=2*n;j+=i){
            dp[j]=(dp[j]+dp[i]*1ll*dp[j-i]%MOD)%MOD;
        }
    }
    cout<<dp[2*n]<<nl;
}

int main()
{
    fast_io;
        // solve();
    int x=1e9+7;
    cout<<x*1ll*x<<nl;

}
