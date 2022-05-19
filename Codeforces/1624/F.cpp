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
void solve()
{
    int n;
    cin>>n;
    int l=1,r=n;
    int mul=1;
    while(l+1<r){
        int mid=(l+r)/2;
        int c=mul*n-mid;
        cout<<"+ "<<c<<endl;
        int q;cin>>q;
        if(mul==q){
            l=mid;
            mul++;
        }
        else r=mid;
        l+=c;r+=c;
    }
    cout<<"! "<<l <<endl;
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
