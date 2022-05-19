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
    int n,q;
    cin>>n>>q;

    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        char c;cin>>c;
        if(c=='+')a[i]=1;
        else a[i]=-1;
        if(i-2>=0)a[i]+=a[i-2];
    }
    for(int i=0;i<=n;i++){
        debug2(i,a[i]);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==1) cout<<abs(a[r]-a[r-1])<<nl;
        else if(l%2==r%2) cout<<abs(a[r]-a[l-2]-(a[r-1]-a[l-1]))<<nl;
        else cout<<abs(a[r]-a[l-1]-(a[r-1]-a[l-2]))<<nl;
    }
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
