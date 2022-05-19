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
    ll n;
    cin>>n;
    vector<int> freqb[n+1];
    vector<int> remb(n+1,0);

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        freqb[a].push_back(b);
    }
    ll sel2same=0,ans=0,sel2diff=0;
    ll cnt=0;
    for(int i=1;i<n+1;i++){
        ll sz=freqb[i].size();
        for(int j=0;j<freqb[i].size();j++){
            remb[freqb[i][j]]+=sz-1;
        }
        ans+=sel2diff*sz;
        sel2diff+=cnt*sz;
        sel2same+=sz*(sz-1)/2;
        ans+=sz*(sz-1)*(sz-2)/6;
        cnt+=sz;
        // debug2(i,sel2same);
    }
    // display(remb);
    for(int i=1;i<=n;i++){
        ll sz=freqb[i].size();
        for(int j=0;j<freqb[i].size();j++){
            ans+=sel2same-sz*(sz-1)/2-remb[freqb[i][j]]+sz-1;
            // debug2(i,j);debug(ans);
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
