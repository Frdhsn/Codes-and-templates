#include<bits/stdc++.h>
using namespace std;
int f(int n,int mx){
    int c=0;
    for(int i=1;i<=100;i++){
        if(mx + (i-1)*(mx+2) <=60){
            c = i;
        }
    }
    return c;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    int n;

    while((cin>>n))
    {
        for(int i=1;i<=60;i++)cout<<"-";
        cout<<"\n";
        string S;
        vector<string>V;
        //V.push_back("haha");
        int len=0;
        for(int i=1;i<=n;i++){
            cin >> S;
            V.push_back(S);
            len = max(len,(int)S.size());
        }
        sort(V.begin(),V.end());
        int col = f(n,len);
        int row = n/col + ((n%col)>0);
        for(int r=1;r<=row;r++){
                string temp="";
                for(int c=1;c<=col;c++){
                    int cell = (row)*(c-1)+ (r-1);
                    //cout<<cell<<",";
                    if( cell < n)temp+=V[cell];
                    if(c<col){
                        int sz = temp.size();
                        int lm = (c)*(2+len);
                        while(temp.size()<lm)temp.push_back(' ');
                    }
                }
                cout<<temp<<"\n";
        }
    }
    return 0;
}

