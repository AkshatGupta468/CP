#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
int query(){
    int a;
    cin>>a;
    return a;
}
void solve()
{
    int p1=0,p2=1;
    int n,acnt=0,bcnt=0;
    cin>>n;
    for(int i=1;i<=n*n;i++){
        int a=query();
        if(a==1){
            if(p2>=n*n){
                cout<<3<<nl;
                cout<<p1/n+1<<" "<<p1%n+1<<nl;
                p1+=2;
            }
            cout<<2<<nl;
            cout<<p2/n+1<<" "<<p2%n+1<<nl;
            p2+=2;
        }
        else{
            if(p1>=n*n){
                cout<<3<<nl;
                cout<<p2/n+1<<" "<<p2%n+1<<nl;
                p2+=2;
            }
            cout<<1<<nl;
            cout<<p1/n+1<<" "<<p1%n+1<<nl;
            p1+=2;
        }
    }
}

int main()
{

    int t;
    cin>>t;
    while(t--)
        solve();

}
