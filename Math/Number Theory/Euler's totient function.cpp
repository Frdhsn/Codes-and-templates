void func()
{
    for(int i=1;i<MAX;i++)phi[i]=i;
    phi[1]=1; // should be defined
    mark[1]=1;
    for(int i=2;i<MAX;i++){
        if(!mark[i]){
            for(int j=i;j<MAX;j+=i)
            {
                mark[j]=1;
                phi[j]=phi[j]/i *1LL *(i-1);
            }
        }
    }
}
