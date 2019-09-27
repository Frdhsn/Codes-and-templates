#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define sc(x) scanf("%d",&x)
#define ff first
#define ss second
const int MAX = 30005;
int n,dist[MAX];
vector<pii>g[MAX];
bool vis[MAX];
int bfs(int source, int type)
{
    for(int i=0;i<MAX;i++)dist[i]=2e9,vis[i]=0;
    queue<int>Q;
    Q.push(source);
    dist[source]=0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto x:g[u]){
            int v = x.ff , w = x.ss;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                Q.push(v);
            }
        }
    }
    int mx=-1 , node = 0;
    for(int i=0;i<n;i++){
        if(dist[i]>mx){
            mx = dist[i];
            node = i;
        }
    }
    if(type)return mx;
    return node;
}
int main ()
{
    int t;sc(t);
    for(int tc = 1; tc<= t ;tc++){
            sc(n);
            for(int i=1;i<=n-1;i++){
                int u,v,w;sc(u);sc(v);sc(w);
                g[u].push_back({v,w});
                g[v].push_back({u,w});
            }
            int farthest_node = bfs( 0 , 0);
            int res = bfs( farthest_node , 1);
            printf("Case %d: %d\n",tc,res);
            for(int i=0;i<n;i++)g[i].clear();
    }
    return 0;
}
