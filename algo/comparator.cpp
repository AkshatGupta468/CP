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
    ll sum,index,k;
    vector<ll>stud;
    vector<bool> ans;
};
//always use const with comparators
bool comp(const node &a,const node &b){
    return a.sum*b.k>b.sum*a.k;
}
bool check(vector<ll> &a,node &b,int x){
    return b.sum<b.k*a[x];
}
int binrsearchfun(int l,int r,vector<ll> &a,node &b){
    if(l+1==r)return l;
    int mid=(l+r)/2;
    if(check(a,b,mid)) return binrsearchfun(mid,r,a,b);
    else return binrsearchfun(l,mid,a,b);
}

void solve()
{
    int m,n;
    cin>>n>>m;
    vector<ll> a(n+2);
    a[0]=INT_MAX;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=0;
    sort(a.begin(),a.end(),greater<ll>());
    vector<node> b(m+1);
    b[0].sum=INT_MAX;b[0].k=1;b[0].index=0;
    for(int i=1;i<=m;i++){
        cin>>b[i].k;
        b[i].stud.resize(b[i].k);
        b[i].sum=0;
        b[i].index=i;
        b[i].ans.resize(b[i].k);
        for(int j=0;j<b[i].k;j++){
            cin>>b[i].stud[j];
            b[i].sum+=b[i].stud[j];
        }
    }
    sort(b.begin(),b.end(),comp);

    map<int,vector<int>> pref;
    for(int g=-1;g<=1;g++){
        pref[g].resize(m+1);
        pref[g][0]=0;
        for(int i=1;i<=m;i++){
            pref[g][i]=(a[i+g]*b[i].k>=b[i].sum)+pref[g][i-1];
        }
    }
    node temp;
    for(int i=1;i<=m;i++){
        for(int j=0;j<b[i].stud.size();j++){
            temp.sum=b[i].sum-b[i].stud[j];
            temp.k=b[i].k-1;
            temp.stud.resize(1);
                // debug2(i,j);
            if(comp(temp,b[i])){
            int npos=int(lower_bound(b.begin(),b.end(),temp,comp)-b.begin());
                b[i].ans[j]=(pref[1][i-1]-pref[1][npos-1]==i-npos 
                            && temp.sum<=a[npos]*temp.k 
                            && pref[0][npos-1]==npos-1 
                            && pref[0][m]-pref[0][i]==m-i);
            }
            else {
            int npos=int(upper_bound(b.begin(),b.end(),temp,comp)-b.begin()-1);
                b[i].ans[j]=(pref[-1][npos]-pref[-1][i]==npos-i 
                            && temp.sum<=a[npos]*temp.k 
                            && pref[0][i-1]==i-1
                            && pref[0][m]-pref[0][npos]==m-npos);
            }
        }
    }
    sort(b.begin(),b.end(),[](node &a,node &b)->bool{
        return a.index<b.index;
    });
    for(int i=1;i<=m;i++){
        for(int j=0;j<b[i].ans.size();j++){
            cout<<b[i].ans[j];
        }
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
