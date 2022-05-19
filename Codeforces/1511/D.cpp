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
    int n,k;
    cin>>n>>k;
    while (1)
    {
        for(char i='a';i<'a'+k;i++){
            cout<<i;n--;
            if(n==0)return;
            for(char j=i+1;j<'a'+k;j++){
                cout<<i;n--;
                if(n==0)return;
                cout<<j;n--;
                if(n==0)return;
            }
        }
    }
}

int main()
{
    fast_io;

    // int t;
    // cin>>t;
    // while(t--){
        solve();
        cout<<nl;
    // }
}
