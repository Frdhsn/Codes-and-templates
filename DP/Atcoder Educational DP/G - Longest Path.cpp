#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5 + 10;
int n,m,Sub[MAX];
vector<int>g[MAX];
bool vis[MAX];
int dfs(int root)
{
    if(vis[root])return Sub[root];
    vis[root]=1;
    int ans=0;
    for(int x:g[root]){
            ans=max(ans,1+ dfs(x));
    }
    return Sub[root]=ans;
}
int main ()
{
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(!vis[i])ans = max(ans,dfs(i));
    cout<<ans;
    return 0;
}
