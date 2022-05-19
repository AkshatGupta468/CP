#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
class dsu{
    public:
    vector<int> head;
    vector<int> childs;
    int n;
    dsu(int n){
        head.resize(n+1);
        childs.resize(n+1);
        this->n=n;
        for(int i=1;i<=n;i++){
            head[i]=i;
            childs[i]=1;
        }
    }
    int find(int x){
        while(head[x]!=head[head[x]]){
            head[x]=head[head[x]];
        }
        return head[x];
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return;
        if(childs[x]>childs[y])swap(x,y);
        head[x]=y;
        childs[y]+=childs[x];
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    // vector<pair<int,int>> adj[n+1];
    vector<pair<int,pair<int,int>>> edges;
    vector<int> ws(m+2);
    vector<int> selected(m+2,0);
    ws[0]=0;
    ws[m+1]=1e8+1;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>ws[i];
        edges.push_back({ws[i],{u,v}});
        // adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }
    vector<int> ans(m+2,0);
    for(int i=0;i<m+2;i++){
        int x=ws[i];

        vector<pair<int,pair<int,pair<int,int>>>> tedge;
        for(auto &e:edges){
            tedge.push_back({abs(e.first-x),{e.first,e.second}});
        }
        sort(tedge.begin(),tedge.end());
        dsu d(n);
        for(auto &e:tedge){
            if(d.find(e.second.second.first)!=d.find(e.second.second.second)){
                ans[i]+=e.first;
                if(e.second.first<=x){
                    selected[i]++;
                }
                d.unite(e.second.second.first,e.second.second.second);
            }
        }
    }
    ll p,k,a,b,c;
    cin>>p>>k>>a>>b>>c;
    ll fans=0;
    ll q;
    for(int i=0;i<p;i++){
        cin>>q;
        int pos=upper_bound(ws.begin(),ws.end(),q)-ws.begin();
        fans^=min(ans[pos]-(ws[pos]-q)*(selected[pos])+(ws[pos]-q)*(n-1-selected[pos]),
                    ans[pos-1]+(q-ws[pos-1])*selected[pos-1]-(q-ws[pos-1])*(n-1-selected[pos-1]));
    }
    for(int i=p;i<k;i++){
        q=(q*a+b)%c;
        int pos=upper_bound(ws.begin(),ws.end(),q)-ws.begin();
        fans^=min(ans[pos]-(ws[pos]-q)*(selected[pos])+(ws[pos]-q)*(n-1-selected[pos]),
                    ans[pos-1]+(q-ws[pos-1])*selected[pos-1]-(q-ws[pos-1])*(n-1-selected[pos-1]));
    }
    cout<<fans<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
