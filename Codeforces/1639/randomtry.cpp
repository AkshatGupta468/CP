#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';

const int MY_SEED = 42;

void solve()
{
    int n,m,start,basemv;
    mt19937 rng(MY_SEED);
    cin>>n>>m>>start>>basemv;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(1)
    {
        string q;
        cin>>q;
        if(q=="AC"||q=="F"){
            return;
        }
        int d;
        cin>>d;
        vector<int> deg(d),flag(d);
        vector<int> unvis;
        for(int i=0;i<d;i++){
            cin>>neigh[i].first>>neigh[i].second;
            if(neigh[i].second)unvis.push_back(i);
        }
        if(unvis.size()==0){
            int sel = (uniform_int_distribution<int>(1, d)))(rng);
            cout<<sel<<nl;
        }
        else{
            int sel = std::uniform_int_distribution<int>(0,(int)(unvis.size()-1))(rng);
            cout<<unvis[sel]+1<<nl;
        }
    }
}

int main()
{
    // fast_io;
    cout.flush();

    int t;
    cin>>t;
    while(t--)
        solve();

}
