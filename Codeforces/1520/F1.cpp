#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
int query(int l, int r){
    cout<<"? "<<l<<" "<<r<<nl;
    int x;
    cin>>x;
    if(x==-1)exit(0);
    return r+1-l-x;
}
void solve()
{
    int n,t;
    cin>>n>>t;
    int k;
    cin>>k;
    int l=0,r=n;
    while(l+1<r){
        int mid=(l+r)/2;
        int q=query(1,mid);
        if(q>=k) r=mid;
        else l=mid;
    }
    cout<<"! "<<l+1<<nl;
}

int main()
{
    // fast_io;
        solve();

}
