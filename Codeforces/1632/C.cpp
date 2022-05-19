#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
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
    int a,b;
    cin>>a>>b;
    int ans=b-a;
    int s=(msb(b)<<1)-1;
    for(int i=a;i<b;i++){
        // debug(ans);
        ans=min(ans,1+i-a+(i|b)-b);
    }
    for(int i=b;i<=s;i++){
        // debug(ans);
        ans=min(ans,1+i-b+(a|i)-i);
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
