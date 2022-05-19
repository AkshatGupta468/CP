#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
bool solve()
{
    int n,k;
    cin>>n>>k;

    vector<bool> frnd(n+1,false);
    queue<int> qfrnd;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        frnd[x]=true;
        qfrnd.push(x);
    }
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    frnd[1]=true;
    while(!q.empty() && !frnd.empty()){
        int sz=qfrnd.size();
        for(int i=0;i<sz;i++){
            int x=qfrnd.front();
            qfrnd.pop();
            for(auto e:adj[x]){
                if(!frnd[e]){
                    qfrnd.push(e);
                    frnd[e]=true;
                }
            }
        }
        sz=q.size();
        for(int i=0;i<sz;i++){
            int x=q.front();
            q.pop();
            for(auto e:adj[x]){
                if(!frnd[e]){
                    if(adj[e].size()==1){
                        return true;
                    }
                    frnd[e]=true;
                    q.push(e);
                }
            }
        }
    }
    return false;
}

int main()
{
    fast_io;
    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"YES\n":"NO\n");
}
