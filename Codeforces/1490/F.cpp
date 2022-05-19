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

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int> cnt={0,1};
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1])cnt.push_back(1);
        else (*cnt.rbegin())++;
    }
    sort(cnt.begin(),cnt.end());
    vector<int> pref=cnt;
    for(int i=1;i<pref.size();i++)pref[i]+=pref[i-1];
    int sz=pref.size();
    int ans=INT_MAX,sum=0;
    for(int i=pref.size()-1;i>0;i--){
        ans=min(ans,pref[i-1]+(sum-cnt[i]*(sz-i-1)));
        sum+=cnt[i];
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
