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
    vector<int> q(n+1,0);
    vector<bool> vis(n+1,false);
    vector<int> link(n+2,0);
    int f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>q[i];
        if(q[i]!=q[i-1]){
            cout<<q[i]<<" ";
            vis[q[i]]=true;
        }
        else {
            while(vis[f])f++;
            cout<<f<<" ";
            vis[f]=true;
        }
        link[i]=i-1;
    }
    cout<<nl;
    for(int i=1;i<=n;i++){
        if(q[i]!=q[i-1]){
            cout<<q[i]<<" ";
            link[q[i]+1]=link[q[i]];
        }
        else{
            cout<<link[q[i]+1]<<" ";
            link[q[i]+1]=link[link[q[i]+1]];
        }
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
