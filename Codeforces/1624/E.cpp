#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
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
int binarysearch(vector<tuple<int,int,int,int>> &vis,int val,int l,int r){
    if(l>=r)return -1;
    int mid=(l+r)/2;
    if(get<0>(vis[mid])==val)return mid;
    else if(get<0>(vis[mid])>val) return binarysearch(vis,val,l,mid);
    else return binarysearch(vis,val,mid+1,r);
}
vector<int> conv(string &s){
    vector<int> h(s.length());
    for(int i=0;i<s.length();i++){
        h[i]=s[i]-'0'+1;
    }
    return h;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(auto &i:a)cin>>i;
    string s;
    cin>>s;
    vector<tuple<int,int,int,int>> vis;
    int p=11;
    for(int j=0;j<n;j++){
        auto h=conv(a[j]);
        for(int i=m-1;i>0;i--){
            vis.push_back({(h[i-1]+h[i]*p)%MOD,j+1,i,i+1});
        }
        for(int i=m-1;i>1;i--){
            vis.push_back({(h[i-2]+h[i-1]*p+h[i]*p*p)%MOD,j+1,i-1,i+1});
        }
    }
    sort(vis.begin(),vis.end());
    // for(auto &[val,pos,l,r]:vis){
    //     cerr<< val sp pos sp l sp r nl;
    // }
    auto S=conv(s);
    int pres[m][2]{};
    for(int i=0;i<m-1;i++){
        // cerr<<n  sp m sp  i nl;
       int pos= binarysearch(vis,(S[i]+S[i+1]*p)%MOD,0,vis.size());
       pres[i][0]=pos;
    }
    for(int i=0;i<m-2;i++){
        int pos= binarysearch(vis,(S[i]+S[i+1]*p+S[i+2]*p*p)%MOD,0,vis.size());
       pres[i][1]=pos;
    }

    vector<int> dp(m+4,-1);
    if(pres[0][0]!=-1)dp[2]=0;
    if(pres[0][1]!=-1)dp[3]=0;
    cerr<< n sp m nl;
    cerr<<pres[0][0] sp pres[0][1] nl;
    for(int i=1;i<=m;i++){
        // cerr<<dp[i] <<" ";
        if(dp[i]==-1)continue;
        if(pres[i][0]!=-1)dp[i+2]=i;
        if(pres[i][1]!=-1)dp[i+3]=i;
    }
    cerr nl;
    if(dp[m]==-1){
        cout<<"-1\n\n";
        return;
    }
    vector<tuple<int,int,int>> ans;
    int x=m;
    while (x>0)
    {
        int type=(x-dp[x]-2);
        auto &[val,pos,l,r]=vis[pres[dp[x]][type]];
        ans.push_back({l,r,pos});
        x=dp[x];
    }
    reverse(ans.begin(),ans.end());
    cout<< ans.size() nl;
    for(auto &[l,r,pos]:ans){
        cout<<l sp r sp pos nl;
    }
    cout nl;
}

int main()
{
        fast_io;
     #ifdef __linux__
        string path="/mnt/3C401CB3401C75BC/CP/";
     #elif _WIN32
        string path="D:/CP/";
     #endif
     #ifndef ONLINE_JUDGE
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
