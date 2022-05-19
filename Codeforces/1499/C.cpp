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
    vector<int> c(n);
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    int m[2]={c[0],c[1]};
    ll s[2]={c[0],c[1]};
    ll fans=c[0]*n+c[1]*n;
    for(ll i=2;i<n;i++){
        m[i & 1]=min(m[i & 1],c[i]);
        s[i & 1]+=c[i];
        fans=min(fans,m[0]*(n-i/2-1)+m[1]*(n-(i-1)/2-1)+s[0]+s[1]);
    }
    cout<<fans<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
