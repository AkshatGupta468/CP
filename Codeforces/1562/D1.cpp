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
map<char,int> m={{'+',1},{'-',-1}};
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        char x;cin>>x;
        a[i]=a[i-1]+(1-2*(i%2))*m[x];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if((a[r]==a[l-1])){
            cout<<"0\n";
        }
        else cout<<(2-(r-l+1)%2) nl;
    }
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/CP/input.txt", "r", stdin);
        freopen("D:/CP/output.txt", "w", stdout);
        freopen("D:/CP/error.txt","w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
