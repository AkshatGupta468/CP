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
void fun(int x,vector<int> &a,vector<int> adj[],vector<bool> &vis,int lvl){
    vis[x]=true;
    for(auto &e:adj[x]){
        if(vis[e])continue;
        a[e]=lvl*(adj[e].size());
        fun(e,a,adj,vis,-lvl);
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1,false);
    vector<int> a(n+1);
    fun(1,a,adj,vis,-1);
    a[1]=adj[1].size();
    for(int i=1;i<=n;i++){
        cout<< a[i] << " ";
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
