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
    int n;
    cin>>n;
    string s; cin>>s;
    string a(n,' '),b(n,' ');
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(s[i]-'0');
    }
    if(cnt%2)return false;
    bool flag=true;
    int onecnt[2]{};
    for(int i=0;i<n;i++){
        if(s[i]-'0'){
            if(cnt>0){
                a[i]=b[i]='(';
                onecnt[0]++;onecnt[1]++;
            }
            else{
                a[i]=b[i]=')';
                onecnt[0]--;onecnt[1]--;
            }
            cnt-=2;
        }
        else{
            if(flag){
                a[i]='(';onecnt[0]++;
                b[i]=')';onecnt[1]--;
            }
            else{
                b[i]='(';onecnt[1]++;
                a[i]=')';onecnt[0]--;
            }
            flag=!flag;
        }
        if(onecnt[0]<0 || onecnt[1]<0)return false;
    }
    cout<<"YES\n";
    cout<<a<<nl<<b<<nl;
    return true;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"":"NO\n");

}
