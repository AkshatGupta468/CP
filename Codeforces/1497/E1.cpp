#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
vector<int> spf(1e7+1,0);
void sieve()
{
    int n=spf.size();
    for(int i=0;i<n;i++) spf[i]=i;
    for(int i=2;i*i<=n;i++)
    {
        for(int j=i*i;spf[i]==i && j<n;j+=i)
            spf[j]=min(i,spf[j]);
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int x=1;
        while (a[i]>1)
        {
            if(spf[a[i]]!=spf[a[i]/spf[a[i]]]){
                x*=spf[a[i]];
                a[i]/=spf[a[i]];
            }
            else{
                a[i]=a[i]/(spf[a[i]]*spf[a[i]]);
            }
        }
        a[i]=x;
        // cout<<a[i]<<" ";
    }
    // cout<<nl;
    int ans=1;
    map<int,int> vis;
    for(int i=0;i<n;i++){
        if(vis[a[i]]==ans)ans++;
        vis[a[i]]=ans;
    }
    cout<<ans<<nl;
}

int main()
{
    fast_io;
    sieve();
    int t;
    cin>>t;
    while(t--)
        solve();

}