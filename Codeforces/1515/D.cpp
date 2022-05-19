#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
// void solve()
// {
//     int n,l,r;
//     cin>>n>>l>>r;

//     vector<vector<int>> a(n+1,{0,0});
//     for(int i=0;i<l;i++)
//     {
//         int x;cin>>x;
//         a[x][0]++;
//     }
//     for(int i=0;i<r;i++)
//     {
//         int x;cin>>x;
//         a[x][1]++;
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         if(a[i][0]>a[i][1]){
//             int u=min(l-r,a[i][0]-a[i][1]);
//             ans+=
//         }
//     }
// }
void solve(){
    int n,l,r;
    cin>>n>>l>>r;

    vector<int> a(n+1,0);
    for(int i=0;i<l;i++)
    {
        int x;cin>>x;
        a[x]++;
    }
    for(int j=0;j<r;j++){
        int x;cin>>x;
        a[x]--;
    }
    int ans=0,oddcntl=0,oddcntr=0;
    int left=0,right=0;
    for(int i=1;i<=n;i++){
        ans+=abs(a[i]);
        if(a[i]>0){
            oddcntl+=a[i] & 1;
            left+=abs(a[i]);
        }
        else {
            oddcntr+=a[i] & 1; 
            right+=abs(a[i]);
        }
    }
    if(right>left){
        swap(right,left);
        swap(oddcntl,oddcntr);
    }
    if(oddcntl<=right){
        cout<<ans/2<<nl;
        return;
    }
    cout<<ans/2+(oddcntl-right)/2<<nl;
}
int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
