#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
int query(){
    int a;
    cin>>a;
    return a;
}
void inv(int &q){
    if(q==2)q=1;
    else q=2;
}
void solve()
{
    int p1=0,p2=1;
    int n,acnt=0,bcnt=0;
    cin>>n;
    int sz=(n%2)?n:(n+1);
    vector<pair<int,int>> p[3];
    int init=1;
    for(int i=1;i<=n;i++){
        int q=init;
        for(int j=1;j<=n;j++){
            p[q].push_back({i,j});
            inv(q);
        }
        inv(init);
    }
    int a;
    int i=1;
    for(;i<=n*n;i++){
        a=query();
        inv(a);
        cout<<a<<" "<<p[a].rbegin()->first<<" "<<p[a].rbegin()->second<<nl;
        p[a].pop_back();
        if(p[a].size()==0){
            i++;
            break;
        }
    }
    int col=a;
    inv(col);
    for(;i<=n*n;i++){
        int q=query();
        cout<<((col==q)?3:col)<<" "<<p[col].rbegin()->first<<" "<<p[col].rbegin()->second<<nl;
        p[col].pop_back();
    }
}

int main()
{
    solve();
}
