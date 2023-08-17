#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    vector<double> l(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        l[i]=log(a[i]);
    }

    vector<int> ans(n);
    ans[0]=-1;

    multiset<pair<double,int>> s;
    s.insert({l[0],0});
    for(int i=1;i<n;i++)
    {
        l[i]=(l[i]+(*s.begin()).first);
        ans[i]=(*s.begin()).second;
        if(i>=k)
        {
            s.erase(s.find({l[i-k],i-k}));
        }
            s.insert({l[i],i});
    }

    int pos=n-1;
    int final_ans=a[n-1];
    while(ans[pos]>=0)
    {
        final_ans=(final_ans * a[ans[pos]])%MOD;
        pos=ans[pos];
    }
    cout<<final_ans<<nl;
}

signed main()
{
//    fast_io;
//
//    int t;
//    cin>>t;
//    while(t--)
        solve();

}
