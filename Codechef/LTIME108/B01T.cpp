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
vector<bool> vis;
vector<int> scnt,a,ans,sz;
void subtreecnt(int v,vector<int> adj[]){
    vis[v]=true;
    for(auto &e:adj[v]){
        if(vis[e])continue;
        // cerr<<"--e "<<e nl;
        subtreecnt(e,adj);
        scnt[v]+=scnt[e];
        sz[v]+=sz[e];
    }
    scnt[v]+=a[v];
    sz[v]++;
    // debug(v);
    // debug(scnt);cerr nl;
}
void getans(int v,int req,vector<int> adj[]){
    vis[v]=true;
    vector<pair<int,int>> chget;
    for(auto &e:adj[v]){
        if(vis[e])continue;
        chget.push_back({2*scnt[e]-sz[e],e});
    }
    sort(chget.begin(),chget.end(),greater<pair<int,int>>());
    for(int i=0;i<chget.size() && req>0;i++){
        if(chget[i].first<=req){
            req-=chget[i].first;
            ans.push_back(chget[i].second);
        }
        else {
            getans(chget[i].second,req,adj);
            break;
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    a.assign(n+1,0);
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans.clear();
    vis.assign(n+1,false);
    scnt.assign(n+1,0);
    sz.assign(n+1,0);
    subtreecnt(1,adj);
    if(scnt[1]*2<n){
        for(int i=1;i<=n;i++){
            scnt[i]=sz[i]-scnt[i];
        }
    }
    vis.assign(n+1,false);
    getans(1,scnt[1]-n/2,adj);
    cout<<ans.size() nl;
    for(auto &e:ans)cout<<e << " ";
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
