#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';

vector<int> fac(1e7+1);
vector<int> ans(1e7+1,1e9);
void sieve()
{
    int n=fac.size();
    for(int i=0;i<n;i++) fac[i]=i;
    for(int i=2;i*i<n;i++)
    {
        for(int j=i*i;fac[i]==i && j<n;j+=i)
            fac[j]=min(i,fac[j]);
    }
}
void solve()
{
    int n=1e7;
    for(int i=1;i<=n;i++){
        int last=fac[i];
        ll w=fac[i];
        ll c=1;
        int x=i;
        while(x!=1){
            if(fac[x]==last){
                w*=fac[x];
                x/=fac[x];
            }
            else{
                c*=(w-1)/(last-1);
                w=fac[x]*1ll*fac[x];
                last=fac[x];
                x/=fac[x];
            }
        }
        if(fac[x]==last){
            w*=fac[x];
            x/=fac[x];
        }
        else{
            c*=(w-1)/(last-1);
            w=fac[x]*1ll*fac[x];
            x/=fac[x];
        }
        // debug2(i,c);
        if(c<ans.size())
        ans[c]=min(i,ans[c]);
    }
}

int main()
{
    fast_io;
    sieve();
    solve();
    int t;
    cin>>t;
    while(t--){
        int c;
        cin>>c;
        if(ans[c]==1e9){
            cout<<"-1\n";
        }
        else
        cout<<ans[c]<<nl;
    }

}
