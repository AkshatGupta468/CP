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
    vector<ll> s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    vector<ll> marker(n+1,0);
    ll carry=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i+s[i]+1<n)marker[i+s[i]+1]--;
        if(i+2<n)marker[i+2]++;
        marker[i+1]+=marker[i];
        if(s[i]-marker[i]>1){
            s[i]-=marker[i];
            int mimm=min(s[i]-1,carry);
            s[i]-=mimm;carry-=mimm;
            ans+=s[i]-1;
        }
        else{
            carry+=marker[i]-s[i]+1;
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
