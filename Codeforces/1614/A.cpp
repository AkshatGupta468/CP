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
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> s(n+2);
    s[0]=string(m+2,'.');
    for(int i=1;i<=n;i++){
        string temp;
        cin>>temp;
        s[i]='.'+temp+'.';
    }
    vector<vector<bool>> vis(n+2,vector<bool> (m+2,false)); 
    for(int i=n;i>0;i--){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='*'){
                int h;
                for(h=1;;h++){
                    if(s[i-h][j+h]!='*'||s[i-h][j-h]!='*')break;
                }
                if(h>k){
                    for(int p=0;p<h;p++){
                        vis[i-p][j-p]=true;
                        vis[i-p][j+p]=true;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='*' && !vis[i][j])return false;
        }
    }
    return true;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"YES\n":"NO\n");

}
