#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
// void solve()
// {
//     ll x,y;
//     cin>>x>>y;
//     ll bm=sqrt(x+2);
//     if(bm*bm==x+2)bm--;
//     bm=min(bm,y);
//     ll ans=bm*(bm-1)/2;
//     for(int i=1;i<bm;i++){

//     }
// }
void solve(){
    ll x,y;
    cin>>x>>y;
    ll ans=0;
    for(int p=1;p*(p+2)<=x;p++){
        int mini=min((x/p),y+1);
        if(mini-(p+1)<0)break;
        ans+=mini-(p+1);
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
