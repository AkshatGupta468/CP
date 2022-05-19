#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
void displayvec(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}
void solve()
{
    int n;
    cin>>n;
    int ans=1;
    vector<int> v;
    for(int i=1;i<n;i++){
        if(__gcd(n,i)==1){
            v.push_back(i);
            ans=(ans*1ll*i)%n;
        }
    }
    if(ans==1){
        cout<<v.size()<<nl;
        displayvec(v);
        return;
    }
    // debug2(n,ans);
    cout<<v.size()-1<<nl;
    for(auto &i:v){
        if(ans==i)continue;
        cout<<i<<" ";
    }
    cout<<nl;
}

int main()
{
    fast_io;
        solve();

}
