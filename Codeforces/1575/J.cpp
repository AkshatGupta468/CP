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
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> dp(n+2,vector<int>(m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>dp[i][j];
        }
    }
    

    for(int p=0;p<k;p++){
        int i=1,j;
        cin>>j;
        while(dp[i][j]!=0){
            if(dp[i][j]==1){
                dp[i][j]=2;
                j+=1;
            }
            else if(dp[i][j]==3){
                dp[i][j]=2;
                j-=1;
            }
            else {
                i+=1;
            }
        }
        cout<<j<<" ";
    }
    cout<<nl;
}

int main()
{
    fast_io;
        solve();

}
