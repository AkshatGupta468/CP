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

bool getpath(int x,int y,int p,vector<int> adj[],vector<int> &path){
    if(x==y){
        path.push_back(y);
        return true;
    }
    bool flag=false;
    for(auto &e:adj[x]){
        if(p!=e && getpath(e,y,x,adj,path)){
            path.push_back(x);
            flag=true;
        }
    }
    return flag;
}
ll fun(int x,int len,vector<bool> &vis,vector<bool> &a,vector<int> adj[]){
    vis[x]=true;
    ll ans=0;
    for(auto &e:adj[x]){
        if(!vis[e]){
            ans+=fun(e,1,vis,a,adj);
        }
    }
    if(ans!=0||a[x])ans+=2*len;
    return ans;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int x,y;
    cin>>x>>y;
    vector<bool> a(n+1);
    for(int i=0;i<k;i++){
        int q;cin>>q;
        a[q]=true;
    }
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> path;
    getpath(x,y,0,adj,path);
    vector<bool> vis(n+1);
    for(int i=path.size()-1;i>=0;i--){
        vis[path[i]]=true;
    }
    ll ans=path.size()-1;
    for(int i=path.size()-1;i>=0;i--){
        ans+=fun(path[i],0,vis,a,adj);
    }

    cout<< ans nl;
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
