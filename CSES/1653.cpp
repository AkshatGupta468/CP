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
    int n,x;
    cin>>n>>x;
    vector<int> w(n);
    for(auto &i:w)cin>>i;
    vector<pair<int,int>> dp(1<<n,{1e9,0});
    dp[0]={1,0};
    for(ll i=0;i<dp.size();i++){
        for(int z=(1<<(n-1)),j=n-1;j>=0;z>>=1,j--){
            if(!(z & i)){
                int r=z ^ i;
                if(dp[i].second+w[j]<=x){
                    if(dp[r].first>dp[i].first)
                        dp[r]={dp[i].first,dp[i].second+w[j]};
                    else if(dp[r].first==dp[i].first && dp[i].second+w[j]<dp[r].second)
                        dp[r]={dp[i].first,dp[i].second+w[j]};
                }
                else{
                    if(dp[r].first>dp[i].first+1)
                        dp[r]={dp[i].first+1,w[j]};
                    else if(dp[r].first==dp[i].first+1 && w[j]<dp[r].second)
                        dp[r]={dp[i].first+1,w[j]};
                }
            }
        }
    }
    cout<<dp.rbegin()->first<<nl;
}

int main()
{
    fast_io;
        solve();

}
