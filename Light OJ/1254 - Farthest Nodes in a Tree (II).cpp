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
int FarthestNode(int source)
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
    return node;
}
vector<int> bfs(int source)
{
    vector<int>F(n+1 , 2e9);
    memset(vis,0,sizeof vis);
    queue<int>Q;
    Q.push(source);
    F[source]=0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto x:g[u]){
            int v = x.ff , w = x.ss;
            if(F[v]>F[u]+w){
                F[v]=F[u]+w;
                Q.push(v);
            }
        }
    }
    return F;
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
            int farthest_node1 = FarthestNode( 0 );
            int farthest_node2 = FarthestNode( farthest_node1 );
            vector<int> D1 = bfs(farthest_node1);
            vector<int> D2 = bfs(farthest_node2);
            printf("Case %d:\n",tc);
            for(int i=0;i<n;i++)printf("%d\n",max(D1[i],D2[i]));
            for(int i=0;i<n;i++)g[i].clear();
    }
    return 0;
}
