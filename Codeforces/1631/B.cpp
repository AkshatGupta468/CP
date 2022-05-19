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
    vector<vector<int>> f(n+1,{n+1,-1});
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]][0]=min(f[a[i]][0],i);
        f[a[i]][1]=max(f[a[i]][1],i);
    }
    int ans=0,pos=0;
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(f[a[i]][0]!=f[a[i]][1] && f[a[i]][0]==i  && f[a[i]][1]>pos){
            if(i<pos){
                ans+=f[a[i]][1]-pos-1;
            }
            else {
                ans+=f[a[i]][1]-f[a[i]][0]-1;
            }
            pos=f[a[i]][1];
        }
    }
    
    cout<<ans<<nl;
}

int main()
{
    fast_io;
        solve();

}