#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
int rect(int t,int b,int l,int r,vector<vector<int>> &v){
    return v[b][r]-v[b][l]-v[t][r]+v[t][l];
}
vector<vector<int>> a;
vector<vector<int>> p;
void solve()
{
    int n,m;
    cin>>n>>m;
    a.assign(n+1,vector<int>(m+1,0));
    p.assign(n+1,vector<int>(m+1,0));
    int ans=1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=c-'0';
            p[i][j]=a[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
            cout<<setw(4)<<p[i][j];
        }
        cout<<nl;
    }
    cout<<nl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            
            if(i>=5 && j>=4){
                debug2(i,j);
                int val=2*i+2*j-8-(rect(0,i,0,j,p)-rect(1,i-1,1,j-1,p)-a[1][1]-a[i][1]-a[1][j]-a[i][j]);
                debug(val);
                val+=rect(1,i-1,1,j-1,p);
                debug(val);
                ans=min(ans,val);
            }
        }
    }
    cout<<ans<<nl;
    
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
