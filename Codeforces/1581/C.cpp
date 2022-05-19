#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#define sp <<" "<<
int rect(int i1,int j1,int i2,int j2,vector<vector<int>> &pref){
    return pref[i2][j2]-pref[i1][j2]-pref[i2][j1]+pref[i1][j1];
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n+2,vector<int>(m+2));
    vector<vector<int>> pref(n+2,vector<int>(m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x;
            cin>>x;
            arr[i][j]=x-'0';
            pref[i][j]=arr[i][j]+pref[i][j-1]+pref[i-1][j]-pref[i-1][j-1];
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int a=5;i+a<=n;a++){
                for(int b=4;j+b<=m;b++){
                    int temp=rect(i+1,j+1,i+a-1,j+b-1,pref);
                    // cerr<<"inarea"<<temp<<nl;
                    temp+=2*a+2*b-8-(rect(i,j,i+a,j+b,pref)-rect(i+1,j+1,i+a-1,j+b-1,pref)-arr[i+1][j+1]-arr[i+1][j+b]-arr[i+a][j+1]-arr[i+a][j+b]);
                    // cout<<2*a+2*b-8<<nl;
                    // // (rect(i,j,i+a,j+b,pref)-rect(i+1,j+1,i+a-1,j+b-1,pref)-arr[i+1][j+1]-arr[i+1][j+b]-arr[i+a][j+1]-arr[i+a][j+b]);
                    if(ans>temp){
                        cout<<i sp j sp i+a sp j+b<<nl;
                        cout<<temp<<nl;
                    }
                    ans=min(ans,temp);
                }
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
