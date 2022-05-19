#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
void solve()
{
    int n;
    cin>>n;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<int> lev;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            lev.push_back(a[i-1]);
        }
        else if(a[i]!=a[i-1]+1){
            while(a[i]!=1+*lev.rbegin()){
                lev.pop_back();
            }
            lev.pop_back();
        }
        for(int j=1;j<lev.size();j++)cout<<lev[j]<<'.';
        cout<<a[i]<<nl;
    }
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
