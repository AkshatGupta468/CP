#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
int msbpos(int n){
    int m=0;
    while (n>0)
    {
        n>>=1;m++;
    }
    return m-1;
}
void solve()
{
    int n,p;
    cin>>n>>p;
    vector<int> a(n);
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int num=a[i];
        while(num>0){
            if(s.count(num)){
                num=-1;
                break;
            }
            if(num%2)num/=2;
            else if(num%4==0)num/=4;
            else break;
        }
        if(num>=0){
            s.insert(a[i]);
        }
    }
    if(p==1){
        cout<<(a[0]==1)<<nl;
        return;
    }
    vector<int> precal(2e5+1,0);
    precal[p-2]=1;
    for(int i=p-3;i>=0;i--){
        precal[i]=((precal[i+1]+precal[i+2])%MOD+2)%MOD;
    }
    // for(int i=0;i<=p;i++)cerr<<precal[i]<<" ";
    // cerr<<nl;
    ll ans=0;
    for(auto i:s){
        int r=msbpos(i);
        // cerr<<i<<"=i"<<nl;
        // cerr<<r<<"=r"<<nl;
        if(r<p)
        ans=((ans+precal[r])%MOD+1)%MOD;
    }
    cout<<ans<<nl;
}

int main()
{
    // fast_io;
    // cout<<2e5<<nl;
    // int t;
    // cin>>t;
    // while(t--)
        solve();
}
