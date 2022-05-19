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

    vector<ll> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<ll> pref(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        pref[i]=b[i]*a[i]+pref[i-1];
        // cout<<pref[i]<<" ";
    }
    // cout<<nl;
    ll ans=pref[n];
    for(int i=1;i<=n;i++){
        ll sum=a[i]*b[i];
        int l=i-1,r=i+1;
        while (1<=l && r<=n)
        {
            sum+=a[l]*b[r]+b[l]*a[r];
            ans=max(ans,sum+pref[n]-pref[r]+pref[l-1]);
            l--;r++;
        }
        sum=0;
        l=i;r=i+1;
        while (1<=l && r<=n)
        {
            sum+=a[l]*b[r]+b[l]*a[r];
            ans=max(ans,sum+pref[n]-pref[r]+pref[l-1]);
            l--;r++;
        }
    }
    cout<<ans<<nl;
}

int main()
{
    fast_io;
        solve();

}
