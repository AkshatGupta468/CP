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
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &i:a)cin>>i;
    int currmax=n-1,tempmax=n-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[currmax]){
            currmax=tempmax;
        }
        if(a[i]>a[tempmax])tempmax=i;
    }
    return a[currmax]==n;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"YES\n":"NO\n");

}
