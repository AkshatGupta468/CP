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
    vector<bool> dp(1e5+1,0);
    dp[0]=true;
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=dp.size()-1-a[i];j>=0;j--){
            if(!dp[j+a[i]] && dp[j]){
                dp[j+a[i]]=true;
                k++;
            }
        }
    }
    cout<<k<<nl;
    for(int i=1;i<dp.size();i++){
        if(dp[i])cout<<i<<' ';
    }
    cout<<nl;
}

int main()
{
    fast_io;
        solve();

}
