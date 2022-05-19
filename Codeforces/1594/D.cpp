#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
void solve()
{
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int x,y;string s;
        cin>>x>>y>>s;
        if(s=="imposter"){
            adj[x].push_back({y,1});
            adj[y].push_back({x,1});
        }
        else{
            adj[x].push_back({y,0});
            adj[y].push_back({x,0});
        }
    }
    vector<int> vis(n+1,-1);
    stack<int> s;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]<0){
            vis[i]=1;
        }
        else continue;
        int onecnt=1,cnt=0;
        s.push(i);
        while(!s.empty()){
            int x=s.top();
            s.pop();
            cnt++;
            for(auto e:adj[x]){
                if(vis[e.first]<0){
                    vis[e.first]=vis[x]^e.second;
                    onecnt+=vis[e.first];
                    s.push(e.first);
                }
                else if(vis[e.first]!=vis[x]^e.second) {
                    cout<<"-1\n";
                    return;
                }
            }
        }
        ans+=max(onecnt,cnt-onecnt);
    }
    cout<<ans<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
