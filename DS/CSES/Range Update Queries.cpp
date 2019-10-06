#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=2e5+10;
ll A[MAX],TREE[4*MAX],LAZY[4*MAX];
void build(int node,int l,int r){
    if(l==r){
        TREE[node]=A[l];return;
    }
    int mid = (l+r)/2;
    build(node*2 ,l,mid);
    build(node*2 + 1,1 + mid,r);

}
void update(int node,int l,int r,int L ,int R,ll w){
    if(r<L||l>R)return;
    if(l>=L&&r<=R){
        int len = r-l + 1;
        TREE[node]+=w*len;
        LAZY[node]+=w;
        return;
    }
    int mid = (l+r)/2;
    update(node*2 ,l,mid,L,R,w);
    update(node*2 + 1,1 + mid,r,L,R,w);
}
ll query(int node,int l,int r,int pos,ll carry){
    if(l==r){
        int len = r-l+1;
        return TREE[node]+carry*len;
    }
    int mid = (l+r)/2;
    if(pos<=mid) return query(node*2 ,l,mid,pos, carry+LAZY[node]);
    else         return query(node*2 + 1,1 + mid,r,pos , carry+LAZY[node]);
}
int main (){
    int N,Q;cin>>N>>Q;
    for(int i=1;i<=N;i++)cin>>A[i];
    build( 1 , 1 , N);
    while(Q--){
        int type;cin>>type;
        if(type==1){
                ll a,b,w;cin>>a>>b>>w;
                update( 1 , 1 , N , a , b , w);
        }
        else{
            int pos;cin>>pos;
                cout<<query(1 , 1 , N , pos , 0)<<"\n";
        }
    }
    return 0;
}
