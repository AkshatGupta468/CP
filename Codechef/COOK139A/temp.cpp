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
int query(vector<int> a){
    cout<<"? "<<a.size()<<" ";
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    cout <<endl;
    int q;
    cin>>q;
    return q;
}
    int n;
void dfs(int x,int p,vector<int> &vis,vector<int>  adj[]){
    vis[x]=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i==x||i==p)continue;
        if(query({x,i,p})){
            if(!vis[i])
                dfs(i,p,vis,adj);
            p=i;
        }
    }
    adj[p].push_back(x);
    adj[x].push_back(p);
}
void solve()
{
    cin>>n;
    vector<int> vis(n+1,0);
    vector<int> adj[n+1];
    vis[1]=1;
    for(int i=2;i<=n;i++){
        dfs(i,1,vis,adj);
    }
    cout<<"!"<<endl;
    for(int i=1;i<=n;i++){
        for(auto &j:adj[i]){
            if(j<i)
            cout<< j sp i <<endl;
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    // string path="/mnt/3C401CB3401C75BC/CP/";
    // string path="D:/CP/";
        // freopen((path+"input.txt").c_str(), "r", stdin);
        // freopen((path+"output.txt").c_str(), "w", stdout);
        // freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
