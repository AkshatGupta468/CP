#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
int query(int l,int r){
    cout<<"? "<<l<<" "<<r-1<<nl;
    int q;
    cin>>q;
    if(q==-1)exit(0);
    return q;
}
int fun(int l,int r){
    cerr<<"sfd"<<l<<" "<<r<<nl;
    if(l+1==r){
        return l;
    }
    int q=query(l,r);
    if(r-l==2){
        return (l==q)?l+1:l;
    }
    int mid=(l+r)/2;
    while(1){
        if(q>=mid){
            if(mid+1==r||q!=query(mid,r))
                return fun(l,mid);
            l=mid;
        }
        else{
            if(l+1==mid||q!=query(l,mid))
                return fun(mid,r);
            r=mid;
        }
        if(l+1==r)return l;
        mid=(l+r)/2;
    }
}
void solve()
{
    int n;cin>>n;
    int l=1,r=n+1;
   int ans=fun(1,n+1);
   cout<<"! "<<ans<<nl;
}

int main()
{
    // fast_io;
    cout.flush();
        solve();

}
