#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
int solve()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<vector<int>> v(k+1);
    queue<int> q;
    for(int i=0;i<n;i++){
        v[a[i]].push_back(i);
        if(!a[i])q.push(i);
    }
    vector<int> ans(n,-1);
    int x=1;
    while(!q.empty()){
        int tpos=q.front();
        while(1){
            // cout<<q.front()<<" ";
            if(q.size()==1)break;
            int len=(q.front()<q.back())?(n+q.front()-q.back()):(q.front()-q.back());
            // debug(len);
            if(len>k) break;
            q.push(q.front());
            q.pop();
            if(q.front()==tpos){
                return 1;
            }
        }
        // debug2(q.front(),x);
        ans[q.front()]=x;x++;
        for(int i=k;i>0;i--){
            if(a[(q.front()-i+n)%n]>=0)a[(q.front()-i+n)%n]--;
            if(a[(q.front()-i+n)%n]==0){
                // cout<<"pushed "<<(q.front()-i+n)%n<<nl;
                q.push((q.front()-i+n)%n);}
        }
        a[q.front()]=-1;
        q.pop();
    }
    for(auto &i:ans){
        if(i<0)return 1;
    }
    display(ans);cout<<nl;
    return 0;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"-1\n":"");
}
