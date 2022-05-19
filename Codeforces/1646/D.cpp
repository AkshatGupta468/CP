#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
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
struct obj
{
    pair<ll,ll> se;
    pair<ll,ll> un;    
};
vector<obj> node;
vector<bool> good;
void dfs(int x,int p,vector<int> adj[]){
    node[x].se.first=1;
    node[x].un.first=0;
    node[x].se.second=adj[x].size();
    node[x].un.second=1;
    
    for(auto &e:adj[x]){
        if(e==p)continue;
        dfs(e,x,adj);
        node[x].se.first+=node[e].un.first;
        node[x].un.first+=max(node[e].se.first,node[e].un.first);
        node[x].se.second+=node[e].un.second;
        if(node[e].se.first==node[e].un.first){
            node[x].un.second+=min(node[e].se.second,node[e].un.second);
        }
        else node[x].un.second+=(node[e].se.first>node[e].un.first)?node[e].se.second:node[e].un.second;
    }
}
void assignw(int x,int p,vector<int> adj[]){
    if(good[p]){
        good[x]=false;
    }
    else {
        if(node[x].se.first==node[x].un.first){
            good[x]=(node[x].se.second<=node[x].un.second);
        }
        else good[x]=(node[x].se.first>node[x].un.first);
    }
    for(auto &e:adj[x]){
        if(e!=p)
        assignw(e,x,adj);
    }
}

void solve()
{
    int n;
    cin>>n;
    node.clear();
    node.resize(n+1);
    good.resize(n+1);
    vector<int> adj[n+1];
    adj[0].push_back(1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n==2){
        cout <<"2 2\n1 1\n";
        return;
    }
    dfs(0,-1,adj);
    good[0]=false;
    assignw(1,0,adj);
    cout<<node[0].un.first sp node[0].un.second-1 nl;
    for(int i=1;i<=n;i++){
        cout<<(good[i]?adj[i].size():1)<<" ";
    }
    cout nl;
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
          string path="../../";
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    int t;
    cin>>t;
    while(t--)
      #endif
        solve();
}
