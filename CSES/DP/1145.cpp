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

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> dp(n+2,INT_MAX);
    dp[0]=0;
    dp[1]=a[0];
    for(int i=1;i<n;i++){
        int pos=upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        if(a[i]>dp[pos-1])
        dp[pos]=a[i];
    }
    for(int i=1;i<dp.size();i++){
        if(dp[i]==INT_MAX){
            cout<<i-1<<nl;
            return;
        }
    }
}

int main()
{
    fast_io;
        solve();

}
