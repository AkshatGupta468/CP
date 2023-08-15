#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
struct project{
    int a,b;
    int indb;
    int p;
    friend bool operator<(const project &left,const project &right){
        return left.a<right.a;
    }
    project(){
        this->a=0;
        this->b=0;
        this->p=0;
    }
};
void solve()
{
    int n;
    cin>>n;

    vector<project> v(n+2);
    v[0].a=0;
    for(int i=1;i<=n;i++){
        cin>>v[i].a>>v[i].b>>v[i].p;
    }
    v[n+1].a=1e9+1;
    v[n+1].p=0;
    v[n+1].b=1e9+2;
    sort(v.begin(),v.end());
    vector<pair<int,int>> ends(n+2);
    ends[0].first=0;
    ends[0].second=0;
    for(int i=1;i<=n+1;i++){
        ends[i].first=v[i].b;
        ends[i].second=i;
    }
    sort(ends.begin(),ends.end());
    for(int i=1;i<=n+1;i++){
        v[ends[i].second].indb=i;
    }
    v.push_back(project());
    int endindex=0;
    vector<ll> dp(n+2,0);
    for(int i=1;i<=n+1;i++){
        while(ends[endindex+1].first<v[i].a){
            endindex++;
            dp[endindex]=max(dp[endindex],dp[endindex-1]);
        }
        dp[v[i].indb]=max(dp[v[i].indb],dp[endindex]+v[i].p);
        // debug2(dp[endindex],endindex);
    }
    cout<<dp[n+1]<<nl;
}

int main()
{
    fast_io;
        solve();
}
