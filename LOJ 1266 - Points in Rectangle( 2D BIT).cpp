#include<bits/stdc++.h>
using namespace std;
const int MAX=1e3 + 10;
bool vis[MAX][MAX];
int BIT[MAX][MAX];
void update(int x,int y,int val)
{
    while(x<=MAX){
        int y_=y;
        while(y_<=MAX){
            BIT[x][y_]+=val;
            y_+=(y_&-y_);
        }
        x+=(x&-x);
    }
}
int query(int x,int y)
{
    int res=0;
    while(x>=1){
        int y_=y;
        while(y_>=1){
            res+=BIT[x][y_];
            y_-=(y_&-y_);
        }
        x-=(x&-x);
    }
    return res;
}
int main (){
    int t,Q;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case %d:\n",i);
        memset(BIT,0,sizeof BIT);
        memset(vis,0,sizeof vis);
        scanf("%d",&Q);
        while(Q--){
            int type;
            scanf("%d",&type);
            if(type){
                    int x1,x2,y1,y2;
                    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                    x1++,y1++,x2++,y2++;
                    printf("%d\n",query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1));
                    /*printf("(1,1) to (%d,%d) points = %d\n",x2,y2,query(x2,y2));
                    printf("(1,1) to (%d,%d) points = %d\n",x1,y2-1,query(x2,y1-1));
                    printf("(1,1) to (%d,%d) points = %d\n",x1-1,y1,query(x1-1,y2));
                    printf("(1,1) to (%d,%d) points = %d\n",x1-1,y1-1,query(x1-1,y1-1));*/
            }
            else{
                    int x,y;
                    scanf("%d %d",&x,&y);
                    x++,y++;
                    if(vis[x][y]==0){
                        vis[x][y]=1;
                        update(x,y,1);
                    }
            }
        }
    }
    return 0;
}
/*
2
9
0 1 1
0 2 6
1 1 1 6 6
1 2 2 5 5
0 5 5
1 0 0 6 5
0 3 3
0 2 6
1 2 1 10 10
9
0 1 1
0 2 6
1 1 1 6 6
1 2 2 5 5
0 5 5
1 0 0 6 5
0 3 3
0 2 6
1 2 1 10 10
*/
