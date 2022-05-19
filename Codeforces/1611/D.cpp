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
    vector<int> b(n+1),p(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    vector<int> dis(n+1,-1);
    vector<int> w(n+1,-1);
    dis[p[1]]=0;w[p[1]]=0;
    for(int i=2;i<=n;i++){
        if(dis[b[p[i]]]<0){
            cout<<"-1\n";return;
        }
        w[p[i]]=max(1,1+dis[p[i-1]]-dis[b[p[i]]]);
        dis[p[i]]=dis[b[p[i]]]+w[p[i]];
    }
    for(int i=1;i<=n;i++){
        cout<<w[i]<<" ";
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
