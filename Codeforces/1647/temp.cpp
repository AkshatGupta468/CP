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
#define int long long
bool solve()
{
    int x,d;cin>>x>>d;
    int cnt1=0;
    while (x%d==0)
    {
        x/=d;
        cnt1++;
    }
    int pf=x;
    int cnt=0;
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            x/=i;
            cnt++;
        }
    }
    if(x>1)cnt++;
    if(cnt1==1)return false;
    if(cnt>=2)return true;
    if(cnt1==2)return false;
    int cntd=0;
    x=d;
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            x/=i;
            cntd++;
        }
    }
    if(x>1)cntd++;
    if(cntd==1)return false;
    //expandable 
    if(cnt==0)return true;
    //no.of prime factors=1 expandable  //no.of splits>1
    if(cnt1>3)return true;
    //no.of splits =3 
    x=d*pf;
    for(int i=2;i*i<=x;i++){
        if(x%i!=0)continue;
        if(i%d!=0 || (x/i)%d!=0)return true;
    }
    return false;
}

int32_t main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
    string path="/mnt/3C401CB3401C75BC/CP/";
    // string path="D:/CP/";
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"YES\n":"NO\n");
}
