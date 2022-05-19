#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';

void hey(int n){
    vector<int> v1;
    int cnt = 0;
    for(int i=2;i<=n;i++){
        int x = __gcd(i,n);
        if(x!=1) continue;
        if((i*i)%n==1) v1.push_back(i);
    }
    debug(n);
    for(auto a:v1)
        cout << a << " ";
    cout <<  nl;   
    // if(v1.size()==1){
    //     cout << n << "\n";
    //     cout << "YES found\n";
    // } 
    // else cout << "NO\n";


}

void solve()
{
    int n;
    cin>>n;
    // for(int i=4;i<=n;i++)
    hey(n);
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
