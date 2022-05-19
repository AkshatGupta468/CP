#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i.second<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
int binr(int l,int r,vector<pair<int,int>> &v,int x){
    if(l+1==r) return l;
    int mid=(l+r)/2;
    if(v[mid].second>x) return binr(l,mid,v,x);
    else return binr(mid,r,v,x);
}
int msb(int n){
    n|=n>>1;
    n|=n>>2;
    n|=n>>4;
    n|=n>>8;
    n|=n>>16;
    return (n+1)>>1;
}
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
    vector<pair<int,int>> v;
    v.push_back({0,0});
    for(int i=0;i<n;i++){
        if(v.rbegin()->first==a[i]){
            (v.rbegin()->second)++;
        }
        else v.push_back({a[i],1+v.rbegin()->second});
    }
    // display(v);cout<<nl;
    int ans=1e6;
    for(int i=1;i<=msb(n)<<2;i<<=1){
            int p1=binr(0,v.size(),v,i);
            // debug2(i,p1);
        for(int j=1;j<=msb(n)<<2;j<<=1){
            int p2=binr(0,v.size(),v,v[p1].second+j);
            int tempans=i-v[p1].second+v[p1].second+j-v[p2].second;
            if(n-v[p2].second==0)tempans++;
            else if(msb(n-v[p2].second)!=n-v[p2].second){
                tempans+=(msb(n-v[p2].second)<<1)-n+v[p2].second;
            }
            // debug2(j,p2);
            ans=min(ans,tempans);
            // debug(ans);
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
