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
    int unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 1;
        if(childs[x]>childs[y])swap(x,y);
        head[x]=y;
        childs[y]+=childs[x];
        childs[x]=-1;
        return 0;
    }
};
void solve()
{
    int n,d;
    cin>>n>>d;

    vector<pair<int,int>> a(d);
    for(int i=0;i<d;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    dsu g(n);
    int cnt=1;
    for(int i=0;i<d;i++){
        cnt+=g.unite(a[i].first,a[i].second);
        vector<int> temp=g.childs;
        sort(temp.begin(),temp.end(),greater<int>());
        int ans=0;
        int tempcnt=cnt;
        for(int i=0;i<=n && tempcnt>0;i++){
            if(temp[i]>0){
                ans+=temp[i];
                tempcnt--;
            }
        }
        cout<<ans-1<<nl;
    }
}

int main()
{
    fast_io;
        solve();

}
