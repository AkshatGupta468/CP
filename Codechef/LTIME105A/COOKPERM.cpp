#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cerr<<i<<" ";
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
    vector<int> a[2];
    map<ll,ll> len[2];
    for(int k=0;k<2;k++){
        a[k].resize(n);
        for(int i=0;i<n;i++){
            cin>>a[k][i];
            a[k][i]--;
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            int tlen=0,x=i;
            while(!vis[x]){
                vis[x]=true;
                tlen++;
                x=a[k][x];
            }
            len[k][tlen]++;
        }
    }
    ll ans=0;
    for(auto i:len[0]){
        for(auto j:len[1]){
            ans+=((i.first*j.first)-(__gcd(i.first,j.first)))*i.second*j.second;
        }
    }
    cout<<ans nl;
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
    // string path="/mnt/3C401CB3401C75BC/CP/";
    string path="D:/CP/";
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
