//problem: https://www.spoj.com/problems/HORRIBLE/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5+10;
ll TREE[4*MAX],LAZY[4*MAX];
void update(int node,int l,int r,int L ,int R,ll w){
    if(r<L||l>R)return;
    if(l>=L&&r<=R){
        ll len = r-l + 1;
        TREE[node]+=w*len;
        LAZY[node]+=w;
        return;
    }
    int mid = (l+r)/2;
    update(node*2 ,l,mid,L,R,w);
    update(node*2 + 1,1 + mid,r,L,R,w);
    TREE[node] = TREE[node*2] + TREE[node*2 + 1] + (r-l + 1)*LAZY[node];
}
ll query(int node,int l,int r,int L,int R,ll carry){
    if(r<L||l>R)return 0;
    if(l>=L&&r<=R){
        ll len = r-l+1;
        return TREE[node]+carry*len;
    }
    int mid = (l+r)/2;
    return query(node*2 ,l,mid,L,R, carry+LAZY[node]) + query(node*2 + 1,1 + mid,r,L,R , carry+LAZY[node]);
}
void solve (){
    memset(TREE,0,sizeof TREE);
    memset(LAZY,0,sizeof LAZY);
    int N,Q;cin>>N>>Q;
    while(Q--){
        int type;cin>>type;
        if(type==0){
                ll a,b,w;cin>>a>>b>>w;
                update( 1 , 1 , N , a , b , w);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<query(1 , 1 , N , l , r , 0)<<"\n";
        }
    }
}
int main (){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
