#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5 + 10;
char str[MAX];
int BIT[MAX],N;
void update(int idx,int val)
{
    for(int i=idx;i<=N;i+=(i&-i)){
        BIT[i]+=val;
    }
}
int query(int idx)
{
    int res=0;
    for(int i=idx;i>=1;i-=(i&-i)){
        res+=BIT[i];
    }
    return res;
}
int main ()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=1;i<=t;i++){
        printf("Case %d:\n",i);
        memset(BIT,0,sizeof BIT);
        int Q;
        scanf("%s",str);
        scanf("%d",&Q);
        N = strlen(str);
        while(Q--){
            char ch;
            int l,r,pos;
            getchar();
            scanf("%c",&ch);
            if(ch=='I'){
                    scanf("%d %d",&l,&r);
                    update(l,1);
                    update(r+1,-1);
            }
            else{
                    scanf("%d",&pos);
                    if(query(pos)%2){
                        if(str[pos-1]=='0')printf("1\n");
                        else printf("0\n");
                    }
                    else printf("%c\n",str[pos-1]);
            }
        }
    }
    return 0;
}
