#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
bool solve()
{
    int n,m,h;
    cin>>n>>m>>h;
    int v=(n*m)/2-h;
    
    if(m%2){
        swap(n,m);
        swap(v,h);
    }
    
    if(n%2){
        if(2*h<m)return false;
        h-=(m/2);
        n--;
    }
    return (h%2==0);
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"YES\n":"NO\n");

}
