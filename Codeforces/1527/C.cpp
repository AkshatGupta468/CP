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

    vector<int> a(n+1);
    
    map<int,vector<int>> m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(m.find(a[i])==m.end())
            m[a[i]].push_back(0);
        m[a[i]].push_back(i);
    }
    ll ans=0;
    for(auto &i:m){
        ll sum=0;
        // i.second.push_back(n+1);
        for(int j=1;j<i.second.size();j++){
            sum+=i.second[j-1];
            ans+=sum*(n+1-i.second[j]);
            // debug2(j,sum*(n+1-i.second[j]));
        }
        // debug2(i.first,ans);
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
