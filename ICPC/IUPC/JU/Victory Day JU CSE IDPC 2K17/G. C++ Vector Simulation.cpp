/*
  Idea:
  Policy based Data Stuctures & Disjoint Set Union
  pbds & dsu
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define sc(x) scanf("%d",&x)
#define endl "\n"
typedef long long int ll;
typedef pair<ll,ll> pii;
const int MAX = 1e5+10;
template<typename T>
using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;
int N,M,rep[MAX] , Size[MAX];
ordered_set<int>MS[MAX];
int FindRep(int x)
{
    if(rep[x]==x) return x;
    return rep[x] = FindRep(rep[x]);
}
void Union(int u , int v)
{
    int RepU = FindRep(u);
    int RepV = FindRep(v);
    if(RepU==RepV) return;
    if(Size[RepU]>Size[RepV])
    {
        rep[RepV] = RepU;
        Size[RepU]+=Size[RepV];
        for(auto x:MS[RepV])MS[RepU].insert(x);
        MS[RepV].clear();
    }
    else
    {
        rep[RepU] = RepV;
        Size[RepV]+=Size[RepU];
        for(auto x:MS[RepU])MS[RepV].insert(x);
        MS[RepU].clear();
    }
}
void init(int n)
{
    for(int i=0;i<=n;i++)
        rep[i] = i , Size[i] = 1 , MS[i].clear();
}
int query(int x)
{
    int repx = FindRep(x);

    int sz = MS[repx].size();
    if(sz&1){
        int pos = sz/2;
        int res = *MS[repx].find_by_order(pos);
        return 2*res;
    }
    else{
        int pos1 = sz/2 -1;
        int pos2 = sz/2 ;
        int res = *MS[repx].find_by_order(pos1);
        res = res + *MS[repx].find_by_order(pos2);
        return res;
    }
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin >> t;

    for(int tc=1;tc<=t;tc++){
            cout<<"Case "<<tc<<":\n";
            cin >> N >> M;
            init(N);
            for(int i=1;i<=N;i++)MS[i].insert(i);

            while(M--){
                int type;
                cin >> type;
                if(type==1){
                    int x,y;
                    cin>>x>>y;
                    Union(x,y);
                }
                else{
                    int x;cin>>x;
                    cout<<query(x)<<endl;
                }
            }
    }
    return 0;
}
