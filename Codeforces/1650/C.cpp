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
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<int> a[n+1];
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int,int>[2]> vis(n+1,{n+10,0});
    vis[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x=q.pop();
        for(auto &e:adj[x]){
            if(vis[e].second==0)q.push(e);
            if(vis[e].first==vis[x].first+1){
                vis[e].second+=vis[x].first;
            }
            else if(vis[e].first>vis[x].first+1){
                vis[e].first=vis[x].first+1;
                vis[e].second=vis[x].first;
            }
        }
    }
    int ans=vis[t].second;
    for(auto &e:adj[t]){
        if(vis[e].first==vis[t].first){

        }
    }
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
