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
    int n,k;
    cin>>n>>k;

    vector<int> a(k),t(k);
    for(auto &i:a)cin>>i;
    for(auto &j:t)cin>>j;
    vector<vector<int>> temp(2,vector<int>(n+1,2e9));
    for(int i=0;i<k;i++){
        temp[0][a[i]]=t[i];
        temp[1][a[i]]=t[i];
    }
    for(int i=2;i<=n;i++){
        temp[0][i]=min(temp[0][i-1]+1,temp[0][i]);
        temp[1][n-i+1]=min(temp[1][n-i+2]+1,temp[1][n-i+1]);
    }
    for(int i=1;i<=n;i++){
        cout<<min(temp[0][i],temp[1][i])<<" ";
    }
    cout<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
