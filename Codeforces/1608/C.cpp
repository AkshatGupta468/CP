#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
struct node{
    int a,b;
    int index;
    int ans;
};
void solve()
{
    int n;
    cin>>n;
    vector<node> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].a;
        p[i].index=i;
    }
    for(int i=0;i<n;i++){
        cin>>p[i].b;
    }

    sort(p.begin(),p.end(),[](const node &x,const node &y)->bool{
        return x.a>y.a;
    });
    bool flag=false;
    int minb=p[0].b,currminb=p[0].b;
    int maxindex=0;
    for(int i=1;i<n;i++){
            currminb=min(currminb,p[i].b);
        if(p[i].b>minb){
            maxindex=i;
            minb=currminb;
        }
    }
    for(int i=0;i<=maxindex;i++){
        p[i].ans=true;
    }
    sort(p.begin(),p.end(),[](const node &x,const node &y)->bool{
        return x.index<y.index;
    });
    for(int i=0;i<n;i++){
        cout<<p[i].ans;
    }
    cout<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
