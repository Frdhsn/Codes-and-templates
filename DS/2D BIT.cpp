const int MAX=1e3 + 10;
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
