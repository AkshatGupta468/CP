#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
const ll inv2=500000004;
void solve()
{
    int n;
    cin>>n;
    int dp[1+n*(n+1)/2]{};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=n*(n+1)/2-i;j>=0;j--){
            dp[j+i]=(dp[j+i]+dp[j])%MOD;
        }
    }
    if(n%4==1||n%4==2){
        cout<<"0\n";
        return;
    }
    cout<<(dp[n*(n+1)/4]*inv2)%MOD<<nl;
}

int main()
{
    fast_io;
        solve();

}
