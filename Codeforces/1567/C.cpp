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

    vector<int> a;
    while(n>0){
        a.push_back(n%10);
        n/=10;
    }
    if(a.size()==1){
        cout<<a[0]-1<<nl;
        return;
    }
    vector<pair<int,int>> dp(a.size());
    dp[0]={a[0]+1,9-a[0]};
    dp[1]={a[1]+1,9-a[1]};
    for(int i=2;i<dp.size();i++){
        dp[i].second=(9-a[i])*dp[i-2].first+(10-a[i])*dp[i-2].second;
        dp[i].first=(a[i]+1)*dp[i-2].first+a[i]*(dp[i-2].second);
    }
    cout<<(dp.rbegin()->first)*((dp.rbegin()+1)->first)-2<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
