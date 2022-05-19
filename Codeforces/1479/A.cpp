#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug2(n1,n2) cerr << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n); 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a){display(a)};
template<class T>
void _dprint(T a){cerr<<a<<"\n";}
void query(int x,vector<int> &a){
    if(a[x]==-1){
        cout<<"? "<<x<<endl;
        cin>>a[x];
    }
    if(a[x]==-1)exit(0);
}
int binarysearch(int l,int r,vector<int> &a){
    if(l+1==r)return l;
    int x=(l+r)/2;
    query(x-1,a);
    query(x,a);
    query(x+1,a);
    if(a[x]<a[x-1] && a[x]<a[x+1])return x;
    else if(a[x-1]>a[x] && a[x]>a[x+1])return binarysearch(x+1,r,a);
    else return binarysearch(l,x,a);
}
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+2,-1);
    a[0]=1e9,a[n+1]=1e9;
    int ans=binarysearch(1,n+1,a);
    cout<<"! "<<ans<<endl;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("D:/CP/input.txt", "r", stdin);
    //     freopen("D:/CP/output.txt", "w", stdout);
    //     freopen("D:/CP/error.txt","w",stderr);
    // #endif
    // int t;
    // cin>>t;
    // while(t--)
        solve();
}
