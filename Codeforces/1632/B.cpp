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
    n|=n>>16;
    return (n+1)>>1;
}
void solve()
{
    int n;
    cin>>n;
    int skip=-1;
    skip=msb(n-1)^(n-1);
    for(int i=0;i<msb(n-1);i++){
        if(i!=skip)
        cout<<i<<" ";
    }
    cout<<skip<<" "<<n-1<<" ";
    for(int j=msb(n-1);j<n-1;j++){
        cout<<j<<" ";
    }
    cout<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
