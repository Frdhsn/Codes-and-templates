       int r,k;cin>>k>>r;
       vector<int>a(k);
        for(int i=0;i<k;i++)cin>>a[i];
        vector<bool>v(k);
        //fill(v.end()-r,v.end(),true);
        fill(v.begin(),v.begin()+r,true);
        do{
            vector<int>res;
            for(int i=0;i<k;i++){
                if(v[i])res.push_back(a[i]);
            }
            for(int i=0;i<r;i++){
                if(i)cout<<' ';
                cout<<res[i];
            }
            cout<<'\n';
        }while(prev_permutation(v.begin(),v.end()));
