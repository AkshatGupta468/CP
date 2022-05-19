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
vector<pair<int,int>> m={{-1,0},{1,0},{0,1},{0,-1}};
void solve()
{
    int n;
    cin>>n;
    vector<tuple<int,int,int>> a(n),ans(n,{0,0,-1});
    for(int i=0;i<n;i++){
        auto &[x,y,pos]=a[i];
        cin>>x>>y;
        pos=i;
    }
    sort(a.begin(),a.end());
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        auto &[x,y,index]=a[i];
        for(auto &d:m){
            tuple<int,int,int> temp={x-d.first,y-d.second,0};
            int pos=lower_bound(a.begin(),a.end(),temp)-a.begin();
            if(pos!=n && get<0>(a[pos])==get<0>(temp) && get<1>(a[pos])==get<1>(temp)){
                adj[i].push_back(pos);
            }
            else ans[i]={x-d.first,y-d.second,index};
        }
    }
    
    queue<int> q;
    for(int i=0;i<n;i++){
        if(adj[i].size()<4){
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++){
            int x=q.front();
            q.pop();
            for(auto &e:adj[x]){
                if(get<2>(ans[e])!=-1)continue;
                ans[e]=ans[x];
                get<2>(ans[e])=get<2>(a[e]);
                q.push(e);
            }
        }
    }
    sort(ans.begin(),ans.end(),[](auto &l,auto &r){
        return get<2>(l) < get<2>(r);
    });
    for(int i=0;i<n;i++){
        auto &[x,y,pos]=ans[i];
        cout<<x sp y nl;
    }
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
        solve();
}
