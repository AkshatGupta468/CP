#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
struct node {
    int a,b;
    bool operator <(const node &x,const node &y){
        return x.b<y.b;
    }
};
void solve()
{
    int n;
    cin>>n;
    vector<node> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].a>>v[i].b;
    }
    sort(v.begin(),v.end());
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
