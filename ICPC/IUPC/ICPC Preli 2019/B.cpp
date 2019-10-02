#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define sc(x) scanf("%d",&x)
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;

const int MAX = 1e5+10;
int N,Q,par[MAX],haha=0;


template<typename T>
using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;

ordered_set<pii>Timelines[MAX];

void init(int x){
    for(int i=1;i<=x;i++)par[i]=i;
}
int find_par(int x){
    if(x==par[x])return x;
    return par[x]=find_par(par[x]);
}
void Union(int u,int v)
{
    int par_u = find_par(u);
    int par_v = find_par(v);
    if(par_u!=par_v){
            int sz_u = Timelines[par_u].size();
            int sz_v = Timelines[par_v].size();
            if(sz_u<sz_v){
                    par[par_u]=par_v;
                    for(auto x:Timelines[par_u])Timelines[par_v].insert(x);
            }
            else{
                    par[par_v]=par_u;
                    for(auto x:Timelines[par_v])Timelines[par_u].insert(x);
            }
    }
}
void Insert(int u,int TL)
{
    int par_u = find_par(u);
    Timelines[par_u].insert({TL,++haha});
}
int Query(int u,int TL)
{
    int par_u = find_par(u);

    int pos = Timelines[par_u].order_of_key({TL+1,0});
    return pos;
}
int main (){

    int t;sc(t);

    for(int tc=1;tc<=t;tc++){
        haha=0;
        sc(N);
        sc(Q);

        init(N);
        printf("Case %d:\n",tc);
        while(Q--){
            int type;sc(type);

            if(type==0){
                    int u,v;sc(u);sc(v);
                    Union(u , v);
            }
            else if(type==1){
                    int u,tl;sc(u);sc(tl);
                    Insert(u,tl);
            }
            else{
                    int u,l,r;sc(u);sc(l);sc(r);

                    int res = Query(u , r) - Query( u , l-1);

                    printf("%d\n" , res);
            }
        }
        for(int i=1;i<=N;i++)Timelines[i].clear();
    }
    return 0;
}
